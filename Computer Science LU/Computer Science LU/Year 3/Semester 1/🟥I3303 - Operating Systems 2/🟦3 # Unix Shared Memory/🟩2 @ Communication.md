_Previous [[🟩1 @ Shared Memory]]_

---

# Communicating with a Child
```c
void main(int argc, char *argv[]) {
	int status;
	pid_t pid;
	
	int ShmID = shmget(IPC_PRIVATE, 4*sizeof(int), IPC_CREAT|0666);
	int *ShmPTR = (int *) shmat(ShmID, NULL, 0);
	
	ShmPTR[0] = atoi(argv[0]); 
	ShmPTR[1] = atoi(argv[1]);
	ShmPTR[2] = atoi(argv[2]); 
	ShmPTR[2] = atoi(argv[3]);
	
	if ((pid = fork()) == 0) {
		Child(ShmPTR);
		exit(0);
	}
	
	wait(&status);
	
	shmdt((void *) ShmPTR); 
	shmctl(ShmID, IPC_RMID, NULL);
	
	exit(0);
}
```

```c
void Child(int SharedMem[]) {
	printf(“%d %d %d %d\n”, SharedMem[0], SharedMem[1], SharedMem[2], SharedMem[3]);
}
```

# Communicating Among Separate Processes :
Define the structure of a shared memory segment as follows:
```c
#define NOT_READY (-1)
#define FILLED (0)
#define TAKEN (1)

struct Memory {
	int status;
	int data[4];
};
```

**THE "SERVER":**
```c
void main(int argc, char *argv[]) {
	// Prepare for a shared memory 
	key_t ShmKEY- ftok("./", 'x');
	int ShmID = shmget(ShmKEY, sizeof(struct Memory), IPC_CREAT | 0666);
	struct Memory *ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
	
	// shared memory not ready
	ShmPTR->status = NOT_READY;
	
	// Filling in data
	for (i = 0; i < 4; i++)
		ShmPTR->data[i] = atoi(argv[i]);
	
	// Wait until data is taken	
	ShmPTR->status = FILLED;
	while (ShmPTR->status != TAKEN)
		sleep(1); /* sleep for 1 second */
	
	// Detach and remove shared memory
	shmdt((void *) ShmPTR);
	shmctl(ShmID, IPC_RMID, NULL);
	
	exit(0);
}
```

**THE "CLIENT": **
```c
void main(void) {
	key_t ShmKEY = ftok("./", 'x');
	int ShmID = shmget(ShmKEY, sizeof(struct Memory), 0666);
	struct Memory *ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
	
	while (ShmPTR->status != FILLED);

	printf(“%d %d %d %d\n”, 
	ShmPTR->data[0], ShmPTR->data[1], 
	ShmPTR->data[2], ShmPTR->data[3]);
	
	ShmPTR->status = TAKEN;
	shmdt((void *) ShmPTR);
	
	exit(0);
}
```

The _“server”_ must run first to prepare a shared memory. _(Try to run the server in one window, and run the client in another a little later.)_

# Things to note
If you did not remove your shared memory segments _(e.g., program crashes before the execution of shmctl())_, they will be in the system forever. This will degrade the system performance.

Use the `ipcs` command to check if you have shared memory segments left in the system.

Use the `ipcrm` command to remove your shared memory segments.

---

_Previous [[🟩1 @ Shared Memory]]_

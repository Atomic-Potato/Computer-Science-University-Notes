_Next [[🟩2 @ Communication]]_

---

Parent and child processes are run in **separate** address spaces. A shared memory segment is a piece of memory that can be allocated and attached to an address space. Thus, processes that have this memory segment attached will have access to it.

In summary to make and manage a shared memory we use the following functions:
- `shmget()` to allocate a shared memory.
- `shmat()` to attach a shared memory to an address space.
- `shmdt()` to detach a shared memory from an address space.
- `shmctl()` to deallocate a shared memory.

Remember to also include the following libraries:
```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
```

# Key
A `key` in unix is used for identifying shared memory segments. Its is of type `key_t`.

**Keys are global entities.** If other processes know your key, they can access your shared memory.

There are 3 ways to create a key:
- Manually
	```c
	key_t someKey = 69420;
	```
- Using `ftok()`
	```c
	key_t key = ftok(char *path, int ID);
	// ID is an integer (e.g., ‘a’)
	```
	_For example:_
	```c
	SomeKey = ftok(“./”, ‘x’);
	```
- Ask the system to provide a private key using `IPC_PRIVATE`.

# Asking for / Creating a Shared Memory
Use `shmget()` to request a shared memory:
```c
shm_id = shmget(
key_t key, /* identity key */
int size, /* memory size */
int flag); /* creation or use */
```
This function returns a shared memory ID.

The flag, for our purpose, is either `0666` _(rw)_ or `IPC_CREAT | 0666`.

_For example:_
```c
// The following creates a shared memory of 
// size: struct Data 
// with a private key :IPC_PRIVATE 

// This is a creation (IPC_CREAT) 
// and permits read and write (0666).
struct Data { int a; double b; char x; };
int ShmID;
ShmID = shmget(IPC_PRIVATE, sizeof(struct Data), IPC_CREAT | 0666);

// The following creates a shared memory 
// with a key based on the current directory:
struct Data { int a; double b; char x;};
int ShmID;
key_t Key;
Key = ftok("./", 'h');
ShmID = shmget(Key, sizeof(struct Data), IPC_CREAT | 0666);
```

When asking for a shared memory:
- the process that creates it uses `IPC_CREAT | 0666` 
- and the process that accesses a created one uses `0666`.

If the return value is negative _(Unix convention)_, the request was unsuccessful, and no shared memory is allocated.

# Attaching a Shared Memory:
Use `shmat()` to attach an existing shared memory to an address space:
```c
shm_ptr = shmat(
int shm_id, /* ID from shmget() */
char *ptr, /* use NULL here */
int flag); /* use 0 here */
```
This function returns a void pointer to the memory. If unsuccessful, it returns a negative integer.

_For example:_
```c
struct Data { int a; double b; char x;};
struct Data *p;

key_t Key = ftok("./", 'h');
int ShmID = shmget(Key, sizeof(struct Data), IPC_CREAT | 0666);

p = (struct Data *) shmat(ShmID, NULL, 0);

if ((int) p < 0) {
	printf("shmat() failed\n"); 
	exit(1);
}

p->a = 1; p->b = 5.0; p->c = ‘.’;
```

## Visual Representation 
![[Pasted image 20230301172607.png|700]]

# Detaching/Removing Shared Memory
To detach a shared memory, use
```c
shmdt(shm_ptr);
// shm_ptr is the pointer returned by shmat().
```

After a shared memory is detached, it is still there. You can re-attach and use it again.

To remove a shared memory, use
```c
shmctl(shm_ID, IPC_RMID, NULL);
// shm_ID is the shared memory ID returned by shmget(). 
```
After a shared memory is removed, it no longer exists.

---
_Next [[🟩2 @ Communication]]_

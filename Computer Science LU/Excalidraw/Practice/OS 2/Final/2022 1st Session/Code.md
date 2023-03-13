# Problem 1:
## 3.a
```c
const int n=3, m=2;
int main(){
	int j=0;
	for(int i=0; i<n && j<m; i++){
		if(!fork()){
			i=0;
			j++;
		}
	}
	
	printf("j=%d\n", j);
	if(j==2){
		execl("toto", "toto", NULL);
	}
	
	int nbOfChildren = 0;
	int nbOfGrandchildren = 0;

	if(j==0){
		int status;
		while(wait(&status) != -1){
			nbOfGrandChildren += WEXITSTATUS(status);
		}
		printf("The main process with PID %d has %d grandchildren \n", getpid(), nbOfGrandChildren);
	}
	else if(j == 1){
		while(wait(&status) != -1){
			nbOfChildren++;
			nbOfGrandChildren += WEXITSTATUS(status);
		}
		printf("Process with PID %d has %d grandchildren", getpid(), nbofGrandChildren);
		exit(nbOfChildren);
	}
	else if(j==2){
		exit(0);
	}
}
```

## 3.b
```c
const int n=3, m=2;
int main(){
	int j=0;
	for(int i=0; i<n && j<m; i++){
		if(!fork()){
			i=0;
			j++;
		}
	}
	
	printf("j=%d\n", j);
	if(j==2){
		execl("toto", "toto", NULL);
	}
	
	int status;
	int nbOfChildren = 0;
	int nbOfGrandchildren = 0;

	if(j==0){
		while(wait(&status) != -1){
			nbOfChildren++;
			nbOfGrandChildren += WEXITSTATUS(status);
		}
		printf("The main process with PID %d has %d grandchildren \n", getpid(), nbOfGrandChildren);
		printf("The main process with PID %d has %d sub processes \n", getpid(), nbOfChildren + nbofGrandChildren);
	}
	else if(j == 1){
		while(wait(&status) != -1){
			nbOfChildren++;
			nbOfGrandChildren += WEXITSTATUS(status);
		}
		printf("Process with PID %d has %d grandchildren", getpid(), nbofGrandChildren);
		exit(nbOfChildren);
	}
	else if(j==2){
		exit(0);
	}
}
```

## 4.a
```c
const int n=3, m=2;
int main(){
	int j=0;
	
	int fd[2];
	pipe(fd);
	
	for(int i=0; i<n && j<m; i++){
		if(!fork()){
			i=0;
			j++;
		}
	}
	
	printf("j=%d\n", j);

	int status;
	int nbOfChildren = 0;
	int nbOfGrandchildren = 0;

	if(j==0){
		while(wait(&status) != -1){
			nbOfChildren++;
			nbOfGrandChildren += WEXITSTATUS(status);
		}
		printf("The main process with PID %d has %d grandchildren \n", getpid(), nbOfGrandChildren);
		printf("The main process with PID %d has %d sub processes \n", getpid(), nbOfChildren + nbofGrandChildren);
		
		while(read())
	}
	else if(j == 1){
		while(wait(&status) != -1){
			nbOfChildren++;
			nbOfGrandChildren += WEXITSTATUS(status);
		}
		printf("Process with PID %d has %d grandchildren", getpid(), nbofGrandChildren);
		exit(nbOfChildren);
	}
	else if(j==2){
		while(wait(&status) != -1){
			nbOfChildren++;
			nbOfGrandChildren += WEXITSTATUS(status);
		}
		printf("Process with PID %d has %d grandchildren", getpid(), nbofGrandChildren);
		dup2(fd[1], 1);
		close(fd[1]);
		execl("toto", "toto", NULL);
		exit(0);
	}
}

int GetGrandChildren(){
	
}
```

# PROBLEM 2
## A
1. The number of entries in a table is = table size / page size = 1024 \* 64 / 64 = 2^10 => 10 bits for the address of the page in the table
   we have 2 levels, so for the offset 32 - 10 \* 2 = 12 which gives us the format 10 : 10 : 12

2. 0010 1210 in binary = 0000 0000 00 | 01 0000 0001 ! 0010 0001 0000
   Physical address: 
   

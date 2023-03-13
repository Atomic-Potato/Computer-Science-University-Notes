_Next [[🟩3@ Inter-Process Communication]]_
_Previous [[🟩1 @ Functions & Reminders]]_

---


Say we want to execute another programing instead of forking the current program _(which creates a new copy of the process)._ A good example of this is the CMD, the commands you give it execute other programs

To do so we use one of these functions:
- `execl` (execute list)
	```c
	execl (char*filename, char* arg0, char* arg1,…)
	//the whole file path should be included in the file name
	```
- `execlp` Same as above but we can omit the file path
	```c
	int execlp (char*filename, char* arg0,char*arg1,…)
	```
- `execv` (execute vector) The parameters can be passed as an array
	```c
	int execv (char*filename, char*argv[])
	```
- `execvp` Same as above but we can omit the file path
	```c
	int execvp (char*filename, char*argv[])
	```

These functions return `1 for failure` and `0 for success` to the parent process.

**==BIG PHAT NOTE:==** When a process calls one of the `exec` functions, this process is terminated and replaced by the process called in the `exec` function



_Example:_
```c
void main(int argc, char* argv[]){
	int pid;
	pid = fork();
	if(!pid){
		execl("/bin/ls","ls","-l","-a", NULL); //filename is a path
		//execlp("ls","ls","-l","-a",NULL); //filename is just a name
		printf("Never executed\n"); // this process is never executed, since the child
									// never returns to this process after exec functions
	}
}
```

**`NOTE:`** I assume the `NULL` at the end of the arguments marks the end of arguments

---

_Next [[🟩3@ Inter-Process Communication]]_
_Previous [[🟩1 @ Functions & Reminders]]_

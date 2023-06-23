_Previous [[🟩2 @ exec Family]]_

---


We learn here the methods of synchronization between processes. These methods are:
- Native: `wait()` & `exit()`
- Unix pipe
- Signals 
- Shared memory segment
- Message passing
- Communication by sockets (processes on different machines)

# Unix Pipes
**REMINDER:**
```
ls | wc
```
Output of `lc` is input of `wc` 

![[Pasted image 20221218123603.png]]

The pipe acts as a FIFO queue buffer (usually its 4KB in size)
By convention one side for writing and the other for reading.

## Creating pipes
Create an integer array of size 2 `int fd[2]`. And make it into a pipe using the function `int pipe(fd)`, which returns `0 for success` and `-1 for fail`. _(fd stands for [[#Descriptors|file descriptor]])_
**This makes `fd[0]` for reading and `fd[1]` for writing**

## I/O with pipes 
In Unix every device is a file that can be accessed through a **[[#Descriptors|descriptor]]**.
This also means that `f[0]` stores the [[#Descriptors|descriptor]] for **reading** and `f[1]` for **writing.**

To write and read to the pipe we use the following functions;
- `write()`
	Removes from the `buffer` characters of the amount `size` and puts them into `fd[1]`
	```c
	int write(fd[1], buffer_address, size);
	// size: num of characters to write
	// buffer: zone from where the data is taken
	```

- `read()`
	Removes data from `fd[0]` of the amount `size` and puts it into the buffer.
	```c
	int read(fd[0], buffer_address, size);
	// size: num of characters to read
	// buffer: zone to place the read data into
	```

These functions both return the number of effective characters _(-1 if it fails)_.

_Example:_
```c
int x[10];
read(fd[0], &x, 10*sizeof(int));
```

### Reading & Writing Pipe Queue
The pipe created is basically a queue, so if you:
- `write()` to the pipe, the buffer is added to the queue
- `read()` from the pipe, the first element of the queue is **removed** into the buffer



## Syncing with pipes
- Reading from an **empty pipe** blocks the process _(stops it from continuing)_ **if there is another process writing from the other side**. Pipe is empty while the writer is still not closed. So the pipe waits until the writer writes something in order to read it.
- Writing in a **full pipe** blocks the process _(stops it from continuing)_ **if there is another process reading from the other side**. Pipe is full while the reader is not closed. Pipe waits until the reader reads something so it gives the pipe space to write.

## Pipe & fork()
If I want to use pipe as a way of communication between parent and child, I need to create a pipe before forking.

**To connect 2 processes using pipes we do the following steps:**
1) Make the pipe using the `pipe()` function
2) `fork()` to create the child for reading from pipe
3)  in the child, close the writing side (if child wants to read)
4)  in the parent, close the reading side (if parent wants to write)

```c
int fd[2], pid;
pipe(fd);                  //create the pipe --> parent has a pipe with fd[1] (write) & fd[0](read)
int p = fopen("toto.txt");
parent --> close(fd[0]);   //if the parent wants to write
child --> close(fd[1]);    //if the child wants to read

// This is one way of communication, If I want 2 ways of communication between parent and child
// I have to create another pipe with opposite closing channels
```

### Descriptors
By default, each created process is associated with three file descriptors:
- `0 for standard input (Keyboard)`
- `1 for standard output (Screen)`
- `2 for standard error (Screen)` (for error messages)

In Pipes, it is associated with 2 descriptors:
- `fd[0] for reading`
- `fd[1] for writing`

[[#File descriptor table|(File descriptor table)]]
![[Pasted image 20221218125033.png | 300]]

#### Descriptors in forking
The pipe is a shared zone between parent & child
However, the child & parent have different descriptors, each pointing to the same location in the file

_Example:_
```c
char reception[100]; //for receiving the message
char *message = "potatoez";
int desc[2];
int nb;

pipe(desc);

if(!fork()){
	close(desc[1]);
	nb = read(desc[0],reception,100);
	printf("the child read %d characters --> %s\n",nb,reception);
	close(desc[0]);
}
else{
	close(desc[0]);
	write(desc[1],message,strlen(message)+1);
	close(desc[1]);
}
```

--- 
# Redirection of I/O
So far we know how to create pipes between parent and child. But how do we send the data in the pipes between them?

## File Descriptor Table
Each process has by default an associated table called `File Descriptor Table`.
File descriptor table contains rows, each containing pointers to the file objects which do all the resource handling.
All file descriptors have, by default, the values:
![[Pasted image 20221218131904.png | 200]]

Each time a file opens, a descriptor is included in the table. _For example:_
```c
int p = open(“tomato.txt”)
// A file descriptor of index (for example) 100 is added to the file descriptor table
```
![[Pasted image 20221218131959.png|150]]

**So when a pipe is created**, 2 descriptors `fd[1] and fd[2]` are added to the file descriptor table
![[Pasted image 20221218132122.png | 200]]
The only communication between the parent and the child is the pipe. So I want to **write to `fd[1]` and read form descriptor `fd[0]`**

## Duplicate functions
Commands like `ls`  and `wc` write to the **1 screen** and read from the **0 keyboard** descriptors, respectively. But we want to redirect them to the pipes descriptors so we can communicate between parent and child. To do so we use the `duplicate functions`

We have 2 duplicate functions:
- `dup()`
	Duplicates the content of a file descriptor, given as a parameter, in the first  free  cell of the file descriptor table
	```c
	int dup(int newfd);
	```
	So to put the `fd[1]` instead of `1` in the `ls`, I have to free `1` using the `Close(int fd)` function. Then we duplicate `fd[1]` and `Close(fd[1])`
- `dup2()`
	The same as `dup()` but automatically does the first close (`dup2(fd[1],1) == close(1);dup(fd[1])`)
	```c
	int dup2(int newfd, int oldfd);
	```

--- 
# Example
How to execute: `ls -l | wc` with code
```c
int fd[2];
pipe(fd);

if(fork()){
	//in parent
	close(fd[0]);
	dup2(fd[1],0);
	close(fd[1]);
	
	execlp("ls","ls","-l",NULL);
}
else{
	//in child
	close(fd[1]);
	dup2(fd[0],0);
	close(fd[0]);
	
	execlp("wc","wc",NULL);
}
```

---

# Named & Unnamed Pipes
When you create a pipe using an array and the pipe function, this is called an `Unnamed Pipe` that gets stored in the RAM.

Permanent pipes, A.K.A. `Named Pipes` or `FIFO Special File`, are files that can be accessed by other processes at any time and it has a capacity of 40KB.
The process opens the FIFO by its name in order to communicate through it. 

## Creation of FIFO
We use the following function
```c
int mkfifo(char *filename, mode-t mode)
// Mode can be: 0666, 0777 (i have no idea whats the difference but youre welcome)
// EDIT: the mode is the read and write things for each user
```
_(Returns `-1 failure`, `0 success`)_

To make a FIFO through the terminal we type the following command
```c
mkfifo canal // creates a named pipe named canal
```

## Using a FIFO
Each process who wants to use a pipe file, it must open it using the `open()` function
```c
int fd = open(char* pipeName, permission);
// permissions can be:
// - O-RDONLY (read only)
// - O-WRONLY (write only)
// - and theres a couple more but i cant bother
```

==**NOTE:**== The FIFO must be opened at both ends simultaneously before you can proceed to do any input or output operations on it.

_For example:_
In FILE1:
```c
char* myfifo = "/tmp/myfifo";
mkfifo(myfifo, 0666);
int fd = open(myfifo, O_WRONLY);
// do your stuff
close(fd);
```
In FILE2:
```c
char* myfifo = "/tmp/myfifo";
int fd = open(myfifo, O_RDONLY);
// do your stuff
close(fd);
```


---
_Previous [[🟩2 @ exec Family]]_

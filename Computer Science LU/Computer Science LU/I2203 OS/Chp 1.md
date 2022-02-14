# Definitions
**`A process`** is a program in execution
**`A program`** is a set of instructions in machine language
==Prog 1.c =>(complile)=>Prog 1.0 => run/execute (becomes a process)==

**`multiprohramming mode: `** execute several programs at the same time
# Multiprogramming mode
- each process has a program, input, output, state, set of registers
- A single processor may be shared among several processes
- Some scheduling algorithm is used to determine when to stop work on process and and service another process 

**Each process has several attributes:**
- process id ==> pid (unique identifier)
- state ==> to describe
- priority 
- general purpose registers (like program counter, IR, accumulator)
- list of opened files
- list of opened devices

**state of the process:**
- when the program is loaded (start the execution) it is placed in `ready` state
- the processes are ready to execute but still waiting the scheduler to choose them 
- when the process is selected by the scheduler then it will become in the `running` state 
- if the process requests input / output it will become in the `block/wait` state

![[The state cycle.jpg | 500]]
If the process slice of time is expired it will go from `running` back to `ready`. Or its because another process with a high priority arrives to the ready queue

### Type of process
We have 2 types
**`CPU bound`** is when the process needs long time in the CPU
**`i/o Bound`** is when the process needs long time for i/o

# Process Creation
A process is stored in memory and divided as follows:
- The stack is where the functions are called and the local variables are stored
- The heap is dynamic, data and variables created that are not defined will be added to the heap
- data is where all the data requested by the app is stored
- code, well its just a place for the code lul
![[How a process is stored in memeory.jpg | 300]]

The memory is divided into 2 sections, one for containing the running processes and one for the OS. The OS section contains a table of process, each row is a `PCB (process control block)` which contains the set of features of a process seen in the process attributes in the Multiprogramming Mode.
![[Memeory sections.jpg | 300]]

**How the process is created**
- in `UNIX (an OS)`, a process (child) is created by another process (parent) by cloning
- on starting `UNIX`, the process with `pid = 1 (init)` is created (parent process above) 

## fork()
`int fork()` located in the `<unistd.h>` library tells the OS to create a child process as a copy of the calling parent process
This function returns:
- `-1` means forking failed (heh forking)
- `random value` returned to the parent process (this is the `pid` of the child)
- `0` returned to the new child process (the child doesnt know its `pid`)

==Note that the new child process will get the same variables and their values==

**If you create multiple forks in a `main()` function, then the amount of process created is `2^n` where `n` is the amount of forks in the main function (assuming there's no failed forks)**

## Process identification 
==These functions are contained in the <unistd.h> library==
- **`int getpid();` **
This function returns the `pid` of the `calling process`.
- **`int getppid();`**
Returns the `pid` of the `parent of the calling process`.

# Process Termination
The process is terminated in one of each of the following scenarios:
- it executes all its instructions (reached return)
- it exits based on a given situation 
- it is killed by another privileged process 

The first 2 are called `normal termination` while the 3rd is called `abnormal termination`

## Normal Termination
`int exit(int status);` found in `#include <sys/wait.h>` <label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> the return is equivalent to exit(0) </span>Note</label>
This function is used to exit out of the entire process when called
- The `status` is a 1 byte number between 0 and 255 used by the process to tell its parent about its exit `status`

==Note: each process running in the system has a PCB==

When the process exits it will stay on the system until its parent gets the info sent by `exit(status)` which means the process row in the PCB will stay and only gets deleted when what happens as said before.

## How the parent gets info about the death of its child
`int wait(int *statusPointer)` found in `#include <sys/wait.h>` 
The `wait` is a blocking statement. Example
```c
//...
pid = wait(&st)
//...
```
When the parent process reaches the wait function it will stop executing the next instructions until it gets the `&status` from `status in exit(status)`
The `wait()` returns the id of the exited child function, it is also used for the **`first exited child`**. 
If we want to wait for all the children we make a loop to do `wait()` as same number of children.
If the parent has no children then wait returns `-1`. So now we can do:
```c
while (wait(&st) != -1);
```

The parameter of the wait function is a pointer to a integer used for receiving the value sent by the child using the function `exit()`.
If we just want to wait for the child and not care about the value returned we give wait the argument `NULL`, `wait(NULL)`. Remember we can still get the get the id of the child while using NULL.

Consider the following:
```
//Parent
int st; 
wait (&st);

//Child
exit(status);
```
the integer st is formed out of 4 bytes, each byte has 8 bits, so we can represent it as cells
|0...0| |0...0| |0...0| |0...0|
When the child exits  the the returned byte is stored in the second cell from right
|0...0| |0...0| |returned| |0...0|
and to fix that we do either one of the following:
- st = st << 8; (<< means shift to the right)
- st = WEXITSTATUS(st);

##### Example question
The question is we need to find the max of an array using 2 processes, when should use from 0 to 4 of the array and the child takes the rest and then the parent should print out the result
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int array[10] = {/*10 values*/}
	
	int max = arr[0];
	int childMax = &arr[5];
	
	for(int i=0; i <= 4; i++)
		if(arr[i] > max)
			max = arr[i];
	
	if(!fork)
	{
		for(int i=5; i <= 9; i++)
			if(arr[i] > *childMax)
				childMax = arr[i];
		exit(childMax);
	}
	esle
	{
		wait(&childMax);
		childMax = choldMax << 8;
		
		if(childMax > max)
			printf("%d", childMax);
		else
			printf("%d", max);
	}
}
```

## Types of dead processes
- **`Zombie process:`**
when a child process exits and the parent doesnt execute the wait statement yet.
- **`Orphan process:`**
when the parent of the process dies before its child. When this happens in `UNIX` systems the main process `init(pid = 1)` becomes the parent.

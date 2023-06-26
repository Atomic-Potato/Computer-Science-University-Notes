# What is OpenMP
OpenMP = “Open Multi-Processing” is a Computing-oriented framework for shared-memory programming.

It distributes threads across CPU cores for parallel speedup
It provides a high-level abstraction layer over low-level multithreading primitives

Its programming model and interface are portable to different compilers and hardware architectures, scalable over an arbitrary number of CPU cores, and flexible in terms of writing compact and expressive source code.

> ==**REMINDER**== **Threads:** streams of instructions that share memory address space

## Basics
The basic philosophy of OpenMP is to augment sequential code by using special comment-like compiler directives – so-called **`pragmas`** – to give hints to the compiler on how the code can be parallelized.

**Pragmas** can be used to exploit compiler-specific functionality. If the compiler does not support the corresponding feature it will simply ignore the pragma.

By just adding appropriate **pragmas**, OpenMP can be easily used to parallelize existing sequential code.

Written software can be compiled and executed with a single or multiple threads. Whether the compiler should include support for the OpenMP API is specified by the compiler flag `-fopenmp`.
**If we compile the code without this flag, we end up with sequential code.**

> Example OpenMP program
> ![[Pasted image 20230626172342.png|400]]

###  Basic OpenMP Functions
- `omp_set_num_threads(nthreads)` - set the number of threads used in a parallel region
- `omp_get _num_threads()` - get the number of threads used in a parallel region
- `omp_get_thread_num()` - get the thread rank in a parallel region

# Fork-Join Task Model
 Spawn tasks in parallel, run each to completion, collect the results.
 ![[Pasted image 20230626172704.png]]

# The various wonders of `pragma`

## Parallel Regions
Specifies which sections of code should be ran in parallel
```cpp
#pragma omp parallel{
	// Code to run in parallel
}
```

> By default, a number of threads equal to the number of cores is created *(i think)*


### Control of variable sharing
#### Private & Shared variables
We can specify if each thread shares the same variable or everyone gets their own copy of the variable. Using `private` & `shared` *(you can tell by the name which is which)*

```cpp
int A = 69;
int B = 420;
#pragma omp parallel private(A) shared(B){
	// get why 69 is private and 420 is shared? ;)
	// i wish someone would see how funny i'am :(
}

// You can even place multiple varibles separated by a comma
#pragma omp parallel private(A, B){
	// damn, thats hot
}
```

> **==NOTE==** the same can be done by just using scopes, variables declared inside the pragma are private, and variables declared before the pragma are shared by default

#### Data Scope
We can change the default sharing of a pragma using `default(shard | none)` *(the bar | means or)* 

- `#pragma omp parallel default(none)` Means no sharing variables by default, each variable must be explicitly shared by adding `shared()` in the pragma
- `#pragma omp parallel default(shared)` all variables are shared by default which is the default behavior if omit it, so as said before, add the `private()` to the pragma to control sharing



#### First & Last private
- `firstprivate` : *Listed variables are initialized according to the value of their original objects prior to entry into the parallel or work-sharing construct.*
  In other words, the changes made to this variable are not reflect to the original.
- `lastprivate` : *The value copied back into the original variable object is obtained from the last (sequentially) iteration or section of the enclosing construct*
  In other words, in a [[parallelized loop]], threads work on **uninitialized** copies, and at the end of the [[parallelized loop]], the thread in charge of the last iteration sets the value of the original variable to that of its own copy. 

## Barrier
Stops the thread from executing and makes it wait for all other threads to reach this point before executing
```cpp
#pragma omp parallel{
	// code
	#pragma omp barrier
	// code
}
```

## Loops
 The OpenMP library will distribute the iterations of the loop across threads
```cpp
#pragmna omp parallel for
for(int i=0; i<69; i++){ }
```

![[Pasted image 20230626182929.png|600]]

### Nested Loops
Outer loop’s index private by default.
**Inner loop’s index must be set private.**

![[Pasted image 20230626183124.png|700]]

### Scheduling Modes
- `schedule (static, [chunk])`  Loop iterations are divided into pieces of size chunk and then statically assigned to threads. If chunk is not specified, the iterations are evenly (if possible) divided contiguously among the threads.
  ![[Pasted image 20230626183615.png]]
- `schedule (dynamic, [chunk])`
   Loop iterations are divided into pieces of size chunk, and dynamically scheduled among the threads; when a thread finishes one chunk, it is dynamically assigned another. The default chunk size is 1.
   ![[Pasted image 20230626183634.png]]
- `schedule (guided, [chunk])` Iterations are dynamically assigned to threads in blocks as threads request them until no blocks remain to be assigned. Similar to `DYNAMIC` except that the block size decreases each time a parcel of work is given to a thread.
	- The size of the initial block is proportional to: `number_of_iterations / number_of_threads`
	- Subsequent blocks are proportional to `number_of_iterations_remaining / number_of_threads`
	- The chunk parameter defines the minimum block size. *The default chunk size is 1.*
	> **==NOTE==** compilers differ in how GUIDED is implemented as shown in the "Guided A" and "Guided B" examples below
		
	![[Pasted image 20230626183831.png]]

![[Pasted image 20230626183921.png]]

## MUTEX
Mutual exclusion conditions (mutexes) protect data races by serializing code.

### Critical
The enclosed code block will be executed by only one thread at a time, and not simultaneously executed by multiple threads. It is often used to protect shared data from race conditions
```cpp
int total = 0;
#pragma omp parallel for
for(int i=0; i<69; i++){
	#pragma omp critical{
		// race free block
		total = total + 1;
	}
}
```
![[Pasted image 20230626184248.png|400]]

### Atomic
the memory update (write, or read-modify-write) in the next instruction will be performed atomically. It does not make the entire statement atomic; only the memory update is atomic. A compiler might use special hardware instructions for better performance than when using critical.
```cpp
int total = 0;
#pragma omp parallel for
for(int i=0; i<69; i++){
	#pragma omp critical{
		// race free block
		total = total + 1;
	}
}
```
![[Pasted image 20230626184248.png|400]]

### Thread-Private & Shared with Atomic
![[Pasted image 20230626184559.png]]

### Shared with reduction
Reduction basically adds *(or based on the specified operation)* the result of all the threads variables into one 
```cpp
int total = 0;
#pragma omp parallel for reduction(+: total)
for(int i=0; i<69; i++){ }
```
![[Pasted image 20230626192249.png|400]]

Other operators:
- ­Arithmetic: `+, *, -, max, min`
- ­Logical: `&&, ||`
- Bitwise AND, OR and XOR: `&, |, ^`

## Single Region
`single` is a clause that must be used in a parallel region; it tells OpenMP that the associated block must be executed by one thread only, albeit not specifying which one.
The other threads will wait at the end of the associated block, at an implicit barrier, unless the single clause is accompanied with a `nowait` clause.
**The `single` clause must not be confused with the master or `critical` clause.**

```cpp
#pragma opm parallel{
	#pragma opm single{
	}
}
```

### Single VS Critical
- `single` specifies that a section of code should be executed by single thread *(not necessarily the master thread)*
- `critical` specifies that code is executed by **one thread at a time.**

## Synchronization
- [[#Critical]]
- [[#Atomic]]
- [[#Barrier]]
- `ordered`: the structured block is executed in the order in which iterations would be executed in a sequential loop.
- `nowait`: specifies that threads completing assigned work can proceed without waiting for all threads in the team to finish. In the absence of this clause, threads encounter a barrier synchronization at the end of the work sharing construct.


## Sections
The section construct is one way to distribute different tasks to different threads.
The sections construct distributes the blocks/tasks between existing threads. The requirement is that each block must be independent of the other blocks. Then each thread executes one block at a time.
**Each block is executed only once by one thread.**

```cpp
#pragma omp parallel{
	#pragma omp section{
	}
	#pragma omp section{
	}
}
```
![[Pasted image 20230626194150.png|300]]

# Common Programming Errors
![[Pasted image 20230626183227.png|400]]
![[Pasted image 20230626183333.png|400]]
![[Pasted image 20230626183347.png|400]]
![[Pasted image 20230626183358.png|400]]

# Some other shit
***DONT REALLY FOCUS MUCH ON THESE, THEY ARE JUST EXTRA***

## omp_get_wtime();
The function `omp_get_wtime()` is a part of the OpenMP library in C++. It is used to obtain the current wall clock time, which can be useful for measuring the execution time of a parallelized code section.

Here's how `omp_get_wtime()` works:

1. The function `omp_get_wtime()` returns a double-precision floating-point value representing the current time in seconds.

2. It provides a way to measure the elapsed time between two points in the code, allowing you to calculate the execution time of a parallel region or a specific code section.

3. The time returned by `omp_get_wtime()` is relative to an arbitrary point in time, typically the start of the program or the system's initialization.

To measure the execution time of a parallelized code section using `omp_get_wtime()`, you can follow these steps:

1. Call `omp_get_wtime()` to record the start time before the parallel section you want to measure.

2. Execute the parallel region or code section that you want to measure.

3. Call `omp_get_wtime()` again to obtain the end time after the parallel section completes.

4. Calculate the difference between the end time and the start time to get the elapsed time.

Here's a code snippet demonstrating the usage of `omp_get_wtime()`:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    double start_time, end_time, elapsed_time;

    start_time = omp_get_wtime();

    // Code section to be parallelized

    end_time = omp_get_wtime();
    elapsed_time = end_time - start_time;

    std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;

    return 0;
}
```

By using `omp_get_wtime()`, you can measure the execution time of parallel sections and compare the performance of different parallel implementations or optimize your parallel code accordingly.

---

## `task` Directive
In OpenMP, the `task` directive is used to explicitly create and schedule tasks for parallel execution. It is a construct that allows you to divide a program into smaller, independent tasks that can be executed concurrently by different threads.

The `task` directive creates a task and assigns it to the current task region for execution. Each task represents a unit of work that can be executed in parallel with other tasks. The tasks are typically scheduled dynamically among the available threads in a team.

Here is the basic syntax of the `task` directive:

```cpp
#pragma omp task [clause-list]
{
    // Task body
}
```

The `task` directive is followed by an optional clause-list, which can include clauses to specify additional behavior and control. Some commonly used clauses with the `task` directive are:

- `if(condition)`: Specifies a condition that determines whether the task should be executed. If the condition evaluates to false, the task is not executed.

- `final(condition)`: Specifies a condition that determines whether the task is a final task. Final tasks are guaranteed to be executed by the encountering thread rather than being assigned to another thread.

- `shared(list)`: Specifies a list of variables that are shared among all tasks. Changes made to these variables inside a task are visible to other tasks.

- `private(list)`: Specifies a list of variables that are private to each task. Each task has its own copy of these variables.

- `firstprivate(list)`: Similar to `private`, but the variables are initialized with the value they had before the task region.

- `default(shared|none)`: Sets the default data-sharing attribute for variables in the task. If not specified, the default is `shared`.

To schedule and execute tasks, you typically enclose the `task` directives within a parallel region. This allows multiple threads to work on the tasks concurrently.

Here's a simple example that demonstrates the usage of the `task` directive:

```cpp
#include <iostream>
#include <omp.h>

void task_function() {
    #pragma omp task
    {
        // Task body
        std::cout << "Executing task" << std::endl;
    }
}

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            // Create tasks
            task_function();
            task_function();
        }
    }

    return 0;
}
```

In this example, the `task_function()` is called twice within a single region, creating two tasks. The tasks are then scheduled and executed concurrently by different threads within the parallel region. The output may show that the tasks are executed in an arbitrary order depending on the scheduling algorithm used.

---

### taskwait
The `taskwait` clause is a clause used with the `task` directive in OpenMP. It provides a synchronization point where a thread waits for the completion of all its child tasks before proceeding further.

When a `taskwait` clause is encountered, the thread that reaches this point will be blocked until all child tasks spawned by that thread have completed their execution. Once all child tasks have finished, the thread continues its execution.

The `taskwait` clause has the following syntax:

```cpp
#pragma omp taskwait [clause-list]
```

The `clause-list` is optional and can include additional clauses to specify behavior and control. Here are some commonly used clauses with the `taskwait` clause:

- `depend(dependence-type: list)`: Specifies dependencies between tasks. It ensures that certain tasks do not start executing until the specified dependencies are satisfied. The `dependence-type` can be `in`, `out`, or `inout`, indicating the type of dependency.

- `default(shared|none)`: Sets the default data-sharing attribute for variables in the taskwait construct. If not specified, the default is `shared`.

Here's an example that demonstrates the usage of the `taskwait` clause:

```cpp
#include <iostream>
#include <omp.h>

void task_function() {
    #pragma omp task
    {
        // Task body
        std::cout << "Executing task" << std::endl;
    }
}

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            // Create tasks
            task_function();
            task_function();
            task_function();

            // Wait for all tasks to complete
            #pragma omp taskwait
        }
    }

    std::cout << "All tasks completed" << std::endl;

    return 0;
}
```

In this example, three tasks are created using the `task_function()` within a single region. After creating the tasks, the `taskwait` clause is used to synchronize the threads and ensure that all tasks are completed before proceeding.

The output will show that the tasks are executed in an arbitrary order depending on the scheduling algorithm used. Once all tasks have finished, the program continues its execution, and the "All tasks completed" message is printed.

The `taskwait` construct is useful when you need to enforce a specific order of execution or when you want to synchronize the tasks' completion before continuing with subsequent computations.

---

### flush

In OpenMP, the `flush` clause is used to ensure that the values of shared variables are visible and consistent across different threads. It provides a synchronization point where the effects of memory operations performed by a thread become visible to other threads.

The `flush` clause has the following syntax:

```cpp
#pragma omp flush [(list)]
```

The optional `(list)` specifies a comma-separated list of variables or memory locations to flush. If no variable is specified, the `flush` clause flushes all shared variables.

When a thread encounters a `flush` clause, it ensures that all memory operations performed by that thread, up to that point, become visible and globally consistent. It forces the thread to write back any locally cached values of shared variables and synchronize with other threads' memory.

The `flush` directive can be used to prevent race conditions and ensure proper memory consistency in parallel code. It is often used in conjunction with other constructs, such as `atomic` or `critical`, to enforce proper synchronization and ordering of memory operations.

Here's an example that demonstrates the usage of the `flush` clause:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int sharedVariable = 0;

    #pragma omp parallel num_threads(2)
    {
        int threadID = omp_get_thread_num();

        if (threadID == 0) {
            // Thread 0 modifies the shared variable
            sharedVariable = 42;

            // Flush the shared variable to make it visible to other threads
            #pragma omp flush(sharedVariable);

            // Perform some computations
            // ...

            // Flush again to ensure other threads see the updated value
            #pragma omp flush(sharedVariable);
        }
        else {
            // Wait for thread 0's modification to become visible
            #pragma omp flush(sharedVariable);

            // Read and use the shared variable
            int value = sharedVariable;

            // Perform some computations using the shared variable
            // ...
        }
    }

    return 0;
}
```

In this example, two threads are created, and the shared variable `sharedVariable` is modified by thread 0. The `flush` clauses are used to ensure that the modification made by thread 0 becomes visible to thread 1 before it reads the shared variable.

The `flush` directive can be used to prevent data races and enforce proper ordering of memory operations when necessary. However, it is important to use the `flush` clause judiciously, as excessive use may impact performance due to frequent synchronization.

---

## Data Scope
### copyin
The `copyin` clause allows the initialization of private variables in parallel regions without explicitly duplicating the initialization code for each thread. It helps ensure that each thread starts with a consistent initial value for the specified variables.
```cpp
#pragma omp copyin(list)
```
### copyprivate
The copyprivate clause provides a mechanism to use a private variable to broadcast a value from the data environment of one implicit task to the data environments of the other implicit tasks that belong to the parallel region. The eﬀect of the copyprivate clause on the speciﬁed list items occurs after the execution of the structured block associated with the associated construct, and before any of the threads in the team have left the barrier at the end of the construct. To avoid data races, concurrent reads or updates of the list item must be synchronized with the update of the list item that occurs as a result of the copyprivate clause if, for example, the nowait clause is used to remove the barrier.
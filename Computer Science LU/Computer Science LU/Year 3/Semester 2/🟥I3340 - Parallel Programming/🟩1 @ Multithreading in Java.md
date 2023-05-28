==Note:== I'm assuming you already know what is a thread, because im sick of writing notes from scratch

The threads are not actually running in parallel, instead they just share the CPU time instead of each thread being sequential
![[Pasted image 20230528095643.png]]

# Process VS Thread
## Process
1. Separate address space
2. Explicit inter-process communication
3. Sync is part of communication
4. The OS calls `fork()` and `wait()`

## Thread
1. Shared address spaces
2. Separate program counter *(PC)* and stacks. Also communication is done through shared memory
3. Sync is done explicitly
4. Library calls, e.g. PThread

## Similarities
- They share CPU and only one thread is active at a time
- Can create children
- If one thread is blocked, another can run

## Differences
- Are not independent of one another
- can access every address in the task
- are designed to assist one another

==Note:== Processes might or might not assist each other, since processes may originate from different users

# Creating Tasks  & Threads
A task is basically a class that implements `Runnable`
```java
public class Task implements Runnable{
	public Task(){}
	
	// Implementing the run method in Runnable
	public void run(){
		// What runs in this task (kinda like the main method)
	}
}
```

Creating a thread out of the task and starting it:
```java
Thread taskThread = new Thread(new TaskClass());
taskThread.start();
```

# The `Thread` Class
![[Pasted image 20230528101003.png]]

- In `join()`, the thread that called this method on another thread, is the one who gets paused. For example:
	```java
	// this is the main thread
	void main(String[] args){
		// ...
		// Making the main thread to wait for taskThread69
		// to finish before continuing execution
		taskThread69.join();
	}
	```
- `isAlive()` returns `true` of the state of the thread is `Ready`, `Blocked` or `Running`. Otherwise returns false if its not started or finished.
- `interrput()` interrupts a thread in the following way:
	- If the thread is `Ready` or `Running`, its interrupted flag is set. *(We can check if a thread is interrupted using `isInterrupt()`)*
	- If the thread is `Blocked`, it is awakened and enters the `Ready` state, and an `InterruptedException` is thrown.
- Some constants for priorities include:
	- `Thread.MIN_PRIORITY` = 0
	- `Thread.NORM_PRIORITY` = 5
	- `Thread.MAX_PRIORITY` = 10

==Note:== To stop a thread, simply set it to `null`
# The States of a Thread
![[Pasted image 20230528101618.png]]

# GUI Event Dispatcher Thread
GUI event handling and painting code executes in a single thread, called the event dispatcher thread.
This ensures that each event handler finishes executing before the next one executes and the painting isn't interrupted by events.

# Thread Pools
Starting a new thread for each task could limit throughput and cause poor performance. A thread pool is ideal to manage the number of tasks executing concurrently.

The `Executor` interface is used for executing tasks in a thread pool and the `ExecutorService` interface for managing and controlling tasks. 
![[Pasted image 20230528103458.png]]

## Creating Executors
To create an `Executor` object, use the static methods in the `Executors` class.

```java
// Creates a thread pool with a fixed number of threads executing concurrently. 
// A thread may be reused to execute another task after its current task is finished. 
ExecutorService newFixedThreadPool(int number of threads){}

// Creates a thread pool that creates new threads as needed, 
// but will reuse previously constructed threads when they are available. 
ExecutorService newCachedThreadPool(){}
```

*Example:*
```java
ExecutorService executor = Executors.newFixedThreadPool(3);

executor.execute(new Task());
executor.execute(new Task());
executor.execute(new Task());

executor.shutdown();
```

# Synchronization
==Note:== You should look into thread safety and race conditions beforehand in this section.

## The `synchronized` Keyword
If placed before a function, it means one function can access this method at a time.
*For example:*
```java
public synchronized void deposit(double amount)
```

**A synchronized method acquires a lock before it executes.** 
In the case of an instance method, the lock is on the object for which the method was invoked. 

**In the case of a static method, the lock is on the class.** 

If one thread invokes a synchronized instance method *(respectively, static method)* on an object, the lock of that object *(respectively, class)* is acquired first, then the method is executed, and finally the lock is released. 
Another thread invoking the same method of that object *(respectively, class)* is blocked until the lock is released. 

## Synchronizing Statements
Same as [[#The `synchronized` Keyword]] but acquires the lock on any block of code.
```java
synchronized (expression){
	// statements
}
// The "expression" must evaluate to an object reference, usually "this"
```

## Synchronization Using Locks Explicitly
![[Pasted image 20230528110715.png]]
A lock may also use the `newCondition()` method to create any number of `Condition` objects, which can be used for thread communications. 

### Fairness Policy
`ReentrantLock` is a concrete implementation of `Lock` for creating mutual exclusive locks. 

You can create a lock with the specified fairness policy.
`True` fairness policies guarantee the longest-wait thread to obtain the lock first.
`False` fairness policies grant a lock to a waiting thread without any access order. 

Programs using fair locks accessed by many threads may have poor overall performance than those using the default setting. But have smaller variances in times to obtain locks and guarantee lack of starvation. 

*Example:*
```java
private static Lock lock = new ReentrantLock();
// ...
lock.lock();
// ...
if (x == true)
	lock.unlock();
```

# Cooperation Among Threads
The conditions can be used to facilitate communications among threads. 
![[Pasted image 20230528111455.png]]

Conditions are objects created by invoking the `newCondition()` method on a `Lock` object. Once a condition is created, you can use its `await()`, `signal()`, and `signalAll()`  methods for thread communications. 

The `await()` method causes the current thread to wait until the condition is signaled.
**The lock associated with this condition is atomically released** and the current thread becomes disabled for thread scheduling purposes.
Before this method can return the current thread must re-acquire the lock associated with this condition.


# Semaphores
Semaphores can be used to **restrict the number of threads that access a shared resource.** 

Before accessing the resource, a thread must acquire a permit from the semaphore. After finishing with the resource, the thread must return the permit back to the semaphore. 
![[Pasted image 20230528112217.png]]

## Creating Semaphores
To create a semaphore, you have to specify the number of permits with an optional fairness policy.
![[Pasted image 20230528112353.png]]

# More topics to look into
- Deadlocks
- Thread safety
- Race conditions
- `getTime()`
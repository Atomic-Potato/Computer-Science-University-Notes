# Intro
We have 2 types of Multi-programming:
- `wihout pre-emption:` The process executes till completion except when it makes I/O request.
- `with pre-emption:` The scheduler may stop one executing process and give the CPU to another process and the first is not finishing its job. i.e. the running process may leave the CPU several times and returns to ready queue based on the criteria used by the dispatcher.

# Context Switching 
When the CPU removes a process that havent finished its job, the process context is stored in the PCB so that it will be used again to continue the process from it left off upon entering the CPU.

# Degree of Multi-programming
It's the number of processes in the ready states at time `t`.

# Process state transition diagram
![[Process State transition diagram.jpg | 700]]
- `1` The scheduler / dispatcher chooses the process to execute
- `2` process time expires / depends on priority
- `3` process requests I/O data
- `4` I/O ready
- `5` new process is created
- `6` process ends

- `7 & 8` if the ready queue is filled up, then when new processes are in the ready state arrive they are put in the suspended ready queue stored in the secondary memory
- `9 & 10` same as above
- `11` the suspended wait receives its requested input and gets sent to the process in the suspended ready queue or the Main Memory ready queue.

**`The process of switching between queues is called swapping, and the dedicated place in the hard disk is called the swapping area`**

# Various timer related to processes
`Arrival Time (AT):` The current time the process arrives to the ready queue.

`Burst Time (BT):` The amount of CPU time required by the process to finish the execution.

`Input/Output Time:` The amount of time the process is blocked (in the waiting queue)

`Completion Time (CT):` The time the process ends in

`Turn arround time (TAT):` The amount of time the process takes between its arrival and its completion.

`Waiting time (WT):` the time spent in the ready queue.

`Response Time (RT):` the first instant the process starts execution 

**TAT = CT - AT = BT + WT + I/OT**
**RT = Scheduling time - AT**

# CPU Scheduling
## Scheduling criteria:
- `CPU utilization`: ideally the CPU would be busy 100% of time (in reality between 40 and 90%)
	- **(1 - idle/total) x 100**
		- idle = total of time the cpu wasnt working
		- total = theTimeWhenTheLastProcessFinishes
- `Throughput`: The number of processes completed by unit of time
	- **Throughput = numOfProcesses/theTimeWhenTheLastProcessFinishes**
- `Turnarround Time:`  explained
- `Waiting time:` explained (load average = average WT)
- `Response time:`  The time taken in an intermediate program from the issuance of a command to the commence of a response to that command

**`Criteria:`**
- Maximize CPU utilization
- Maximize throughput
- Minimize TAT
- Minimize WT
- Minimize RT

**`Scheduling / Dispatcher:`**
A short term scheduler / dispatcher manages the scheduling.
(Where) It functions from the ready state till the running states.
(When) when a process moves from:
- run -> terminate
- run -> wait
- run -> ready
- new -> ready
- wait -> ready

![[Pasted image 20220409154355.png | 500]]

# Scheduling Algorithms
## FCFS: First Come First Served
**Criteria**: arrival time `(The criteria means which processes to run first)`
**Mode**: Non-preemptive `(Because of this, the response time is the waiting time)`
The scheduler gives to the CPU the processes in respect with their arrival time to ready queue

Example:
![[Example on FCFS.jpg | 400]]
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> In case we have several processes with the same AT, we choose the processes with the lower pID</span>Note</label>
![[Gantt diagram.jpg | 400]]

The problem with this algorithm is if a process with long BT and the next processes in the queue have low BT, this first process will make the average WT greater than first executing the processes with low BT.

## SJF: Shortest Job First
Gives the priority to the process with the least BT
- Criteria: Burst Time (CPU Time)
- mode: non-preemptive

At instant `t`, the algorithm chooses from the ready queue, the process with minimum BT
![[Example on SJF.jpg | 600]]
Theres still a problem with this algorithm is that if the first process arrived to the the ready queue with a long CPU time then all of the next short ones will have a long wait time 

**`Efficiency =` (1 - throughput) x 100  = % time the CPU is used**

## `SJF with prediction`
SJF is not used because we can't know ahead of time the BT of the process.
It is used for research comparison.

This is why we have SJF with prediction of BT
We have 2 types or prediction:
- `Static:`
	- process size
	- process type
- `Dynamic:`
	- simple averaging
	- exponential averaging / aging

### `Static prediciton techniques`
- Process size: gives processes priority depending on the process size (like in KB), but this is inaccurate since some processes are small but do large amount of calculations
- Process type: by dividing process into 2 types, OS and USV, and dividing USV into 3 types, interactive | foreground | background. But still is not efficient.

### `Dynamic Prediction techniques`
- **Simple averaging:**
In the simple averaging method, the average burst time is taken of all the processes that have executed till now.
There is a total of **n** processes **P(1), P(2), ... , P(n)** and burst time of each process **P(i)** as **t(i)**, where **i = 1,2,3, ..., n**.
The predicted burst time for process **P(n+1)** is **T(n+1)** given by the following, **`T(n+1) = (1/n) ∑ t(i)`**

- **Exponential averaging:**
Let, **t(n)** be the actual burst time of **nth** process. **T(n)** be the predicted burst time for **nth** process then the CPU burst time for the next process **T(n+1)** given by the following, **`T(n+1) = α. t(n) + (1-α) . T(n)`**
Where, **α** is the smoothening factor, where **0<= α <=1**. It controls and manages the relative weight of the recent and past history of processes in our prediction,
	-   If **α = 0**, **Τ(n+1) = Τ(n)**, it represents there is no change in the value of initial predicted burst time.
	-   If **α = 1**, **Τ(n+1) = t(n)**, it represents predicted burst-time of the new process will always change according to actual burst-time of the **nth** process.
	-   If **α = 1/2**, it represents the current and past history of equally-weighted processes.

### Relation between quantum time, context switching and response time
![[relation between quantum time, context switching and response time.jpg | 300]]
## Round Robin Algorithm
This is the most popular algorithm. It is similar FCFS, we start executing the processes that arrive in turn but we used `Quantum Time (qt)`.

- **Mode**: Preemptive
- **Criteria**: AT and QT

How it works:
![[Round Robin Algorithm.jpg | 500]]

The advantage of this algorithm is that no process starves / takes too long to executes
The disadvantage is if theres a small quantum time then the number of context switching will become quite high / overloaded. And if we had a large quantum time, then we will have starvation

## Priority Algorithm
A process can have either one of two types of priority:
`Static`: doesnt change throughout the execution
`Dynamic:` changes at regular intervals of time

The second type of types are the following types: (wtf...)
`non-preemptive:` the process with the highest priority is running until completion
`preemptive:` the process with highest priority is running until  completion except if another process with higher priority arrives 

Non preemptive example (Remember, no context switching !!)
![[Pasted image 20220104183335.png | 500]]

Preemptive example
![[Pasted image 20220104184352.png | 600]]
Another example
![[Pasted image 20220120181015.png | 600]]
**`CPU efficiency`** **= 1 - idleTime/TotalTime x 100** 

## Shortest Job First (preemptive) Algorithm
The first process that arrives executes for 1 unit, if a new process arrives with lower BT we execute it if not we continue with P1 again for one unit. If we execute P2 we also doing it for 1 unity each till a new process with lower BT arrives and so on. 
Example:
![[Pasted image 20220105160136.png |  600]]

## SJF with I/O (the one above)
Its the same as above but at the moment a process finishes its first BT, we add this the I/O time to this moment and that will be the new AT for the process, and we continue normally from there for the next BT

![[Pasted image 20220105161546.png | 600]]

## Multi-Level queue scheduling (MLQ)
![[Pasted image 20220120184654.png | 500]]
This algorithm creates multiple queues and each one has its algorithm. The queues on the top have higher priority from the one below them means they should always execute first. Each process enters a queue and cant switch between queues.

## Multi-level feedback scheduling algorithm 
This algorithm avoids starvation and at the same time preference will be given to higher priority processes
Processes may be moved from one queue to another for several reasons:
- process characteristics change from CPU intensive to I/O intensive
- if the age is incorporated the a process that waits for a long time may change its queue and its priority increase
![[Pasted image 20220125184250.png | 400]]

MLFQ Rules:
- if priority `P1 > P2` then` P1 runs`
- if `P1 = P2` then the algorithm runs in a `round robin` fashion 
- when a process arrives it is placed at the `highest priority queue`
- when a process `uses up its time allotment` at a given level (regardless of how many times it has given the CPU), i`ts priority  is reduced` (i.e. moves down one queue)
	- if a process uses up an entire time slice while running, `its priority is reduced`
	- if a process gives up the CPU before the time slice is up, then it `stays in the same queue / priority`
- After some period "t" of time, `move all the processes to the topmost queue.` 

Example
![[Pasted image 20220125185309.png | 600]]

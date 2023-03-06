A transaction is at least one of the following actions on the database:
- `write`
- `modify`
- `delete`

Multiple transactions can execute in parallel.
![[Pasted image 20230306180246.png|400]]

# Issues
There are 2 main issues to deal with:
- Concurrent execution of multiple transactions
- Failures of various kinds, such as hardware failures and system crashes _(Specific Recovery Protocol is needed!)_

# The properties of a database system
To preserve integrity of data, the database system must ensure:
- `Atomicity:` Either all operations of the transaction are properly reflected in the database or none are. 
  _A transaction might be committed after completing all its actions, or it could be aborted by the DBMS after executing some actions._
- `Consistency:` Execution of a transaction in isolation preserves the consistency of the database.
- `Isolation:` Although multiple transactions may execute concurrently, each transaction must be unaware of other concurrently executing transactions.
  Intermediate transaction results must be hidden from other concurrently executed transactions.
  _That is, for every pair of transactions T1 and T2, it appears to T1 that either:_
	- _T2, finished execution before T1 started,_
	- _or T2 started execution after T1 finished._
- `Durability:` After a transaction completes successfully, the changes it has made to the database persist, even if there are system failures.

# Transaction States
![[Pasted image 20230306181509.png|700]]

- `Active:` the initial state; the transaction stays in this state while it is executing
- `Partially committed:` after the final statement has been executed.
- `Failed:` after the discovery that normal execution can no longer proceed.
- `Aborted:` after the transaction has been rolled back and the database restored to its state prior to the start of the transaction. 
  _Two options after it has been aborted:_
	- _restart the transaction – only if no internal logical error_
	- _kill the transaction_
- `Committed:` after successful completion.

# Transaction in SQL
A transaction must be explicitly marked by surrounding it with:
```sql
begin transaction
	/*Transaction*/
commit transaction
```

We can also use the `rollback` keyword to well... rollback our changes, duh..
```sql
begin transaction
	/*Transaction*/
if ?
	then rollback
else
	commit transaction
```

**==NOTE:==** If a transaction begins and another process tries to access the same data, it is put on hold until the first process to either `commit` or `rollback`

_For example:_
```sql
begin trans
	update BankingAccounts
	set balance= balance– 100
	where accid = “100022”
	
	update BankingAccounts
	set balance= balance+100
	where accid = “100010”

if ( select balance 
	from BankingAccounts 
	where accid = “100022”) > 0
	commit trans
else
	rollback trans
```

# Concurrency
Concurrency is basically managing transactions from different processes so that they wont have to wait too long to be execute but rather to be executed in parallel.

## Scheduling
**`Schedule:` sequences that indicate the chronological order in which instructions of concurrent transactions are executed**

Consider two transactions T1 and T2 enclosed
There is no guarantee that T1 will execute before T2 or vice-versa.
These two transactions running serially in some order: T1 followed by T2 _(scheme 1)_ or T2 followed by T1 _(scheme 2)._
![[Pasted image 20230306192636.png|200]]

A schedule _(i.e. scheme 1 and 2)_ of concurrent transactions is a particular interleaving of their read or write operations on data items.

Since we allow multiple transactions to execute concurrently by interleaving their operations, we need a way to maintain the properties of the transactions
![[Pasted image 20230306192916.png|400]]

## Serializability
**A schedule is serial if, for every transaction T in the schedule, all operations are executed consecutively _(are not interleaved)_ in the schedule**

A serializable schedule can let us run transactions in parallel_, or thats what i think..._

### Conflict Serializability
Instructions i1 and i2 of transactions T1 and T2 respectively, conflict if and only if there exists some data item Q accessed by both li and lj, and at least one of these instructions wrote Q.
![[Pasted image 20230306193538.png|300]]
If i1 and i2 are consecutive in a schedule and they do not conflict, their results would remain the same even if they had been interchanged in the schedule.

>`Conflict equivalent:` if a schedule S1 can be transformed into a schedule S2 by a series of swaps of non-conflicting instructions, we say that S1 and S2 are conflict equivalent.
>`Conflict serializable:` We say that a schedule S is conflict serializable if it is conflict equivalent to a serial schedule

_For example:_
```
The enclosed schedule S1 is not conflict serializable.
Since we are unable to swap instructions in the above schedule to obtain either the serial schedule <T1, T2>, or the serial schedule <T2, T1>.
```
![[Pasted image 20230306194029.png|125]]

#### _Example_
Schedule 2 below can be transformed into Schedule 1, a serial schedule where T2 follows T1, by series of swaps of non-conflicting instructions. Therefore Schedule 2 is conflict serializable.
![[Pasted image 20230306194228.png|800]]

# Recoverability
Take the following example:
![[Pasted image 20230306194424.png|200]]

Say T1 wants to rollback instead of committing, then the read data of T2 by R(A) is incorrect.
To fix this issue we just place the commit at the end, and we traceback the queries of each table and we rollback the way we executed but in reverse.
![[Pasted image 20230306194633.png|300]]

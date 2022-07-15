# `list` — Terribly Sloooow Queues
Not a good idea
```python
q = []
q.append('eat')
q.append('sleep')
q.append('code')

# Careful: This is slow!
q.pop(0) #eat
```
# `collections.deque` – Fast & Robust Queues
The deque class implements a double-ended queue that supports adding and removing elements from either end. They can serve both as queues and as stacks.
Deques are implemented as doubly linked lists.
```python
from collections import deque

q = deque()
q.append('eat')
q.append('sleep')
q.append('code')

q.popleft() #eat
#...
```

# `queue.Queue` – Locking Semantics for Parallel Computing
Same as the stacks one
```python
from queue import Queue

q = Queue()
q.put('eat')
q.put('sleep')
q.put('code')

q.get() #eat
#...
```

# `multiprocessing.Queue` – Shared Job Queues
This is a shared job queue implementation that allows queued items to be processed in parallel by multiple concurrent workers.
This type of queue can store and transfer any pickle-able object across process boundaries.

```python
from multiprocessing import Queue

q = Queue()
q.put('eat')
q.put('sleep')
q.put('code')

q.get() #eat
#...
```


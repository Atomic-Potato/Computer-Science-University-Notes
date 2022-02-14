# list – Maintaining a Manually Sorted Queue
You can use a sorted list to quickly identify and delete the smallest or largest element. The downside is that inserting new elements into a list is a slow operation.
Sorted lists are only suitable as priority queues when there will be few insertions.

```python
q = []
q.append((2, 'code'))
q.append((1, 'eat'))
q.append((3, 'sleep'))

# NOTE: re-sort every time
# a new element is inserted, or use
# bisect.insort().

q.sort(reverse=True)
while q:
	next_item = q.pop()
	print(next_item)
```

# `heapq` – List-Based Binary Heaps
This is a binary heap implementation usually backed by a plain list, and it supports insertion and extraction of the smallest element in fast time.

```python
import heapq

q = []
heapq.heappush(q, (2, 'code'))
heapq.heappush(q, (1, 'eat'))
heapq.heappush(q, (3, 'sleep'))

while q:
	next_item = heapq.heappop(q)
	print(next_item)
```

# `queue.PriorityQueue` – Beautiful Priority Queues
This priority queue implementation uses heapq internally.
The difference is that `PriorityQueue` is synchronized and provides locking semantics to support multiple concurrent producers and consumers.

```python
from queue import PriorityQueue

q = PriorityQueue()
q.put((2, 'code'))
q.put((1, 'eat'))
q.put((3, 'sleep'))

while not q.empty():
	next_item = q.get()
	print(next_item)
```
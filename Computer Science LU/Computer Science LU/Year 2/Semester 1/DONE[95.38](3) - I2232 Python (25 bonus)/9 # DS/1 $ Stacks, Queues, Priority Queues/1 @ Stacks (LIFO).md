# `list` - Simple, Built-in Stacks
using lists for making stacks is usually not recommended and takes performance, so avoid this pattern
```python
L =[]
L.append('x')
L.append('b')
L.append('y')
L.pop()
L.pop()
L.pop()
```

# `collections.deque` – Fast & Robust Stacks
The `deque` class implements double-ended queues which can be used as well like a stack
```python
from collections import deque

s = deque()
s.append('eat')
s.append('sleep')
s.append('code')
```

# `queue.LifoQueue` – Locking Semantics for Parallel Computing
useful for parallel computing 
```python
from queue import LifoQueue

s = LifoQueue()
s.put('eat')
s.put('sleep')
s.put('code')

s.get() #code
#....
```

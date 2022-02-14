# Breadth-First Search [BFS]
```
Notation

#Queues
- FIFO: first in first out
- LILO: Last in last out
```

### Algorithm
- Create  a queue 
- visited vertex list (add root to the queue)
- Loop over the queue
	- if theres no first element => finish
	- get front vertex
	- treat vertex
	- Enqueue the neighbors if they are not visited 

### Theorems
- A spanning tree `T` of `G` has `rad(T) >= rad(G)`
If the graph is `connected rad(T) = rad(G)` 

- `radius-preserving spanning tree (BPST)` means rad(T) = rad(G)
`diameter-preserving spanning tree (DPST)`means diam(T) = diam(G)
==DPST =>BPST==

# Depth-First Search [DFS]
```
Notation

# Stacks
LIFO: last in first out
FILO: first in last out 
```

### Types of edges in DFS
- **Tree edge :** encounter new vertex
- **Back edge:** from descendant to ancestor (when visiting a new vertex but it has and edge with one of its ancestors)
- **Forward edge:** from ancestor to descendant (same as above but when backtracking up the tree)
- **Cross edge:** between trees and subtrees
- **Bidirectional edge:** if from visited vertex to a visited vertex

### Algorithm
- create a stack
- push the root and mark it as visited
- loop over the stack 
top => pop => loop over its neighbors => push the vertex if not visited

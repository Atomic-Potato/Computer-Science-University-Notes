# Definitions
`directed graph, digraph` is a graph with its edges can only be traversed in one way
![[Pasted image 20220203121443.png | 200]]
`simple digraph:` a digraph that has no self-loops or parallel edges
`Arcs:` are the vertices
`adjacent to:` x is adjacent to y
`adjacent from:` y is adjacent from x
`symmetric arcs:` is when we have x->y and y->x

 `underlying (multi-)graph:` 
![[Pasted image 20220203121709.png | 300]]
	- `outdegree od(v):` number of edges going out of x
	- `indegree id(v):` number of edges coming into x

 `transmitter:` arc with id(v) = 0
 `receiver:` arc with od(v) = 0

`weakly connected:` when we have a path from y to x, but not the opposite
`strongly connected:` when have a path from y to x and vice versa
`unilateral graph:` is when we have only one type of path from x to y or from y to x but not both
![[Pasted image 20220203122945.png  | 200]]![[Pasted image 20220203123016.png | 250]] ![[Pasted image 20220203123049.png | 250]]

`orienting:` is changing the direction of an edge

 `acyclic:` is a graph with no cycle
 ![[Pasted image 20220203124608.png | 200]]

`pratial order set:` the operator `~` is reflexive `a~a`, antisymmetric `a~b and b~a => a=b` and transitive

`unilateral:` **f for every pair x, y of its ver- tices there exists a directed path from x to y**, or a directed path from y to x, or both.

# Theorems:
 - **Theo 1:**
 ![[Pasted image 20220203122220.png | 600]]
 - **Theo 2:**
 ![[Pasted image 20220203123225.png | 600]]
- **Theo 2**
![[Pasted image 20220203124946.png | 600]]


# Algorithms
 ![[Pasted image 20220203123936.png | 600]]

# Definitions
`k-deficient` $deg_G(v) - deg_T(v) = k$
`deficiency` = k
`degree-preserving` k = 0

`minimal-connecter problem` (or minimal-cost problem)
which is finding the tree with the minimum sum of weights of edges
`minimum spanning tree` it is the tree found in the above problem with the minimum cost


# Theorems
- in a connected graph, n = vertecies and q = edges
$$\sum deficiency = 2(q-n+1)$$
- The number of leaves in a tree is equal to:
![[num of leaves.jpeg | 700]]
# Algorithms
- `greedy` aims to find the tree with the lowest cost

- `Kruskal's Algorithm` finds the first tree that has no loops
	- Sort the edges of the graph in ascending order depending on their weight
	- create an empty vector to contain the edges of the tree
	- start checking each edge, if adding it to the tree forms a loop skip it, if not add it
	- stop only when you have a number of edges equal to the number of vertices - 1 or you ran out of edges
![[Pasted image 20220104150309.png | 400]]

We will create this algorithm containing multiple sets
![[Pasted image 20220104150815.png | 250]]
With the help of `UnionFind Data Structure`

##### UnionFind Data Structure
- `UnionFind UF(V):` Creates V disjoint sets
- `int findSet(int i):` finds and returns the set of i
- `bool isSameSet(int i, int j):` checks whether i and j are in the same set
- `void unionSet(int i, int j):` merges i's and j's sets
- `int numDisjointSets():` returns the number of disjoint sets
- `int sizeOfSet(int i):` returns the size of the set where i resides

- **`Prim's Algorithm`** (its the same as **kruskal's** but we add in a starting root)
	- Select a vertex v, and add it to a list of vertices
	- push the edges of v to priority queue
	- pick the lowest weight of edge emanating from v (front vertex in the queue) (store the edge in an edges list)
	- push the edges of the new vertex to the priority queue
	- repeat until edges = vertecies - 1
==Note that we used a priority queue==
![[Pasted image 20220104152633.png | 650]]
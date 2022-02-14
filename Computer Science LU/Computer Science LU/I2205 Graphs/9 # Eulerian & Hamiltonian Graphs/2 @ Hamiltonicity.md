# Definitions
`traceable:` is a spanning path

`Hamiltonian` same as eulerian but with vertices 
`Hamiltonian cycle`  same as eulerian cycle but with vertices

`semi-Hamilton` has a Hamiltonian path but no Hamiltonian cycle

`closure C(G)` every non adjacent pair of vertices such that deg(v)+deg(u) >= order G, then we  add an edge between those two, we repeat the process until we cant anymore
![[Pasted image 20220129193259.png | 400]]

`Hamiltionian connected` if for any xy vertices in Ham graph, we can find a Ham Path 

`Hamilton Laceable:` if it G **has a Hamiltonian path for all pairs of vertices** and , where belongs to one set of the bipartition.

# Properties
- Props of Hamiltonian graphs
	- G must be connected
	- No vertex can have degree less than 2 
	- G cannot contain a cut vertex
	- a theres a vertex of degree 2, then both of these edges must be included in the cycle
	- if a vertex has more than 2 edges than we cannot use more than 2 edges in the cycle

# Theorem
- **Dirac** if G has an order >= 3, and the degree of each vertex is >= order/2, then the graph is hamiltonian
- **Ore** if G has an order >= 3, then if for each non adjacent pair of vertices, the deg(v)+deg(u) >= order then G is Hamiltonian
- **Bondy Chvatal:** G is hamiltonian <=> C(G) is hamiltonian
- **Chvatal:** $d_1 <= ... <= d_n$ if $i<\frac{n}{2}$=> $d_i> i$ or $d_{n-i} >= n-i$ => G is Hamiltonian (d is the degree for vertex i)
In other words, if half of the degrees are greater than n/2 then the graph is hamiltonian
- **Chvatal-Erdos 1972:** if $\kappa(G)=> \alpha(G)$ => G has a Hamiltonian cycle
- **Theo 1:** Every even mesh is Ham
- **Theo 2:** Every hypercube is Hamilton laceable
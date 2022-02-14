# Definitions
`Multigraph:` Its a graph were 2 vertices can have multiple edges
`weighted graph / network` is when we convert the number of edges connecting 2 vertices into a weight

`Eulerian graph:`  is traversing all the edges of a graph once starting from one vertex and returning to it
`Eulerian circuit:` if we find a circuit in an Eulerian graph

`Eulerian trail:` if theres only `2` vertices with odd degree then we can have Eulerian trail instead of an eulerian circuit
`semi-Eulerian:` a graph is semi-Eu if it has an Eu trail

`traversable:` a graph is traversable if its an Eu or a semi-Eu graph

# Theorems 
- **Theo 1:** 
	A graph G is `Eulerian` iff
	- G is Connected 
	- every vertex has an even degree   

- **Theo 2:**
if G has 2k odd degrees then G can be drawn by lifting the pen k times
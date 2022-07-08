# Definitions
`palnar:` a planar graph is where the edges dont overlap (if a graph has one cycle then its planar)

`crossing number:` is number of overlappings
`plane graph:` is a planar graph

`Faces:` a, b and c
`outer face:` d
![[Pasted image 20220131134833.png | 150]]

`subdivision:` is adding vertices to the graph with degree 2
![[Pasted image 20220131140422.png | 200]]


# Theorems
- **Euler's Formula:** if a graph is connected with `n` vertices, `q` edges, `f` faces, then `n-q+f = 2` 
	- **Corollary:** if a graph is not connected then `n-q+f = k+1` where K is the number of connected components
- **Theo 1:** if a graph is planner then and `n >= 3` with q edges then `q <= 3n-6`
	- **Corollary:** $\delta(G)<=5$
- **Theo 2:** if a graph is planar with `n` vertices, `q` edges, and girth `g` then $q <= \frac{g*(n-2)}{g-2}$
	- **Corollary:** if a graph is planar and theres no triangles, then `q <= 2n-4`
- **Kuratowski:** G is planar <==> it contains no subdivision of $k_5$ or $k_{3,3}$

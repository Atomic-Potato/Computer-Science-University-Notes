# Definitions
`cut vertex:` if the deletion of the vertex disconnects the graph / conneceted components++
`bridge / cut edge:` same as above but for edges

`vertex connectivity:` $\kappa(G)$ is the min num of vertices needed to disconnect a graph
`vertex cutset:` its the set of vertices that disconnect the graph (this includes the vertices that help in disconnecting the graph in kappa)
`K-connected:` if kappa >= K

`edge connectivity` $\lambda(G)$ same as kappa but for edges
`edge cutset:` same as vertex cutset but for edges
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> Btw when we say a set of order n, we mean it should contain n elements </span>Sets Note</label>

`internally disjoint u-v paths:` if we have two paths connecting u and v and these paths have no edges in common other than u and v (this also automatically makes it `edge disjoint`)
`seperates` is a set does not of edges and vertices that doesnt include u neither v

`minimum cut` i think its the min number of edges needed to disconnected all the paths between u and v

# Theorems
- $\kappa(G) <= \lambda(G) <= \delta(G)$ (delta G is the min degree)
- **Whitney's theorem:** A graph with at least 3 vertices is 2-connected iff each pair u,v in the set of vertices is connected by a pair of internally disjoint u-v paths
- **Menger's theorem:** max num of internally disjoint u-v paths = num of vertices in the set that seperates  u and v
	- **corollary:** each vertex in S (separating set) is contained in only 1 u-v path
- The max num of edge-disjoint u-v paths = min num of edges in the set that separates u and v.


# Definitions
### Graphs as models
The `order = number of vertices`
The `size = number of edges`

A `loop` is an edge the connects to the same vertex
A `multiple edge` 2 vertices with multiple edges

Vertices are `adjacent` if they have an edge between them, otherwise they are `nonadjacent`. And we can say these 2 vertices are neighbors

`deg(v)` = number of edges connected to this vertex
`end vertex / leaf` is a vertex with one edge

`smallDelta(G)` = min degree
`bigDelta(G)` = max degree
if they are equal then `G` is `Regular`
`r-regular` if all the vertices have the same degree `r`

`bipartite` graphs are graphs with multiple types of vertices but each vertex in each doesnt connect with a vertex of the same type
`weighted` graphs where each edge has value representing its distance/length

`Eulerian` graphs is where you can travel each and all the edges once from one vertex and back to it
`Hamiltonian` graphs, same as above but with vertices

`Graph coloring` is giving vertices a color but if 2 vertices are connected with an edge they cant have the same color
`Graph matching` is matching vertices in a maximum possible way... ?

**Theorem (Euler):**
Sum of degrees in a graph = 2 * numOfEdges
We deduce that a graph has an even number of vertices of odd degrees

### Subgraphs and types of graphs
**A walk**
`u-v walk` is going from u to v along any edge or vertex as many times as we'd like
it can be a `length` where edges can be repeated
a`trail` where no vertex can be repeated
and a `circuit` which is a closed trail

**A path**
`u-v path` is same as a walk but no vertex is repeated, and there's `cycle` which is the same as `circuit`
```c
Path theorem: 
if smolDelta(G) >= 2 
then G has a cycle of smolDelta(G)+1 
and a path of length smolDelta(G)
```

**others**
`connected graph` is where all vertices are connected to the graph and if at least one is not then its called `disconnected graph` and each connected part is called `component` 
`supergraph` is a graph containing a `subgraph`

`induced and spanning graphs:`
![[indcued and spanning graphs.JPG | 300]]

`complete graph / clique` is a graph where each vertex is has an edge with all other vertices and its denoted `K_n` where n = numOfVertices
`K_1` is called `trivial graph`

`Cycle:`
![[a cycle.JPG | 300]]

`Path`
![[path.JPG | 300]]

`Complete bipartite graph`
denoted `K_n_m`
![[complete bipartite graph.JPG | 300]]
the `k_1_m` is called a `star` and each `m` is called an `end vertex`
### Trees
An example of trees is K_1_m and paths 
`Leavs` are the end vertices of a `Tree`

**Properties of trees**
- There's always at least 2 end vertices
- every edge is a bridge/cutedge
- all u-v paths are geodesic which means there are no cycles
- edges = vertices - 1

**Theorem**
The sum of degrees in a tree graph = 2 * (numOfVertices - 1)
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> Can be used to determine if a tree graph degree sequence is graphical </span>How can we use it to see if its graphical ?</label>

### Isomorphic graphs

Two graphs are `Isomorphic` if they are equal / bijective

`Degree sequence` is putting the highest degrees at first down to the smallest sequence, take for example P_4, then it will have a sequence = 2 2 1 1

**How to know if a degree sequence is `graphical`?**
- Delete the 1st number K
- Subtract 1 from the next K degrees and sort again
- repeat
- stop only if we have only zeros left or the degree is 2 2 2 ... 2 2 1 1 which means its just a path P_n, if its only zeros at the end then its graphicals, i think if you become negative then it wont be negative (Future me here, wtf did you say here lol ? i think i meant if it becomes negative then its not graphical)

### Graph Operations
`Union:` just place the graphs next to each other duh. Denoted `G U H`
`Join:` connect each vertex from each graph with every single vertex in the other graph. Denoted `G + H`
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> Note that if we have G1 + G2 + G3... we join vertices of G1 and G2 and then we connect vertices of G2 and G3 and so on, its not like (G1+G2) + G3 </span></label>
`Wheel:` Denoted `W_m,n = K_m + C_n`. Note that to draw it you first draw the C_n and then add in K_m
`Edge or vertex deletion:` obvious duh. Denoted `G - v`
`Complement:` **Property: bar(G+H) = bar(G) U bar(H)**
![[Graph complement.JPG | 300]]
`Self-complementary:` 
if G isomorphic to bar(G)
**Properties:**
- **numOfVertices n = 4k or 4k+1 for some k**
- **numOfEdges size = n(n-1)/4**

`Cross product:`
Give each vertex a number from v_1 to v_n in G and u_1 to u_m in H
Now we will make vector2(s) out of all of them in order like so
(v_1, u_1); (v1, u2); ... (v1, u_m)
...								         ...
(v_n, u_1); .................(v_n, u_m)
Now we start drawing the cross product `GxH` with the help of this example
![[example on cross product.JPG | 600]]
the `1` in (*1*, `1`) is connected to `2` so we connect it to the vector2 which starts with *1* and ends with `2`.
And for *1* in (*1*, `1`) we have it connected to vertex *2* and *3* so we connect it to the vertices that start with *2* and *3* and end in `1` which are (*2*, `1`) and (*3*, `1`).

`Hypercubes:` 
A little confusing so here you go and im too lazy to explain:https://www.youtube.com/watch?v=5CA_RliXe5M
==Also the number of edges in a hypercube = (2^n-1) x n==
**Proving all hypercubes are bipartite:**
https://slaystudy.com/prove-that-hypercube-is-bipartite/

`Meshes:` n-mesh `M(a,b,c, ...)` = `P_a x P_b x P_c x ....`
`Line graphs:` Denoted L(G)
![[Line graph.JPG | 300]]
`Edge contraction:` Denoted `G/vw`. You just make the vertices u and v a single one.
![[edge contraction.JPG | 300]]
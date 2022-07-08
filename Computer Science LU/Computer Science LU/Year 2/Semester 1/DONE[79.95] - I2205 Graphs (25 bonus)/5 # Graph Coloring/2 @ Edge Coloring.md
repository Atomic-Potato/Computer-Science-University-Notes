# Definitions
**`edge coloring`** is assigning colors to edges even if 2 edges of the same vertex have the same color
**`proper edge coloring`** is edge coloring but each 2 edges of the same vertex cannot have the same color
**`edge-chromatic number`**$X_1(G)$ is the same as vertex chromatic number but for vertices
**Theorems**
- $X_1(G) >= \Delta(G)$ for all graphs except for bipartite graphs its equal 

**`monochromatic`** is when all edges have the same color
**`biochromatic`** is when we have only 2 colors for edges
**`ambivalent`** is when a vertex has 2 edges with 2 different colors

# Theorems
**Vizing** $\Delta(G) <= X_1(G) <= \Delta(G)+1$

**Vizing Extended** (only applied in multigraphs, when 2 vertices have multiple edges) $\Delta(G) <= X_1(G) <= \Delta(G)+h$ where h is the max number of  edges of 2 vertices 

**Shannon**$\Delta(G) <= X_1(G) <= 1 \space or \space 2$
- 1: $\frac{3\Delta(G)}{2} \space if \space \Delta \space is \space even$
- 2: $\frac{3\Delta(G)-1}{2} \space if \space \Delta \space is \space odd$

**Konig** if graph is bipartite $X(G) = \Delta(G)$

**Theorem** `How to find how many monochromatic triangles we have in a graph?`
$$\frac{n(n-1)(n-2)}{6}-\frac{1}{2} * \sum^n_{i=1}[color(i)*(n-color(i)-1)]$$
where n is the number of vertices and color(i) is how many edge with color "color" are connected to vertex i

**Theorem** if n=2 * k, k >= 3, then in any coloring of $k_n$ with 2 colors, there are at least
$$\frac{k(k-1)(k-2)}{3}$$
monochromatic triangles
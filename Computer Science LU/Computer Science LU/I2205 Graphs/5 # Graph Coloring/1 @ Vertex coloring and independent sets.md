# Definitions
**`Vertex coloring`** is assigning colors to vertices duh
**`k-coloring`** i can color the graph with k colors
**`k-colorable`** a graph that permits a k-coloring
**`uniquely k-colorable`** means we cannot find more than one coloring scheme 
**Theorems**
- if G is uniquely k-colorable then the min degrees >= k-1
- Given 2 numbers i and j, 1 <= i < j <= k,  the induced graph on the sets $V_i \bigcup V_j$ is connected 

**`chromatic number X(G)`** min number of colors needed for any proper k-coloring of G
==We can call a graph "tripitite" if X(G) = 3==
**Properties:**
- in `Bipartite` graphs, ==X(G) <= 2==
- in `odd cycles` graphs, ==X(G) = 3==
- in `K_n`, ==X(G) = n==

**Theorems:**
- if G is ==k-critical==, then ==the min degrees of G >= k-1==
- if ==X(G)=k== then we must have at least k vertices of degrees at least equal to ==k-1==
**corollary:** $X(G) <= max \space number \space of \space degrees + 1$
**Theorem (Brooks):** except for 'odd cycles' and 'complete graphs', X(G) <= max degrees of G


**`k-critical`** when ==X(G) = k== and ==X(G-v) = k-1==

**`independent`** is where all pairs in a subgraph of G are not connected
**`independence number`**$\beta(G)$: is the max size of an independent set
**Properties**
- $\beta(K_n) = 1$
- $\beta(1, K_n) = n$
- $X(G) >= \frac{n}{\beta(G)}$
- $X(G) <= n - \beta(G)+1$

**`girth`** is the length of the smallest cycle in the graph if theres any
**`clique`** a complete graph

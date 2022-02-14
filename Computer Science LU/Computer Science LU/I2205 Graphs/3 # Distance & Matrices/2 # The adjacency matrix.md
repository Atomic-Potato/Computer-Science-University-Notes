# Definitions
**`Adjacency Matrix`** is a matrix (like unity's physics matrix) where if each vertex are adjacent we place `1` and if not `0`
It's also called a binary matrix and its symmetric.
![[adjacency matrix.jpg | 500]]

doing `A**n` will give us the amount of ways we can travel between 2 vertices `(i, j)` in exactly `n edges`

**Calculating the adjacency matrix of the complement of the graph**
`bar(G) = J - A - I`, where:
`J` = the identity matrix where all of its components are `1`
`A` = G
`I` = matrix where only its diagonal is `1s` and the rest is `0s`

**`trace`** is the sum of the diagonal elements of a matrix

**`incidence matrix`** is where the rows of the matrix are the vertices and the columns are the edges. And we put `1` if a vertex is connected to an edge, otherwise 0.

**`submatrix`** is when we pick `a non consecutive` number of rows and columns of a matrix
**`block`** is when we pick `a consecutive` number of rows and columns of a matrix

# Theorem
**The adjacency matrix of a graph**
- The number of triangles `(k_3)` in G = `trace(G^3) / 6`

**The incidence matrix**
- M x trans(M) = A + D
Where `M = incidince matrix` | `A = adjacency Matrix` | `D = diagonal matrix where each element (i, i) = deg(v_i)`

# Notes:
- Weights are predefined and not calculated or something, this is different from branches weights 
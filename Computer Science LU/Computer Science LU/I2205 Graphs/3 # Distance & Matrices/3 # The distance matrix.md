# Definitions
**`The distance matrix`** is an `n*n` matrix that stores the distance between vertices

# Theorems
- **Obtaining the distance matrix from the adjacency matrix**
`S_k = I + A + A^2 + ... + A^3`
- e(v_i) = min value of k such that the row `i` has no zero entries
- A graph G of is connected <==> S_n-1 has no zero entries
- rad(G) is the minimum k such that at least one of the	rows has no zero entries
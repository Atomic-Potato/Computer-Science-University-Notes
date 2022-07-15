# Floyd Warshall's algorithm
```cpp
//precondition: adj[i][j] contains the weight of edge (i, j)
//or infinity if there is no such edge

for(int k=0; k<V; k++)
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])
```

Note that this algorithm is good for smoll matrices for example up to $M_{200}$

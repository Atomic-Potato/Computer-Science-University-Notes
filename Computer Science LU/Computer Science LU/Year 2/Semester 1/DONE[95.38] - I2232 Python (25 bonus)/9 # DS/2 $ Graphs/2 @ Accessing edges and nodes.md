Nodes and Edges can be accessed together using the` G.nodes()` and `G.edges()` methods. Individual nodes and edges can be accessed using the bracket/subscript notation.

```python
G.nodes() #NodeView((1, 2, 3))
G.edges() #EdgeView([(1, 2), (1, 3), (2, 3)])
G[1] # same as G.adj[1] #AtlasView({2: {}, 3: {}})
G[1][2] #{}
G.edges[1, 2] #{}
```
Namings of bipartite graphs
`Equatiable:` V1 = V2 (sets of disconnected vertices)
`Nearly Equatiable:` V1 - V2 = 1
`Skewed:` V1 - V2  >= 2

# Checking if a graph is bipartite
- **Algorithm 1**
	- name the first vertex a, then name its neighbors b
	- do the same for all vertices but if one of them already has a name just give its neighbors the opposite
	- repeat until all vertices are filled or you have a contradiction 

## Theorems
**`Theo 1:`** if G contains any odd cycles then its not bipartite
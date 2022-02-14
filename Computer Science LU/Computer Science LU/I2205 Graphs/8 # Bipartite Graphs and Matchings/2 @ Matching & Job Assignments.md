`Matching M:` a set of the edges chosen in such a way that no two edges share an endpoint

# Matching in a bipartite graph
`complete matching from X to Y:` is if we can match each vertex in X with an edge to a vertex in Y (|X|<=|Y|, the || means the set of vertices)
`perfect matching:` is when we can complete match from X to Y and from Y to X (|X| = |Y|)

# Finding maximum matching
`Maximum matching:` is the way where you can match the most vertices in a graph
`Maximul Matching:` is when you cant match anymore vertices
https://youtu.be/bOJC93XxoFc
![[Pasted image 20220121202436.png | 400]]

 `M - alternating path:` is a path of edges which alternate between matched and unmatched like the path in the first graph in the above photo, c->e->f->g
 `M - matched or saturated:` is when a vertex finds a match
 `M - augmenting path:` is an ==alternating== path that starts from an unmatched vertex and ends in an unmatched vertex

`Perfect matching:` is when all the vertices are matched once (|V1|=|V2|)

 ## Theorems
 - **Berge's Matching Theorem:** a matching M is maximum iff there is no M-augmenting path in G

## Khun's Algorithm 
First, we take an empty matching. Then, while the algorithm is able to find an augmenting path, we update the matching by alternating it along this path and repeat the process of finding the augmenting path. As soon as it is not possible to find such a path, we stop the process - the current matching is the maximum.
```c
int n, k; 
vector<vector<int>> g; 
vector<int> mt; 
vector<bool> used; 

bool try_kuhn(int v) 
{ 
	if (used[v]) 
		return false; 
	used[v] = true; 
	for (int to : g[v]) 
	{ 
		if (mt[to] == -1 || try_kuhn(mt[to])) 
		{ 
			mt[to] = v; 
			return true; 
		} 
	} 
	return false; 
} 

int main() 
{ 
	//... reading the graph ... 
	mt.assign(k, -1); 
	for (int v = 0; v < n; ++v) 
	{ 
		used.assign(n, false); 
		try_kuhn(v); 
	}
}
```

# Complete Matchings in bipartite graphs
 - **Hall's Matching Theorem:** a bipartite graph has a complete matching from x to y iff |N(S)| >= |S| for every subset S in X
 ![[Pasted image 20220122100846.png | 400]]

- **Theorem:** if a graph is a regular graph then it has perfect matching.

# Matchings and Job Assignments
## Edmond's Blossom Algorithm
`A stem` is an alternating path that starts with an unmatched vertex and ends with a matched vertex
`A blossom` is an odd cycle of which all of its vertices are matched
`A flower` is two alternating paths that start at a vertex u and end in a vertex v of which one path has an odd length and the other has an even length.
![[Pasted image 20220122102635.png | 400]]

The way this algorithm works is when you find a `flower` you turn the `blossom` into a single vertex like in the below pictures
![[Pasted image 20220122103231.png | 400]]
![[Pasted image 20220122103248.png | 400]]
![[Pasted image 20220122103313.png | 400]]
Then once done you find an `m-agumenting path` and then you alternate the matching in that path.
![[Pasted image 20220122103411.png | 400]]
![[Pasted image 20220122103436.png | 400]]
(im not sure if this works from the first time, but i think you should keep repeating the process to find all the flowers and apply the algorithm)
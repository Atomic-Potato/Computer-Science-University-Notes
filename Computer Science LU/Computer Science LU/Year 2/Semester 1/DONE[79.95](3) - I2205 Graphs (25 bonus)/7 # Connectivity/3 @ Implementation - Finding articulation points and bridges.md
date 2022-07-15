  https://youtu.be/iGGolqb6gDE

- declare a counter to count the time a vertex has been visited
- We start checking for each vertex if they are visited or not
- of course the first vertex will not be visited so we will take it as root of the dfs search
- we set a variable to count how many root children this vertex has
- we starts the articulation search with this vertex
- set the dfs low and num equal to the search counter
- start to loop over the neighbors of the vertex
	- if the neighbor is not visited before we set the parent of this neighbor to the current calling vertex
		- else if the neighbor vertex is visited and its not the parent we set the dfs low of the root vertex  to the dfs low of the neighbor if its lower
	- we check if our current calling vertex is still the same as the dfs root search variable if so we increase that variable
	- now we initiate dfs again with this neighbor
	- after the function finishes we check if the dfs low of the neighbor is greater or equal than the dfs num of the root vertex, if so then the root vertex is an articulation point
	- we do the same as above but strictly greater to check if the edge between them is an articulation edge
	- and finally we set the dfs low of the root vertex = to min dfs low of the root or dfs low of the neighbor
- once we're done with all of that we check if the root of the search children variable is greater than 1, if so the root vertex is an articulation point otherwise its not

![[ArticulationPoints.cpp]]
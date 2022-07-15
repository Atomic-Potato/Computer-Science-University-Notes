 # Topological Sort
 ITS SORTING THE ACTIVITIES SO THAT ONCE WE FINISH ONE ACTIVITY WE CAN DIRECTLY MOVE ON TO THE NEXT ONE WITHOUT MAKING ANY OTHER ACTIVITIES
 
 ## Tarjan's algorithm
// SORTING THE ACTIVITIES IN A DIAGRAPH

// The concept of this algorithm is
// we travel through the graph using dfs
// when we reach a vertex that has no more children
// we push it to the top of the stack
// and we go back
// we keep doing the same until we reach back to the original vertex
// and we move on to the next connected component if theres any
// once done we reverse the stack and thus we get the ordering
 ![[Pasted image 20220203135743.png | 650]]

 ## Kahn's algorithm
 // SORTING THE ACTIVITIES IN A DIAGRAPH

// we calculate the in degree for each vertex
// if its equal to "zero" we push into the queue
// now while the queue is not empty
// we delete the front vertex from the graph and put in the sorted list
// reduce the in degree for the vertices that were connected to this vertex
// if its neighbors now have an indegree of "zero" we push them into the queue
 ![[Pasted image 20220203140436.png | 650]]

 # Finding Strongly connected components

 ![[Pasted image 20220203150738.png | 650]]

 ## Tarjan's Algorithm
  // FINDING STRONGLY CONNECTED COMPONENTS

// We travers the graph using DFS while assigning dfs_num and dfs_low for each vertex
// and as we travel we push in vertices into a stack
// once we reach a child of a vertex that is already visited we set dfs_low for the parent to
// min(dfs_low(parent), dfs_child)
// once done with DFS we start emptying the stack
// while dfs_low != dfs_num for each vertex, then this vertex is part of a SCC
// other wise we reached the start of the connected component
// and so we move on to the next connected component
 ![[Pasted image 20220203150858.png | 650]]

 ## Kosaraju's Algorithm
 // FINDING STRONGLY CONNECTED COMPONENTS

// First we path through the graph using dfs
// and we push in each newly visited vertex into a vector
// now we traverse the graph once again but in the transpose of the graph
// we start from the first vertex in the vector
// if this vertex doesnt have any children that are not visited
// then we reached the end of the first connected component
// otherwise we travel into the next vertex in the list
 ![[Pasted image 20220203152450.png | 650]]
 
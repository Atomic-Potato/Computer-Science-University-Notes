**`I recommend pasting these into an IDE`**
![[DFS.cpp]]
![[DBFS.cpp]]
![[GraphAlgorithms.cpp]]
# DFS implementation
### The recursive way
```cpp
# include <stdio.h>

# include <iostream>

# include <vector>

using namespace std;

  

//Defininig visited and not visited

#define VISITED 1

#define NOT_VISITED -1

  

//to make DFS we need vector of vector ints

typedef vector<int> vi;

vector<vi> adjacencyList;

  

//Vector containing if each vertex is visited or not

vi dfsNum;

  

//Sorting algorithm DFS

void DFS(int u) // we take only the non visited vertex

{

 printf("%d", u); //Treating the vertex

 dfsNum[u] = VISITED;

  

 for(int i=0; i< (int)adjacencyList[u].size(); i++)

 {

 //visit all the neighbors of u

 int v = adjacencyList[u][i];

 if(dfsNum[v] == NOT_VISITED)

 DFS(v);

 }

}

  

int main()

{

 int vertices, edges;

 int vertexA, vertexB;

  

 scanf("%d %d", &vertices, &edges);

 //Giving all the vector elements of the adjacencyList an empty vector of ints

 adjacencyList.assign(vertices, vi());

  

 //Scanning the edges

 for(int i=0; i<edges; i++)

 {

 //Scanning each edge and asigning it to the adjacencyList

 scanf("%d %d", &vertexA, &vertexB);

 adjacencyList[vertexA].push_back(vertexB);

 adjacencyList[vertexB].push_back(vertexA);

 }

  

 dfsNum.assign(vertices, NOT_VISITED);

 //we could call the dfs function on this line

 //but this doesnt work for a non connected graph

 //so instead we search each vertex if its visited or not

 //if its not visited then we apply DFS on it

 for(int i = 0; i < vertices; i++)

 if(dfsNum[i] == NOT_VISITED)

 DFS(i);

  

 return 0;

}
```

### The iterative way
```cpp
void DFS(int u) // we take only the non visited vertex

{

 //Remember that we have 3 vertices in here because the first root will always be unvisited

 //Adding the non visited vertex to the top of the stack

 stack <int> verticesStack;

 verticesStack.push(u);

 dfsNum[u] = VISITED;

  

 while(!verticesStack.empty())

 {

 // storing the top vertex and poping it from the stack

 int vert = verticesStack.top();

 verticesStack.pop();

 printf("%d ", vert);

  

 //Checking if the children of vert are visited

 for(int i=0; i < (int)adjacencyList[vert].size(); i++)

 {

 int childVertex = adjacencyList[vert][i];

 if(dfsNum[childVertex] == NOT_VISITED)

 {

 dfsNum[childVertex] = VISITED;

 verticesStack.push(childVertex);

 }

 }

 }

}
```

# BFS
```cpp
void BFS(int u) // we take only the non visited vertex

{

 //Remember that we have 3 vertices in here because the first root will always be unvisited

 //Adding the non visited vertex to the back of the queue

 queue <int> verticesQueue;

 verticesQueue.push(u);

 dfsNum[u] = VISITED;

  

 while(!verticesQueue.empty())

 {

 // storing the front vertex and poping it from the queue

 int vert = verticesQueue.front();

 verticesQueue.pop();

 printf("%d ", vert);

  

 //Checking if the children of vert are visited

 for(int i=0; i < (int)adjacencyList[vert].size(); i++)

 {

 int childVertex = adjacencyList[vert][i];

 if(dfsNum[childVertex] == NOT_VISITED)

 {

 dfsNum[childVertex] = VISITED;

 verticesQueue.push(childVertex);

 }

 }

 }

}
```

# Getting the number of components
we already done this part we just need to count it in here
```cpp
int componentsCount = 0;

 for(int i = 0; i < vertices; i++)

 {

 if(dfsNum[i] == NOT_VISITED)

 {

 componentsCount++;

 BFS(i);

 }

 }
```
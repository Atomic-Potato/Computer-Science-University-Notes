/*Test Input
9
1 1 0
3 0 0 2 0 3 0
2 1 0 3 0
3 1 0 2 0 4 0
1 3 0
0
2 7 0 8 0
1 6 0
1 6 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define DFS_WHITE  -1

vector<vector<pair<int,int>>> AdjList;
vector<int> dfs_parent;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> articulation_vertex;

int dfsNumberCounter;
int dfsRoot;
int rootChildren;
int V;

void read()
{
    int numOfNeighbors;
    int weight;
    int id;

    scanf("%d", &V);
    AdjList.assign(V, vector<pair<int,int>>());

    for(int i=0; i<V; i++)
    {
        scanf("%d", &numOfNeighbors);
        for(int j=0; j < numOfNeighbors; j++)
        {
            scanf("%d %d", id, weight);
            AdjList[i].push_back(make_pair(id, weight));
        }
    }
}

void FindPointsAndBridges(int vertex)
{
    //setting the dfs num (when the dfs search entered this vertex) and the same should be the dfs low since its just got visited
    dfs_num[vertex] = dfsNumberCounter;
    dfs_low[vertex] = dfsNumberCounter;
    dfsNumberCounter++;

    // starting the dfs search for the neighbors of the root
    for(int i=0; i < (int)AdjList[vertex].size(); i++)
    {
        //getting the current neighbor
        pair<int, int> neighbor = AdjList[vertex][i];
        if(dfs_num[neighbor.first] == DFS_WHITE) // if the neighbor is not visited
        {
            //we set the parent of the neighbor as the root vertex
            dfs_parent[neighbor.first] = vertex;
            
            //if the current vertex is the root we started the function with
            // basically the root start of the graph component
            if(vertex == dfsRoot)
                rootChildren++;
            
            //Now we move on with the dfs
            FindPointsAndBridges(neighbor.first);

            //When we reach the end of the tree / search and we come back to the current neighbor
            //if the low of the neighbor is greater or equal to the enter time of the root
            //then this root is a an articulation vertex
            if(dfs_low[neighbor.first] >= dfs_num[vertex])
                articulation_vertex[vertex] = true;
            //if the low is strictly greater than the entering time
            // then the edge between the neighbor and the root is and articulation edge
            if(dfs_low[neighbor.first] > dfs_num[vertex])
                printf(" Edge (%d, %d) is a bridge\n", vertex, neighbor.first);
            
            //now we change the low of the neighbor if needed ???
            //shouldnt it be the neighbor ??
            dfs_low[vertex] = min(dfs_low[vertex], dfs_low[neighbor.first]);
        }
        else if(neighbor.first != dfs_parent[vertex]) //otherwise if its visited and its not the parent then its a back edge
            dfs_low[vertex] = min(dfs_low[vertex], dfs_low[neighbor.first]);
    }
}

void Articulations()
{
    //Initialization
    dfs_parent.assign(V, -1);// storing the parent of each vertex while doing dfs
    dfs_num.assign(V, DFS_WHITE); //visiting time in the search
    dfs_low.assign(V, 0); //used in the algorithm to find if the current vertex is an articulation point
    articulation_vertex.assign(V, 0); // stroing the vertecies that are articulation points
    dfsNumberCounter = 0; //the timer for dfs search when entering a new vertex


    printf("Articulation Points & Bridges (the input graph must be UNDIRECTED)\n");
    printf("Bridges\n");
    for(int i=0; i < V; i++)
    {
        if(dfs_num[i] == DFS_WHITE) //if vertex is u
        {
            dfsRoot = i; // current root
            //this thing is used to check if the starting root vertex is an articulation point
            //theres a chance in the later function it will trun into an articulation point
            // this variable will turn it back to a normal point
            rootChildren = 0; 
            FindPointsAndBridges(i); // lets find the articulations starting from i
            //checkking if the root of the component is an actual articulation point or not
            articulation_vertex[dfsRoot] = (rootChildren>1);
        }
    }

    //We already found them above with the bridges so no need to do any work here
    printf("Articulation Points:\n");
    for(int i=0; i<V; i++)
        if(articulation_vertex[i])
            printf(" Vertex %d\n", i);
}

int main()
{
    read();

    return 0;
}

//Thinking Space:
/*
First we set all the variables to empty
We create a timer for dfs
we choose a root which will be 0
we set the dfs_num and the dfs_low = counter
we go inside the first neighboring vertex of the root vertex
keep a refrence for the parent vertex for each new visited vertex 
we do the same for the new vertex
if we reach a vertex where all the new vertex is visited and theres no other option
we set the low of the visited vertex to the current vertex following the formula
we keep doing this until we reach a vertex with other neighbors
*/
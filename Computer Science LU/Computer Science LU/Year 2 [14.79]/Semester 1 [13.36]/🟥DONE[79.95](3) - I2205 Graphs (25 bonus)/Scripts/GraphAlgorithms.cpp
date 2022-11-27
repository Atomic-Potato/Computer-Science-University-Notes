#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define DFS_BLACK 1
#define DFS_WHITE -1
#define BFS_BLACK 1
#define BFS_WHITE -1

typedef vector <int> vi;

vector <vi> AdjList;
vi dfs_num;

//Using recursion
void dfs(int u)
{
    if(dfs_num[u] == DFS_WHITE)
        printf("%d ", u);
    dfs_num[u] = DFS_BLACK;

    for(int i=0; i<(int)AdjList[u].size(); i++)
    {
        int v = AdjList[u][i];
        if (v == DFS_WHITE)
            dfs(v);
    }
}

//Using stacks
void dfs(int u)
{
    stack <int> vertexStack;
    vertexStack.push(u);
    dfs_num[u] = DFS_BLACK;

    while(!vertexStack.empty())
    {

        int topVertex = vertexStack.top();
        vertexStack.pop();
        printf("%d ", topVertex);

        for(int i=0; (int)AdjList[topVertex].size(); i++)
        {
            int childVertex = AdjList[topVertex][i];
            if(childVertex == DFS_WHITE)
            {
                vertexStack.push(childVertex);
                dfs_num[childVertex] == DFS_BLACK;
            }
        }
    }
}

void bfs(int u)
{
    queue <int> verticesQueue;
    verticesQueue.push(u);
    dfs_num[u] = BFS_BLACK;

    while(!verticesQueue.empty())
    {
        int frontVertex = verticesQueue.front();
        verticesQueue.pop();
        printf("%d", frontVertex);

        for(int i=0; i < (int)AdjList[frontVertex].size(); i++)
        {
            int childVertex = AdjList[frontVertex][i];
            if(childVertex == DFS_WHITE)
            {
                verticesQueue.push(childVertex);
                dfs_num[childVertex] == DFS_BLACK;
            }
        }
    }
}

int CC()
{
    int connectedComponents = 0;
    for(int i=0; i < V; i++)
    {
        if(dfs_num[i] == DFS_WHITE)
        {
            dfs(i);
            connectedComponents++;
        }
    }
    return connectedComponents;
}

vi prufer_code;
void prufer_code_gen() 
{
    vector<bool> activeVertices(V, true);
    vector<int> vertexEdgeCount(V, 0);
    priority_queue<int> pruferQueue;
    
    for(int i=0; i < V; i++)
    {
        vertexEdgeCount[i] = AdjList[i].size();
        if(vertexEdgeCount[i] == 1)
            pruferQueue.push(-i);
    }
    
    prufer_code.resize(V-2);
    
    for(int i=0; i<V-2; i++)
    {
        int smallestEndVertex = pruferQueue.top();
        pruferQueue.pop();
        
        activeVertices[-smallestEndVertex] = false;
        
        int neighborVertex;
        for(int j : AdjList[-smallestEndVertex])
        {
            if(activeVertices[j])
            {
                neighborVertex = j;
                break;
            }
        }
        
        prufer_code[i] = neighborVertex;
        vertexEdgeCount[neighborVertex]--;
        if(vertexEdgeCount[neighborVertex] == 1)
            pruferQueue.push(-neighborVertex);
    }
}

vector<pair<int,int>> edges;

void prufer_to_edges()
{
    int verticesCount = prufer_code.size()+2;
    vector<int> vertexDegree(verticesCount, 1);
    priority_queue<int> leaves;

    for(int i : prufer_code)
        vertexDegree[i]++;

    for(int i=0; i<verticesCount; i++)
        if(vertexDegree[i]==1)
            leaves.push(i);

    for(int i : prufer_code)
    {
        int leaf = leaves.top();
        leaves.pop();

        edges.emplace_back(-leaf, i);
        edges.emplace_back(i, -leaf);
        
        vertexDegree[i]--;
        if(vertexDegree[i] == 1)
            leaves.push(-i);
    }

    edges.emplace_back(-leaves.top(), verticesCount-1);
    edges.emplace_back(verticesCount-1, -leaves.top());
    leaves.pop();
}
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<int> dfs_num;
vector<vector<int>> AdjList;
int V;

void DFS(int vertex)
{
    dfs_num[vertex] = DFS_BLACK;

    for(int i=0; i<(int)AdjList[vertex].size(); i++)
    {
        int neighbor = AdjList[vertex].size();
        if(dfs_num[neighbor] == DFS_WHITE)
            DFS(neighbor);
    }
}

bool IsConnected()
{
    DFS(0);

    for(int i=0; i<V; i++)
        if(dfs_num[i] == DFS_WHITE)
            return false;
    
    return true;
}

int solve()
{
    dfs_num.assign(V, DFS_WHITE);

    if(!IsConnected())
        return 0;

    int oddVerticesCount = 0;

    for(int i; i < V; i++)
        if((int)AdjList[i].size()%2 == 1)
            oddVerticesCount++;
    
    if(oddVerticesCount > 2)
        return 0;

    return oddVerticesCount ? 1 : 2; 
}
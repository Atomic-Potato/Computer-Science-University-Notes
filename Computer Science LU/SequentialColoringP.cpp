#include <stdio.h>
#include <vector>

using namespace std;

#define NOT_COLORED -1
typedef vector<int> vi; 
vi dfs_num;  
vector<vi> AdjList;
int V;

void read()
{
    int  E;
    int a, b;
    
    scanf("%d", &V);
    scanf("%d", &E);
    AdjList.assign(V, vi());
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &a, &b);
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
}

void color(int u)
{
    vi vertexColoredNeighbors;

    for(auto j: AdjList[u])
        if(dfs_num[j] != NOT_COLORED)
            vertexColoredNeighbors.push_back(dfs_num[j]);
    
    int color = 1;
    while(true)
    {
        if(count(vertexColoredNeighbors.begin(), vertexColoredNeighbors.end(), color))
            color++;
        else
            break;
    }
    dfs_num[u] = color;
}

void solve() 
{
    dfs_num.assign(V, NOT_COLORED);
    
    for(int i=0; i < V; i++)
        if(dfs_num[i] == NOT_COLORED)
            color(i);
}

void print()
{
    printf("Colors\n");
    for (int i = 0; i < V; i++) 
        printf("vertex %d colored %d\n",i,dfs_num[i]);
}

int main()
{
    read();
    solve();
    print();
    printf("Sup");
}
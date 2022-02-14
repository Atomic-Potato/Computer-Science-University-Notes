#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define NOT_COLORED -1
typedef vector<int> vi; 
vi dfs_num;  
vector<vi> AdjList;
int V;
vector<pair<int,int>> degrees;

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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return b.second < a.second;
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
    for(int i=0; i < V; i++)
        degrees.push_back(make_pair(i, (int)AdjList[i].size()));
    
    sort(degrees.begin(), degrees.end(), cmp);

    dfs_num.assign(V, NOT_COLORED);
    
    for(int i=0; i < V; i++)
        if(dfs_num[degrees[i].first] == NOT_COLORED)
            color(degrees[i].first);
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
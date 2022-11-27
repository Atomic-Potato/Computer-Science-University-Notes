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

void solve() 
{
    //printf("Filling dfs_num\n");
    for(int i=0; i<V; i++)
        dfs_num.push_back(NOT_COLORED);

    //printf("\nStarting Algorithm\n");
    for(int i=0; i < V; i++)
    {
        //printf("%d's Adjacency List Size = %d\n", (int)AdjList[i].size());
        int vertexColor = 1;

        if(dfs_num[i] != NOT_COLORED || (int)AdjList[i].size() == 0)
        {
            if((int)AdjList[i].size() == 0)
                dfs_num[i] = 1;
            continue;
        }

        for(int j=0; j < (int)AdjList[i].size();)
        {
            //printf("i = %d  j = %d\n", i, j);
            //printf("Neighbor's color = %d", dfs_num[AdjList[i][j]]);
            
            if(vertexColor != dfs_num[AdjList[i][j]])
                j++;
            else
            {
                vertexColor++;
                j = 0;
            }

            if (j == (int)AdjList[i].size())
            {
                dfs_num[i] = vertexColor;
                break;
            }
        }
    }
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
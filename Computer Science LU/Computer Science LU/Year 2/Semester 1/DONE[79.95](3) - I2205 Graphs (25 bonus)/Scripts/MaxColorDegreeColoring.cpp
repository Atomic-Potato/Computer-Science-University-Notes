#include <stdio.h>
#include <vector>
#include <queue>
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

bool DegreesComparision(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

void solve()
{

    for(int i=0; i<V; i++)
    {
        pair<int, int> vertexDegree;
        vertexDegree.first = i;
        vertexDegree.second = (int)AdjList[i].size(); 
        degrees.push_back(vertexDegree);
    }
    sort(degrees.begin(), degrees.end(), DegreesComparision);

    /*
    printf("\n Degrees List : \n");
    for(int i=0; i<V; i++)
        printf("vertex : %d degreee : %d\n", degrees[i].first, degrees[i].second);
    printf("\n");
    */

    for(int i=0; i < V; i++)
        dfs_num.push_back(NOT_COLORED);

    for(int i=0; i < V; i++)
    {
        int vertexColor = 1;
        if(dfs_num[degrees[i].first] != NOT_COLORED || degrees[i].second == 0)
        {
            if(degrees[i].second == 0)
                dfs_num[degrees[i].first] = 1;
            continue;
        }

        for(int j=0; j < degrees[i].second + 1;)
        {
            if(vertexColor != dfs_num[AdjList[degrees[i].first][j]])
                j++;
            else
            {
                vertexColor++;
                j=0;
            }

            if(j == degrees[i].second)
            {
                dfs_num[degrees[i].first] = vertexColor;
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
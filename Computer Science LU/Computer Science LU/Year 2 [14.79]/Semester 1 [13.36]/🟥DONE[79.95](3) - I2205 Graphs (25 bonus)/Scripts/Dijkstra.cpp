#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1
#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;

int V;
int s; //is the starting position

void solve()
{
    vi distances(V, INF);
    distances[s] = 0;

    //a pq of integres sorted by the one greater first pair (second one indicates the pair symbol)
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));
    
    //Turned out wrong
    //vi parents(V, -1);

    while(!pq.empty())
    {
        ii front = pq.top();
        pq.pop();
        
        int distance = front.first;
        int currentVertex = front.second;

        if(distance > distances[currentVertex])
            continue;
        
        for(int i=0; i<(int)AdjList[currentVertex].size(); i++)
        {
            ii neighbor = AdjList[currentVertex][i];
            if(distances[currentVertex] + neighbor.second < distances[neighbor.first])
            {
                //parents[neighbor.first] = currentVertex;
                distances[neighbor.first] = distances[currentVertex] + neighbor.second;
                pq.push(ii(distances[neighbor.first], neighbor.first));
            }
        }
    }

    for(int i=0; i<V; i++)
    {
        printf("SSSP(%d, %d) = %d\n", s, i, distances[i]);
        //printf("Root: %d ", i);
        //for(int j=parents[i]; j != s; parents[j])
            //printf("%d ", parents[i]);
        printf("\n");
    }
}
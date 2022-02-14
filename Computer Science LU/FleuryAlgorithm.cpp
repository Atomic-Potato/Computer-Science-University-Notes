#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vector<pair<int, int>>> AdjList;
vector<int> dfs_num;
list<int> cycle;
int V, E;

void EulerTour(list<int>::iterator i, int vertex)
{
    for(vector<pair<int, int>>::iterator currentVertex = AdjList[vertex].begin(); currentVertex != AdjList[vertex].end(); currentVertex++)
    {
        //means if the current edge is avaliable
        if(currentVertex->second)
        {
            //set the edge is used
            currentVertex->second = 0;

            //move on to the next edges
            for(vector<pair<int,int>>::iterator nextVertex = AdjList[currentVertex->first].begin(); nextVertex != AdjList[currentVertex->first].end(); nextVertex++)
            {
                //if the next vertex is neighbor to the parent, and the edge between them is avaliable for usage
                if(nextVertex->first && nextVertex->second)
                {
                    //set as traveled and move on to the next vertex
                    nextVertex->second = 0;
                    break;
                }
            }

            EulerTour(cycle.insert(i, vertex), currentVertex->first);
        }
    }
}
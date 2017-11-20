#ifndef GRAPH2_H
#define GRAPH2_H
/*************************************************************************
* AUTHOR         : Jon Griswold
* STUDENT ID     : 364919
* ASSIGNMENT #12
* CLASS          : CS1D
* SECTION        : T Th
* DUE DATE       : 4/14/15
*************************************************************************/


#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>
#include <qlist.h>
#include "stadium.h"
using namespace std;

struct neighbor {
 int target;
    int weight;
    neighbor(int targetIn, int weightIn): target(targetIn), weight(weightIn)
    {
    }
};

typedef vector<vector<neighbor> > adjacencyList;

template <class keyType>
class Graph2{
    public:

        Graph2(int newSize);
        ~Graph2();
        void setMatrix(keyType **newMap);
        void setNames(Stadium *newString);

        void MST();
        void printMST(int parent[]);
        void ShortestTo(int from, int to);
        void DijkstraComputePaths(int source);
        list<int> DijkstraGetShortestPathTo(int vertex);
        QList<Stadium> PathFromXtoY(int x, int y);
        int GetDistance(int y);
    private:
        Stadium *names;

        vector<int> minDistance;
        vector<int> previous;
        adjacencyList adjacencyList1;
        int size;
        int total;
};

template <class keyType>
int Graph2<keyType>::GetDistance(int y){
    return minDistance[y];
}

//Constructor
template <class keyType>
Graph2<keyType>::Graph2(int newSize)
{
     size = newSize;
 names = new Stadium[size];
 total = 0;

}

template <class keyType>
Graph2<keyType>::~Graph2()
{
}

template <class keyType>
void Graph2<keyType>::setNames(Stadium* newString)
{
    names = newString;
}

template <class keyType>
void Graph2<keyType>::setMatrix(keyType **newMap)
{
 int secParam;
 adjacencyList temp(size);
 for(int index1 = 0; index1 < size; index1++)
 {
  for(int index2 = 0; index2 < size; index2++)
  {
   if(newMap[index1][index2] != 0)
   {
    secParam = newMap[index1][index2];
    temp[index1].push_back(neighbor(index2, secParam));
   }
  }
 }
 adjacencyList1 = temp;

}

//Uses dijkstra's algorithm for shortest path
template<class keyType>
QList<Stadium> Graph2<keyType>::PathFromXtoY(int x, int y)
{
 total = 0;
 DijkstraComputePaths(x);
 list<int> forOut = DijkstraGetShortestPathTo(y);
 QList<Stadium> temp;
 for( list<int>::const_iterator i = forOut.begin(); i != forOut.end(); ++i)
 {
     temp.append(names[*i]);
//  cout << names[*i] << endl;
 }
// cout << "Distance traveled: " << minDistance[y];
 return temp;
}


template <class keyType>
void Graph2<keyType>::DijkstraComputePaths(int source)
{
    int n = 13;
    minDistance.clear();
    minDistance.resize(n, 9999999);
    minDistance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    set<pair<int, int> > vertexQueue;
    vertexQueue.insert(make_pair(minDistance[source], source));

    while (!vertexQueue.empty())
    {
        int dist = vertexQueue.begin()->first;
        int u = vertexQueue.begin()->second;
        vertexQueue.erase(vertexQueue.begin());

        // Visit each edge exiting u
        const vector<neighbor> &neighbors = adjacencyList1[u];
        for (vector<neighbor>::const_iterator neighborIt = neighbors.begin();
             neighborIt != neighbors.end();
             neighborIt++)
        {
            int v = neighborIt->target;
            int weight = neighborIt->weight;
            int distanceThroughU = dist + weight;
            if (distanceThroughU < minDistance[v])
            {
    vertexQueue.erase(make_pair(minDistance[v], v));

    minDistance[v] = distanceThroughU;
    previous[v] = u;
    vertexQueue.insert(make_pair(minDistance[v], v));
            }
        }
    }
}

template<class keyType>
list<int> Graph2<keyType>::DijkstraGetShortestPathTo(int vertex)
{
    list<int> path;
    while (vertex != -1)
    {
        path.push_front(vertex);
        vertex = previous[vertex];
    }
    return path;
}

#endif // GRAPH2_H

/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #12 : Djikstra's & Primm's
*	CLASS      : CS1D
*	SECTION    : 5-9p T-Th
*	DUE DATE   : 3/10/2015
*******************************************************************************/

#ifndef GRAPH_H
#define	GRAPH_H

#include <list>
#include <queue>
#include <limits>
#include <QDebug>
using namespace std;
template <class vertType, class wtType>
class Graph{
public:
    class Edge;
    class Vertex;

    
        class Vertex{
            public:
                Vertex();
                vertType name;
                int index;
                bool isUsed;
        };
        
        class Edge{
            public:
                Edge(const pair<Vertex, Vertex> vertPair, const wtType& w);
            private:
                pair<Vertex, Vertex> incedentVertices;
                wtType weight;
        };
    
    Graph();
    Graph(int numVerts);
    ~Graph();
    
    bool addVertex(vertType vName);
    bool addVertex(vertType vName, int i);
    void addEdge(int from, int to, wtType w);
    void DFS(int v);
    void BFS(int v);
    void Dijkstras(int srcVert);
    int MST_Prim();
    void VertList();
    vertType* GetSortedVertList();
    vertType* GetUnsortedVertList();
    void SetVertNum(int newNum);
    int Dream(int *verts, int size);
    int Dijkstras(int srcVert, int nextVert);
    int GetTotVerts();
    void SetMatrix(int **newMatrix);
    int** GetMatrix();
    
private:
    void DFS(int v, bool visited[]);

    list<int> discoEdges;
    list<int> backEdges;
    list<int> frontEdges;
    list<int> crossEdges;

    int totVerts;
    Vertex* vertList;
    vertType* sortedArray;
    int** matrix;
    int MAX ;//= std::numeric_limits<int>::max();
};

template<class vertType,class wtType>
void Graph<vertType,wtType>::SetMatrix(int **newMatrix){
    matrix = newMatrix;
}

template<class vertType, class wtType>
int Graph<vertType,wtType>::GetTotVerts(){
    return totVerts;
}

template<class vertType, class wtType>
Graph<vertType,wtType>::Graph(){
    MAX = std::numeric_limits<int>::max();
}

template<class vertType, class wtType>
void Graph<vertType,wtType>::SetVertNum(int newNum){
    totVerts = newNum;

    vertList = new Vertex[newNum];

    matrix = new int*[totVerts];
    for(int i = 0; i < totVerts; ++i){
        matrix[i] = new int[totVerts];
    }

    for(int i = 0; i < totVerts; ++i){
        for(int j = 0; j < totVerts; ++j){
            matrix[i][j] = 0;
        }
    }
}

template<class vertType,class wtType>
int** Graph<vertType,wtType>::GetMatrix(){
    return matrix;
}

template<class vertType, class wtType>
vertType* Graph<vertType, wtType>::GetUnsortedVertList(){
    vertType* temp = new vertType[totVerts];
    for(int i = 0; i < totVerts; i++){
        temp[i] = vertList[i].name;
    }
    return temp;
}

template<class vertType, class wtType>
vertType* Graph<vertType, wtType>::GetSortedVertList(){
    return sortedArray;
}

//Vertex Constructor
template <class vertType, class wtType>
Graph<vertType, wtType>::Vertex::Vertex(){
    name = vertType();
    index = 0;
    isUsed = false;
}

//Graph Constructor
template <class vertType, class wtType>
Graph<vertType, wtType>::Graph(int numVerts){
    totVerts = numVerts;
    MAX = std::numeric_limits<int>::max();
    vertList = new Vertex[numVerts];
    
    matrix = new int*[totVerts];
    for(int i = 0; i < totVerts; ++i){
        matrix[i] = new int[totVerts];
    }
    
    for(int i = 0; i < totVerts; ++i){
        for(int j = 0; j < totVerts; ++j){
            matrix[i][j] = 0;
        }
    }
}

//Graph Destructor
template <class vertType, class wtType>
Graph<vertType, wtType>::~Graph(){
    
//    //Deleting vert list
//    delete [] vertList;
    
//    //Deleting matrix
//    for(int i = 0; i < totVerts; ++i){
//        delete [] matrix[i];
//    }
//    delete [] matrix;
}

template <class vertType, class wtType>
bool Graph<vertType, wtType>::addVertex(vertType vName){
    int i = 0;
    bool added = false;
    while(!added && i < totVerts){
        
        if(vertList[i].isUsed == false){
            vertList[i].index = i;
            vertList[i].name = vName;
            vertList[i].isUsed = true;
            
            added = true;
        }
        
        i++;
    }
    
    if(!added){
        //cout << "Vertex: " << vName << "not added\n";
    }
    
    return added;
}

template <class vertType, class wtType>
bool Graph<vertType, wtType>::addVertex(vertType vName, int i){
    bool added = false;
    
    if(i < totVerts){
        vertList[i].index = i;
        vertList[i].name = vName;
        vertList[i].isUsed = true;
        
        added = true;
    }
    else{
       // cout << "Vertex: " << vName << "not added\n";
    }
    
    return added;
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::VertList(){
    for(int i = 0; i < totVerts; i++){
       // cout << i << ". " << vertList[i].name;
    }
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::addEdge(int from, int to, wtType w){
    if(vertList[from].isUsed && vertList[to].isUsed){
        matrix[from][to] = w;
        matrix[to][from] = w; //This Link makes it undirected
//        cout << "Added Edge: "
//             << vertList[from].name
//             //<< " -- [" << w << "] --> "
//             << " <-- [" << w << "] --> "
//             << vertList[to].name
//             << endl;
    }
    else{
        //cout << "vertices not found, edge not added" << endl;
    }
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::DFS(int v){
    bool visited[totVerts];
    queue<int> edges;
    int smallest = MAX;
    int nextVert;
    
    for(int c = 0; c < totVerts; c++){
        visited[c] = false;
    }
    
    if(v < totVerts){
       // cout << "DFS Start: " << endl;
        visited[v] = true;
       // cout << vertList[v].name << endl;
        
        for(int k = 0; k < totVerts; k++){
            if( matrix[v][k] > 0 && (!visited[k]) ){
                edges.push(k);
//                cout << "Possible Vertex: " << k << endl;
            }
        }
        //finds smallest edge
        if(!edges.empty()){
    		while(!edges.empty()){
    			int contender = matrix[v][edges.front()];
//    			cout << "vertex: " << edges.front() << " ";
//    			cout << contender << " vs. " << smallest << endl;

    			if(contender < smallest){
    				smallest = contender;
    				nextVert = edges.front();
    			}
    			edges.pop();
    		}
        }
        //Handles if no possible
        else{
        	bool found = false;
        	int j = 0;
        	while(!found && j < totVerts){
				if(visited[j] == false){
					nextVert = j;
					found = true;
				}
				j++;
			}
        }
        DFS(nextVert, visited);
    }
    else{
        //cout << "ERROR: OUT OF BOUNDS";
    }

}

template <class vertType, class wtType>
void Graph<vertType, wtType>::DFS(int v, bool visited[]){
    queue<int> edges;
    int smallest = MAX;
    int nextVert;
    
    visited[v] = true;
    //cout << vertList[v].name << endl;

    for(int k = 0; k < totVerts; k++){
        if( matrix[v][k] > 0 && (!visited[k]) ){
            edges.push(k);
//            cout << "Possible Vertex: " << k << endl;
        }
    }
    //finds smallest edge
    if(!edges.empty()){
		while(!edges.empty()){
			int contender = matrix[v][edges.front()];
//			cout << "vertex: " << edges.front() << " ";
//			cout << contender << " vs. " << smallest << endl;

			if(contender < smallest){
				smallest = contender;
				nextVert = edges.front();
			}
			edges.pop();
		}
	    DFS(nextVert, visited);
    }
    //Handles if no possible
    else{
    	bool found = false;
    	int j = 0;
    	while(!found && j < totVerts){
    		if(visited[j] == false){
    			nextVert = j;
    			found = true;
    		}
    		j++;
    	}
    	if(found == true){
//    		cout << "Vertex not found: " << nextVert << endl;
    	    DFS(nextVert, visited);
    	}
    }
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::BFS(int v){
    bool visited[totVerts];
    queue<int> travelQ;

    for(int c = 0; c < totVerts; c++){
        visited[c] = false;
    }

    visited[v] = true;
    travelQ.push(v);

    while(!travelQ.empty()){

    	v = travelQ.front();
    	travelQ.pop();
    //	cout << vertList[v].name << endl;

    	for (int i = 0; i < totVerts; i++ ) {
    			if (matrix[v][i] > 0) {
    				if (!visited[i]) {
    						visited[i] = true;
    						travelQ.push(i);
    				}
    			}
    		}
    }
}


template <class vertType, class wtType>
void Graph<vertType, wtType>::Dijkstras(int srcVert){
	int distAr[totVerts];
	bool SPTAr[totVerts];

	for(int i = 0; i < totVerts; i++){
		distAr[i] = MAX;
		SPTAr[i] = false;
	}

	distAr[srcVert] = 0;

	for(int count = 0; count <totVerts - 1; count++){
		int minNum = MAX;
		int minDex = 0;

		for(int i = 0; i < totVerts; i++){
			if( SPTAr[i] == false &&
			    distAr[i] <= minNum){
				minNum = distAr[i];
				minDex = i;
			}
		}
		SPTAr[minDex] = true;

		for(int v = 0; v < totVerts; v++){
			if(!SPTAr[v] && matrix[minDex][v] &&
			   distAr[minDex] != MAX &&
               distAr[minDex]+matrix[minDex][v] < distAr[v]){
				distAr[v] = distAr[minDex]+matrix[minDex][v];
			}
		}
	}

    //insertion sort
    int key,i;
    Vertex temp;
    for(int j = 1; j < totVerts; j++)    // Start with 1 (not 0)
   {
          key = distAr[j];
          temp = vertList[j];
          for(i = j - 1; (i >= 0) && (distAr[i] > key); i--)   // Smaller values move up
         {
                distAr[i+1] = distAr[i];
                vertList[i+1] = vertList[i];
         }
        distAr[i+1] = key;    //Put key into its proper location
        vertList[i+1] = temp;
    }

    sortedArray = new vertType [totVerts];

    for(int j = 0;j<totVerts;j++){
        sortedArray[j] = vertList[j].name;
    }
}

template <class vertType, class wtType>
int Graph<vertType, wtType>::MST_Prim(){
	int MST[totVerts];
	int keyValues[totVerts];
	bool used[totVerts];

	//Initialization
	for(int i = 0; i < totVerts; i++){
		keyValues[i] = MAX;
		used[i] = false;
	}

	keyValues[0] = 0;
	MST[0] = -1;

	for( int count = 0; count < totVerts -1; count++){
		int minNum = MAX;
		int minDex = 0;

		for(int i = 0; i < totVerts; i++){
			if( used[i] == false &&
				keyValues[i] <= minNum){
				minNum = keyValues[i];
				minDex = i;
			}
		}
		used[minDex] = true;

		for(int v = 0; v < totVerts; v++){
			if(matrix[minDex][v] &&
			   used[v] == false  &&
			   matrix[minDex][v] < keyValues[v]){
				MST[v] = minDex;
				keyValues[v] = matrix[minDex][v];
			}
		}
	}

    int returningThis = 0;

	for(int v = 1; v < totVerts; v++){
        //cout << vertList[MST[v]].name << " --[" << matrix[v][MST[v]] << "]-- "
            // << vertList[v].name << endl;
        returningThis+=matrix[v][MST[v]];
        qDebug() << matrix[v][MST[v]];
	}
    return returningThis;
}

template <class vertType, class wtType>
int Graph<vertType, wtType>::Dijkstras(int srcVert, int nextVert){
 int distAr[totVerts];
 bool SPTAr[totVerts];

 for(int i = 0; i < totVerts; i++){
  distAr[i] = MAX;
  SPTAr[i] = false;
 }

 distAr[srcVert] = 0;

 for(int count = 0; count <totVerts - 1; count++){
  int minNum = MAX;
  int minDex = 0;

  for(int i = 0; i < totVerts; i++){
   if( SPTAr[i] == false &&
       distAr[i] <= minNum){
    minNum = distAr[i];
    minDex = i;
   }
  }
  SPTAr[minDex] = true;

  for(int v = 0; v < totVerts; v++){
   if(!SPTAr[v] && matrix[minDex][v] &&
      distAr[minDex] != MAX &&
      distAr[minDex]+matrix[minDex][v] < distAr[v]){
    distAr[v] = distAr[minDex]+matrix[minDex][v];
   }
  }
 }

 return distAr[nextVert];
}

template <class vertType, class wtType>
int Graph<vertType, wtType>::Dream(int *verts, int size)
{
 int totDistance;
 int prevVert;
 int nextVert;
 for(int i = 1; i < size; i++){
  prevVert = verts[i-1];
  nextVert = verts[i];
  totDistance += Dijkstras(prevVert, nextVert);
 }
 return totDistance;
}

#endif	/* GRAPH_H */


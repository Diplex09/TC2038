/*                                                  */
/*  Actividad Integradora 2 - Servicios de internet */
/*                                                  */
/*  Diego Velazquez Moreno - A01632240              */
/*  Aldo Alejandro Degollado Padilla - A01638391    */
/*                                                  */

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <queue>
#include <limits> 
using namespace std;

#define INF 9999


//minDijstra sirve para buscar el vertice que aun no este visitado esperando conseguir una distancia minima , la complejidad es de O(n)
int minDijstra(vector<int> &dist,  vector<bool>visited){
  int distSize = dist.size();
  int minConection = INF;
  int vertex = 0;

  for(int i = 0;i < distSize ; i++){
    if(dist[i] <= minConection && visited[i] == false){
      minConection = dist[i];
      vertex = i;
    }
  }
  return vertex;
} 


//dijkstra te permite encontrar el camino mas corto entre un nodo a otro, la complejidad es de O(V^2+E)
void dijkstra(vector<vector<int> > &adjList, int source){


  int adjListSize = adjList.size();
  vector<bool> visited (adjListSize, false);
  vector<int> dist (adjListSize, INF);
  int min = 0;
  
  dist[source]=0;

  for(int i = 0; i < adjListSize; i++){

    min = minDijstra(dist,visited);
    visited[min] = true;

    for(int j = 0; j < adjListSize; j++){

      if(!visited[j]  && adjList[min][j] != -1 && dist[min] != INF && dist[min]+adjList[min][j]<dist[j]&& adjList[min][j]){

        dist[j] = dist[min] + adjList[min][j];

      }
    }
    
    

  }
  for( int pr = 0; pr < adjListSize;pr++){
    if(dist[pr]== INF){
          cout<<"node "<< source + 1<<" to node "<<pr + 1 <<" is "<<-1<<endl;
        }
    else{
    cout<<"node "<< source + 1<<" to node "<<pr + 1 <<" is "<<dist[pr]<<endl;
    }
  }
 
}


//Algoritmo Fordfoulkson

bool bfs(vector<vector<int>> &auxGraph,int s, int t, int parent[]){
  int graphSize = auxGraph.size();
  bool visited[graphSize];
  memset(visited, 0 , sizeof(visited));

  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for (int v = 0; v<graphSize;v++){
      if (visited[v] == false && auxGraph[u][v]>0){
        if (v == t){
          parent[v] = u;
          visited[v] = true;
        }
      }
    }
  }
  return false;

}
int fourdFulkerson(vector<vector<int>> &graph, int s, int t){
  int graphSize = graph.size();
  int u = 0;
  int v = 0;
  int parent[graphSize];
  int max_flow = 0;
  vector<vector<int>> auxGraph(graphSize, vector<int>(graphSize,0)) ;
  while (bfs(auxGraph,s,t,parent)){
    int path_flow = INF;
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, auxGraph[u][v]);
    }
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      auxGraph[u][v] -= path_flow;
      auxGraph[v][u] += path_flow;
    }
    return max_flow;

  }


}


int main() {
  cout << "\n |-|-|      Dijstra & Floyd      |-|-|" << endl;
  cout << "By: Aldo Degollado, Diego Velazquez" << endl;
  int sizeMatrix;

  // Aqui cambia el documento que quieres probar
  ifstream fin("Case1.txt");
  vector<int> data;
    
    int element ;
    while (fin >> element)
    {
        data.push_back(element);
    }
    

    sizeMatrix=data[0];// First value of the data that will define the size
    data.erase(data.begin()); // Erase the first value of the data
    vector<vector<int> > matrix(sizeMatrix ,vector<int>(sizeMatrix, -1));
    int mMatrixSize = matrix.size();
    int dataSize = data.size();
    int counter = 0;
    
    for(int i = 0; i<mMatrixSize ; i++){
        for(int j = 0; j<mMatrixSize ; j++){
            matrix[i][j]= data[counter];
            
            counter = counter +1;

        }
    }



  cout<<"Dijkstra :"<<endl ;
  for(int l = 0; l < sizeMatrix; l++){

    dijkstra(matrix,l);
  }
  


 
  
    return 0;
}

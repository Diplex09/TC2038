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

#define INF 999

vector<char> alphabeth = {'a','b','c','d','e','f',
		'g','h','i','j','k','l','m','n','o','p',
		'q','r','s','t','u','v','w','x','y','z'};

//minDijstra sirve para buscar el vertice que aun no este visitado esperando conseguir una distancia minima , la complejidad es de O(n)
int minDijstra(vector<int> &dist, vector<bool>visited)
{
  int distSize = dist.size();
  int minConection = INF;
  int vertex = 0;

  for(int i = 0; i < distSize; i++)
  {
    if(dist[i] <= minConection && visited[i] == false)
    {
      minConection = dist[i];
      vertex = i;
    }
  }
  return vertex;
} 
//La funcion printPath sirve para imprimir los camino de la funcionde dijkstra, es llamada por la funcion display. Se llama de manera recursiva hasta conseguir el camino. completoComplejidad O(n).
void printPath(vector<int> &par, int source)
{    

  if (par[source] == - 1)
  {
    return;
  }
  
  printPath(par, par[source]);
  
  cout << alphabeth[source] << " ";
}

// La funcion display te sirve para llamar la funcion print path, ademas de que te imprime el camino a cada nodo y la distancia, no te regresa nada. Complejidad O(n).
void display(vector<int> &dist,int adjListSize,int source ,vector<int> &par)
{
  cout<<"Pueblos\t\t Distancia\tRecorrido";
  
   for(int i= 1; i<adjListSize; i++)
   {
    printf("\n%c -> %c \t\t %d\t\t%c ", alphabeth[source], alphabeth[i], dist[i], alphabeth[source]);
    printPath(par, i);
   }
}

//dijkstra te permite encontrar el camino mas corto entre un nodo a otro, la complejidad es de O(V^2+E)
void dijkstra(vector<vector<int> > &adjList, int source)
{
  int adjListSize = adjList.size();
  vector<bool> visited (adjListSize, false);
  vector<int> dist (adjListSize, INF);
  vector<int> par (adjListSize);
  dist[source]= 0;
  par[source] = -1;
  int min = 0;

  for(int i = 0; i < adjListSize; i++)
  {
    min = minDijstra(dist,visited);
    visited[min] = true;

    for(int j = 0; j < adjListSize; j++)
    {
      if(!visited[j] && adjList[min][j] != -1 && dist[min] != INF && dist[min] + adjList[min][j] < dist[j] && adjList[min][j])
      {
        par[j] = min;
        dist[j] = dist[min] + adjList[min][j];

      }
    }
  }

  display(dist, adjListSize, source,par);

  return;
}

// least sirve para identificar el cual es el camino mas corto hacia los distintos vectores. complejidad de O(n).
int least(vector<vector<int> >&matrix, vector<int> &visited,int cost ,int city)
{
  int matrixSize = matrix.size();
  int i, nc = INF;
  int min = INF, kmin;
  
  for(i=0; i < matrixSize; i++)
  {
    if((matrix[city][i] != 0) && (visited[i] == 0))
    {
      if(matrix[city][i] + matrix[i][city] < min)
      {
        min = matrix[i][city] + matrix[city][i];
        kmin = matrix[city][i];
        nc = i;
      }
    }
  }
  
  if(min != INF)
  {
    cost += kmin;
  }
  
  return nc;
}
// La funcion tsp sirve para conocer el camino del viajero su complejidad es de O(n2^n), es un algoritmo dinamico, va a buscar siempre el nodo con menor distancia y llama la funcion de least para encontrar el menor y tsp para seguir verificando cada vector
void tsp(vector<vector<int> >&matrix, vector<int> &visited,int cost ,int city)
{
  int ncity;

  visited[city] = 1;
  
  cout << alphabeth[city] << " --> ";
  ncity = least(matrix, visited, cost, city);
  
  if(ncity == INF)
  {
    ncity=0;
    cout << alphabeth[ncity];
    cost += matrix[city][ncity];
    
    return;
  }
  
  tsp(matrix, visited, cost, ncity);
}

//La función bfs hace una busqueda de anchura para apoyar a la funcion de ford, regresa un valor entero que sera el minimo flujo O(V+E).
int bfs(int source, int sink, vector<int>& parent, vector<vector<int> >& residualGraph) 
{
  fill(parent.begin(), parent.end(), -1);
  int V = residualGraph.size();
  parent[source] = -2;
  queue<pair<int, int> > q;
  q.push({source, INF});

  while (!q.empty()) 
  {
    int u = q.front().first;
    int capacity = q.front().second;
    q.pop();

    for (int av=0; av < V; av++) 
    {
      if (u != av && parent[av] == -1 && residualGraph[u][av] != 0)
      {
        parent[av] = u;
        int min_cap = min(capacity, residualGraph[u][av]);

        if (av == sink)
        {
          return min_cap;
        }

        q.push({av, min_cap});
      }
    }
  }

  return 0;
}
//La funcion fordFulkserson sirve para conseguir el flujo maximo de la grafo que es ingresado  O(flujo máximo  * E). Dentro de la funcion se llama a bfs 
int fordFulkerson(vector<vector<int> >& graph, int source, int sink) 
{
  vector<int> parent(graph.size(), -1);
  vector<vector<int> > residualGraph = graph;
  int min_cap = 0, max_flow = 0;

  while ((min_cap = bfs(source, sink, parent, residualGraph)))
  {
    max_flow += min_cap;
    int u = sink;

    while (u != source) 
    {
      int v = parent[u];
      residualGraph[u][v] += min_cap;
      residualGraph[v][u] -= min_cap;
      u = v;
    }
  }

  return max_flow;
}

int main() {
  cout << "\n |-|-|-|-|-| Act Integradora 2 |-|-|-|-|-|" << endl;
  cout << "By: Aldo Degollado, Diego Velazquez" << endl;
  int sizeMatrix;

  // Aqui cambia el documento que quieres probar
  ifstream fin("Case1.txt");
  vector<int> data;
    
  int element;

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
  
  for(int i = 0; i<mMatrixSize ; i++)
  {
    for(int j = 0; j<mMatrixSize ; j++)
    {
      matrix[i][j] = data[counter];
      counter = counter +1;
    }
  }
  
  vector<vector<int> > secondMatrix(sizeMatrix ,vector<int>(sizeMatrix, -1));
  int countersecond = 16;

  for(int i = 0; i<mMatrixSize ; i++)
  {
    for(int j = 0; j<mMatrixSize ; j++)
    {
      secondMatrix[i][j]= data[counter];
      counter = counter +1;
    }
  }

  vector<int> visitedTSP(sizeMatrix);

  cout<<"\n1.- Dijkstra"<<endl;
  dijkstra(matrix, 0);
  cout<<endl;

  cout<<"\n2.- TSP Dinamica"<<endl;
  tsp(matrix,visitedTSP, 0, 0);
  cout<<endl;

  cout<<"\n3.- Flujo Maximo"<<endl;
  cout<<fordFulkerson(secondMatrix, 0, sizeMatrix-1);

  return 0;
}
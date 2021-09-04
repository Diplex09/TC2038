//
//  main.cpp
//  BackTracking
//
//  Created by Aldo Degollado Diego Velázquez on 03/09/21.
//


#include <stdio.h>
#include <iostream>
using namespace std;


#include <iostream>
#include <vector>

// Backtracking
bool solveMazeBacktracking(int row, int column, vector<vector<bool>> &v);
bool solveMaze(int row, int column, vector<vector<bool>> &v, int x, int y, vector<vector<bool>> &s);





// Función para comprobar que si x,y es un índice válido
//
bool isValid(int row, int column, vector<vector<bool>> &maze, int x, int y){
    if (x >= 0 && x < row && y >= 0 && y < column && maze[x][y] == 1){
        return true;
    }
 
    return false;
}


// Regresa true en caso de que exista un camino posible,
// caso contrario regresa false
bool solveMazeBacktracking(int row, int column, vector<vector<bool>> &maze) {
    
    vector<vector<bool>> visited(row,vector<bool>(column,false));
    

    if (solveMaze(row, column, maze, 0, 0, visited) == false) {
        cout << "Don't have a solution" << endl;
        return false;
    }
 
    
    cout << "Solucion" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }

    return true;
}
 
// Función recursiva para resolver el problema del laberinto
bool solveMaze(int row, int column, vector<vector<bool>> &maze, int x, int y, vector<vector<bool>> &visited)
{
    // Si se llegó al final regresa true
    if (x == row - 1 && y == column - 1 && maze[x][y] == 1) {
        visited[x][y] = 1;
        return true;
    }
 
    // Comprueba si maze[x][y] es válido
    if (isValid(row, column, maze, x, y) == true) {
        // Comprueba si la posición actual ya forma parte
        // de la solución
        if (visited[x][y] == 1){
            return false;
        }
       
        // Marca la posición como parte de la solución
        visited[x][y] = 1;
        

        // Se mueve hacia abajo en la posición y
        if (solveMaze(row, column, maze, x, y + 1, visited)== true) {
            return true;
        }
        // Si moverse en la posición y no da resultado
        // Se avanza en la posición x
        if (solveMaze(row, column, maze, x + 1, y, visited) == true){
            return true;
        }
 

       
        // Si moverse en la posición y no da resultado
        // Se regresa en la posición x
        if (solveMaze(row, column, maze, x - 1, y, visited) == true) {
            return true;
        }
 
        // Si regresar en la posición x no da resultado
        // Se mueve hacia arriba en la posición y
        if (solveMaze(row, column, maze, x, y - 1, visited) == true) {
            return true;
        }
 

        // Si ninguno de los anteriores movimientos
        // da resultado, se desmarca la posición actual
        // como parte de la solución
        visited[x][y] = 0;
        return false;
    }
 
    return false;
}

int main() {
    int row, column;

    cout << "Type row and columns: " << ::endl;
    cin >> row;
    cin >> column;

    vector<vector<bool>> maze;
    
    
    bool path;
    cout << "Type the maze " << endl;
    for (int i = 0; i < row; i++) {
        int j = 0;
        vector<bool> line;
        while(j < column){
            cin >> path;
            line.push_back(path);
            j++;
            if (cin.peek() == '\n'){
                break;
            }
        }
        maze.push_back(line);
    }
    cout << "Backtracking" << endl;
    solveMazeBacktracking(row, column, maze);

    return 0;
}


    
    


    


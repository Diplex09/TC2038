//
//  main.cpp
//  Maze
//
//  Created by Diego Velázquez on 02/09/21.
// backtraccking
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool solveMaze(vector<vector<int>>maze,int x,int y,vector<vector<int>>visited){
    return true;
}


bool mazeSolver(vector<vector<int>>maze){
    long sizeRows=maze.size();
    long sizeColumns=maze[0].size();
    vector<vector<int>> visited(sizeRows,vector<int>(sizeColumns,0));
    
    solveMaze(maze,0,0,visited);
    
    
    
    cout<<sizeRows<<sizeColumns;
    
    
    
    return true;
}



int main()
{

    vector<vector<int>> maze;
    maze={
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {0,1,1,1},
        {0,1,1,1}
    };
    mazeSolver(maze);
    
    cout<<"hola mundo";
    
    return 0;
}


    
    


    


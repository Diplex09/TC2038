//
//  main.cpp
//  Maze
//
//  Created by Diego Velázquez on 02/09/21.
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;




bool mazeSolver(vector<vector<int>>maze){
    long sizeRows=maze.size();
    long sizeColumns=maze[0].size();
    vector<vector<int>> visited(sizeRows,vector<int>(sizeColumns,0));
    
    
    
    
    
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


    
    


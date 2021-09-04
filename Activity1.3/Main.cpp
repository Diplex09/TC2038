/*                                                                                    */
/*  Actividad 1.3 - Implimentación de algoritmo backtracking y branch and bound       */
/*                                                                                    */
/*  Diego Velázquez Moreno - A01632240                                                */
/*  Aldo Alejandro Degollado Padilla - A01638391                                      */
/*                                                                                    */


#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Prints the solution for the maze founded by the algorithm.
void printMazeSolution(vector<vector<int>>& mazeSolution)
{
    for(int i = 0; i < mazeSolution.size(); i++)
    {
        for(int j = 0; j < mazeSolution[0].size(); j++)
        {
            cout << mazeSolution[i][j] << " ";
        }
        cout << endl;
    }
}

// This function verifies if the given coordinate it's inside the maze and it's accesible.
bool isAccesible(vector<vector<int>> maze, int x, int y)
{
    if(x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y])
    {
        return true;
    }
    return false;
}

// Recursive function that goes through the maze until it finds a solution or exhausts all positionsibilities.
bool solveMazeBacktrackRecursive(vector<vector<int>> maze, vector<vector<int>>& mazeSolution, int x, int y)
{
    // Verifies if the end of the maze was reached.
    if(x == maze.size() - 1 && y == maze[0].size() - 1)
    {
        mazeSolution[x][y] = 1;
        return true;
    }

    // Verifies if the current positionition in the maze is part of the solution.
    if(isAccesible(maze, x, y)) 
    {
        if(mazeSolution[x][y]) 
        {
            return false;
        }

        mazeSolution[x][y] = 1;
        
        if(solveMazeBacktrackRecursive(maze, mazeSolution, x + 1, y))
        {
            return true;
        }

        if(solveMazeBacktrackRecursive(maze, mazeSolution, x, y + 1))
        {
            return true;
        }

        if(solveMazeBacktrackRecursive(maze, mazeSolution, x - 1, y))
        {
            return true;
        }

        if(solveMazeBacktrackRecursive(maze, mazeSolution, x, y - 1))
        {
            return true;
        }

        mazeSolution[x][y] = 0;
        return false;
    }
    return false;
}

// This function initializes the process of searching for a solution for the maze using backtracking method.
void solveMazeBacktrack(vector<vector<int>> maze, vector<vector<int>>& mazeSolution)
{
    int m = maze.size();
    int n = maze[0].size();

    if(!maze[0][0])
    {
        cout << "The maze has no entrance." << endl;
        return;
    }

    if(!maze[m-1][n-1])
    {
        cout << "The maze has no exit." << endl;
        return;
    }

    if(!solveMazeBacktrackRecursive(maze, mazeSolution, 0, 0))
    {
        cout << "The maze has no solution." << endl;
        return;
    }
}

// This function uses the branch and bound method (BFS algorithm) to find a solution for the maze.
void solveMazeBranchBound(vector<vector<int>> maze, vector<vector<int>>& mazeSolution)
{
    int x = maze.size();
    int y = maze[0].size();

    if(!maze[0][0])
    {
        cout << "The maze has no entrance." << endl;
        return;
    }

    if(!maze[x-1][y-1])
    {
        cout << "The maze has no exit." << endl;
        return;
    }

    vector<vector<bool>> current(x, vector<bool>(y, false));
    queue<vector<int>> mazeQueue;

    int xNum[] = {1, 0, 0 , -1};
    int yNum[] = {0, 1, -1, 0};
    
    int row = 0;
    int col = 0;
    int stride = 0;
    std::vector<int> position = {row, col, stride};

    mazeQueue.push(position);
    current[row][col] = true;

    while(!mazeQueue.empty())
    {
        position = mazeQueue.front();

        if(position[2] < stride)
        {
            row = position[0];
            col = position[1];
            stride = position[2];
        }

        if(row == maze.size() - 1 && col == maze[0].size()-1)
        {
            mazeSolution[row][col] = 1;
            return;
        }

        mazeQueue.pop();

        mazeSolution[row][col] = 1;

        for(int i = 0; i < maze.size(); i++)
        {
            int newRow = row + xNum[i];
            int newColumn = col + yNum[i];

            if(isAccesible(maze, newRow, newColumn) && !current[newRow][newColumn])
            {
                current[newRow][newColumn] = true;
                mazeQueue.push({newRow, newColumn, stride++});
            }
        }
    }
    cout << "The maze has no solution." << endl;
}

int main()
{
    cout << "\n |-|-|      BACKTRACKING AND BRANCH AND BOUND IMPLEMENTATION      |-|-|" << endl;
    cout << "By: Aldo Degollado, Diego Velazquez\n" << endl;

    int m;
    int n;

    vector<vector<int>> maze;

    cout << "Type the amount of rows and columns: " << endl;
    cin >> m;
    cin >> n;

    cout << "\nInsert the maze: " << endl;
    for(int i = 0; i < m; i++)
    {
        vector<int> line;
        for(int j = 0; j < n; j++)
        {
            int o;
            cin >> o;
            line.push_back(o);
        }
        maze.push_back(line);
    }

    cout << "\nBacktracking aproach: " << endl;
    vector<vector<int>> backtracking(m, vector<int>(n, 0));
    solveMazeBacktrack(maze, backtracking);
    printMazeSolution(backtracking);

    cout << endl;

    cout << "Branch and bound aproach: " << endl;
    vector<vector<int>> branchAndBound(m, vector<int>(n, 0));
    solveMazeBranchBound(maze, branchAndBound);
    printMazeSolution(branchAndBound);

    return 0;
}
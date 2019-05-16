//
// Created by kevin on 28/04/19.
//

#include <cstdio>
#include "Pathfinding.h"
#include "PathNode.h"
#include "PathList.h"
#include <stack>
#include <cstring>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

Pathfinding* Pathfinding::pathfinding = nullptr;

Pathfinding* Pathfinding::getInstance() {
    if (!pathfinding) {
        pathfinding = new Pathfinding();
        pathfinding->initializeIDS();
    }
    return pathfinding;
}

bool Pathfinding::backTrack11x19(int sRow, int sColumn, int matrix[11][19]){
    //Base Case 1: Attempted move is outside of grid
    if(sRow < 0 || sRow > 10 || sColumn < 0 || sColumn > 18){
        return false;
    }

    //Base Case 2: End of Maze
    else if(matrix[sRow][sColumn] == 1 && sRow == 6 && sColumn == 18){
        solution11x19[sRow][sColumn] = 1;
        cout << toString11x19() << endl;
        return true;
    }

    //Base Case 3: Attempted move is a wall of the maze
    else if(matrix[sRow][sColumn] == 0){
        return false;
    }

    //Base Case 4: Attempted move is a previously used move
    else if(visited11x19[sRow][sColumn] == 1){
        return false;
    }

    else{
        solution11x19[sRow][sColumn] = 1; //Mark cell as part of the path
        visited11x19[sRow][sColumn] = 1;
        int bestPath = 0;
        if (sRow < 6){
            bestPath = 1;
        }
        if (sRow > 6){
            bestPath = 2;
        }
        if (sColumn < 18){
            bestPath = 3;
        }

        //Move up
        if (bestPath == 2 && backTrack11x19(sRow - 1, sColumn, matrix)){
            return true;
        }

        //Move down
        else if (bestPath == 1 && backTrack11x19(sRow + 1, sColumn, matrix)){
            return true;
        }

        //Move right
        else if (bestPath == 3 && backTrack11x19(sRow, sColumn + 1, matrix)){
            return true;
        }
        else{
            //Move up
            if (backTrack11x19(sRow - 1, sColumn, matrix)){
                return true;
            }
                //Move down
            else if (backTrack11x19(sRow + 1, sColumn, matrix)){
                return true;
            }
                //Move right
            else if (backTrack11x19(sRow, sColumn + 1, matrix)){
                return true;
            }
                //Move left
            else if (backTrack11x19(sRow, sColumn - 1, matrix)){
                return true;
            }
            else{
                solution11x19[sRow][sColumn] = 0; //backtracking
                return false;
            }
        }
    }
}

bool Pathfinding::backTrack8x17(int sRow, int sColumn, int matrix[8][17]){
    //Base Case 1: Attempted move is outside of grid
    if(sRow < 0 || sRow > 7 || sColumn < 0 || sColumn > 16){
        return false;
    }

        //Base Case 2: End of Maze
    else if(matrix[sRow][sColumn] == 1 && sRow == 3 && sColumn == 16){
        solution8x17[sRow][sColumn] = 1;
        cout << toString8x17() << endl;
        return true;
    }

        //Base Case 3: Attempted move is a wall of the maze
    else if(matrix[sRow][sColumn] == 0){
        return false;
    }

        //Base Case 4: Attempted move is a previously used move
    else if(visited8x17[sRow][sColumn] == 1){
        return false;
    }

    else{
        solution8x17[sRow][sColumn] = 1; //Mark cell as part of the path
        visited8x17[sRow][sColumn] = 1;
        int bestPath = 0;
        if (sRow < 3){
            bestPath = 1;
        }
        if (sRow > 3){
            bestPath = 2;
        }
        if (sColumn < 16){
            bestPath = 3;
        }

        //Move up
        if (bestPath == 2 && backTrack8x17(sRow - 1, sColumn, matrix)){
            return true;
        }

            //Move down
        else if (bestPath == 1 && backTrack8x17(sRow + 1, sColumn, matrix)){
            return true;
        }

            //Move right
        else if (bestPath == 3 && backTrack8x17(sRow, sColumn + 1, matrix)){
            return true;
        }
        else{
            //Move up
            if (backTrack8x17(sRow - 1, sColumn, matrix)){
                return true;
            }
                //Move down
            else if (backTrack8x17(sRow + 1, sColumn, matrix)){
                return true;
            }
                //Move right
            else if (backTrack8x17(sRow, sColumn + 1, matrix)){
                return true;
            }
                //Move left
            else if (backTrack8x17(sRow, sColumn - 1, matrix)){
                return true;
            }
            else{
                solution8x17[sRow][sColumn] = 0; //backtracking
                return false;
            }
        }
    }
}

string Pathfinding::toString11x19(){
    string result = "Solution: \n";
    for(int row = 0; row < 11; row++){
        for(int col = 0; col < 19; col++){
            result += to_string(solution11x19[row][col]) + " ";
        }
        result += "\n";
    }
    return result;
}

string Pathfinding::toString8x17() {
    string result = "Solution: \n";
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 17; col++){
            result += to_string(solution8x17[row][col]) + " ";
        }
        result += "\n";
    }
    return result;
}

void Pathfinding::initializeIDS() {
    int id = 0;
    for(int i = 0; i < 11; i++){
        for (int j = 0; j < 19; j++){
            ids11x19[i][j] = id;
            id++;
        }
    }
    id = 0;
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 17; j++){
            ids8x17[i][j] = id;
            id++;
        }
    }
}
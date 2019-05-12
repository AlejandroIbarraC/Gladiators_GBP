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
    }
    return pathfinding;
}

bool Pathfinding::backTrack11x19(int sRow, int sColumn, int matrix[11][19]){
    //Base Case 1: Attempted move is outside of grid
    if(sRow < 0 || sRow > 10 || sColumn < 0 || sColumn > 18){
        return false;
    }

    //Base Case 2: End of Maze
    if(matrix[sRow][sColumn] == 1 && sRow == 6 && sColumn == 18){
        solution11x19[sRow][sColumn] = 1;
        cout << toString11x19() << endl;
        return true;
    }

    //Base Case 3: Attempted move is a wall of the maze
    if(matrix[sRow][sColumn] == 0){
        return false;
    }

    //Base Case 4: Attempted move is a previously used move
    if(solution11x19[sRow][sColumn] == 1){
        return false;
    }

    solution11x19[sRow][sColumn] = 1; //Mark cell as part of the path

    //Move right
    if (backTrack11x19(sRow, sColumn + 1, matrix)){
        return true;
    }
    //Move down
    if (backTrack11x19(sRow + 1, sColumn, matrix)){
        return true;
    }
    //Move left
    if (backTrack11x19(sRow, sColumn - 1, matrix)){
        return true;
    }
    //Move up
    if (backTrack11x19(sRow - 1, sColumn, matrix)){
        return true;
    }
    solution11x19[sRow][sColumn] = 0; //backtracking
    return false;
}

bool Pathfinding::backTrack8x17(int sRow, int sColumn, int matrix[8][17]){
    //Base Case 1: Attempted move is outside of grid
    if(sRow < 0 || sRow > 7 || sColumn < 0 || sColumn > 16){
        return false;
    }

    //Base Case 2: End of Maze
    if(matrix[sRow][sColumn] == 1 && sRow == 3 && sColumn == 16){
        solution8x17[sRow][sColumn] = 1;
        cout << toString8x17() << endl;
        return true;
    }

    //Base Case 3: Attempted move is a wall of the maze
    if(matrix[sRow][sColumn] == 0){
        return false;
    }

    //Base Case 4: Attempted move is a previously used move
    if(solution8x17[sRow][sColumn] == 1){
        return false;
    }

    solution8x17[sRow][sColumn] = 1; //Mark cell as part of the path

    //Move right
    if (backTrack8x17(sRow, sColumn + 1, matrix)){
        return true;
    }
    //Move down
    if (backTrack8x17(sRow + 1, sColumn, matrix)){
        return true;
    }
    //Move left
    if (backTrack8x17(sRow, sColumn - 1, matrix)){
        return true;
    }
    //Move up
    if (backTrack8x17(sRow - 1, sColumn, matrix)){
        return true;
    }
    solution8x17[sRow][sColumn] = 0; //backtracking
    return false;
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
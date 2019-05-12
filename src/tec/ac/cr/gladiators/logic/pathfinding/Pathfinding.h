//
// Created by kevin on 28/04/19.
//

#ifndef GLADIATORS_GBP_PATHFINDING_H
#define GLADIATORS_GBP_PATHFINDING_H

#include <string>

using namespace std;

class Pathfinding {

public:

    static Pathfinding* getInstance();

    bool backTrack11x19(int sRow, int sColumn, int matrix[11][19]);
    bool backTrack8x17(int sRow, int sColumn, int matrix[8][17]);

private:

    Pathfinding() = default;
    Pathfinding(Pathfinding const&)= default;
    Pathfinding& operator = (Pathfinding const&) = default;

    static Pathfinding* pathfinding;
    int solution11x19[11][19];
    int solution8x17[8][17];
    int ROW;
    int COL;

    string toString11x19();
    string toString8x17();

};


#endif //GLADIATORS_GBP_PATHFINDING_H

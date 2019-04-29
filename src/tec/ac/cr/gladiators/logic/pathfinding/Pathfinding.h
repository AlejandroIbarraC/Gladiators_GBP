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

    int solution11x19[11][19];
    int solution8x17[8][17];

    bool backTrack11x19(int matrix[11][19]);
    bool backTrack8x17(int matrix[8][17]);

private:

    Pathfinding() = default;
    Pathfinding(Pathfinding const&)= default;
    Pathfinding& operator = (Pathfinding const&) = default;

    static Pathfinding* pathfinding;

    bool backTrack11x19Aux(int sRow, int sColumn, int matrix[11][19]);
    bool backTrack8x17Aux(int sRow, int sColumn, int matrix[8][17]);
    string toString11x19();
    string toString8x17();

};


#endif //GLADIATORS_GBP_PATHFINDING_H

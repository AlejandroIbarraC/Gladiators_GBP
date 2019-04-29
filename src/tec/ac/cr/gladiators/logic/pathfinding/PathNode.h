//
// Created by kevin on 28/04/19.
//

#ifndef GLADIATORS_GBP_PATHNODE_H
#define GLADIATORS_GBP_PATHNODE_H


class PathNode {

public:

    PathNode(int i, int j){
        this->x = i;
        this->y = j;
        this->dir = 0;
    }

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getDir() const;

    void setDir(int dir);

private:

    int x;
    int y;
    int dir;

};


#endif //GLADIATORS_GBP_PATHNODE_H

//
// Created by kevin on 28/04/19.
//

#ifndef GLADIATORS_GBP_PATHNODE_H
#define GLADIATORS_GBP_PATHNODE_H


class PathNode {

public:

    PathNode(int path){
        this->location = path;
    }

    PathNode* getNext() const;
    void setNext(PathNode* next);
    int getLocation() const;
    void setLocation(int location);

private:

    PathNode* next;
    int location;

};


#endif //GLADIATORS_GBP_PATHNODE_H

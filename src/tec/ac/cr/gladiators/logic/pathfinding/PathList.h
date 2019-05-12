//
// Created by kevin on 30/04/19.
//

#ifndef GLADIATORS_GBP_PATHLIST_H
#define GLADIATORS_GBP_PATHLIST_H


#include "PathNode.h"

class PathList {

public:

    static PathList* getInstance();

    int getLarge() const;
    void setLarge(int large);
    PathNode* getHead() const;
    void setHead(PathNode* head);

    void addPath(int location);

private:

    PathList() = default;
    PathList(PathList const&)= default;
    PathList& operator = (PathList const&) = default;

    static PathList* pathList;

    int large = 0;
    PathNode* head = nullptr;

};


#endif //GLADIATORS_GBP_PATHLIST_H

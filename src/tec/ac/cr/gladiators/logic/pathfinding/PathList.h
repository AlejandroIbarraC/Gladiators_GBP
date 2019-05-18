//
// Created by kevin on 30/04/19.
//

#ifndef GLADIATORS_GBP_PATHLIST_H
#define GLADIATORS_GBP_PATHLIST_H


#include <QtCore/QList>
#include "PathNode.h"

class PathList {

public:

    static PathList* getInstance();

    int getLarge() const;
    void setLarge(int large);
    PathNode* getHead() const;
    void setHead(PathNode* head);

    void createPath11x19(int row, int column);
    void createPath8x17(int row, int column);
    QList<int>* toQList();
    QList<int>* recalculatePath(QList<int> oldPath);

private:

    PathList() = default;
    PathList(PathList const&)= default;
    PathList& operator = (PathList const&) = default;

    static PathList* pathList;

    int large = 0;
    int ids11x19[11][19];
    int ids8x17[8][17];
    PathNode* head = nullptr;

    void initializeIDS();
    void addPath(int id);
    void deletePath();

};


#endif //GLADIATORS_GBP_PATHLIST_H

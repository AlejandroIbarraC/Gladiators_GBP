//
// Created by kevin on 30/04/19.
//

#include "PathList.h"
#include "Pathfinding.h"

PathList* PathList::pathList = nullptr;

PathList* PathList::getInstance() {
    if (!pathList) {
        pathList = new PathList();
        pathList->initializeIDS();
    }
    return pathList;
}

int PathList::getLarge() const {
    return large;
}

void PathList::setLarge(int large) {
    PathList::large = large;
}

PathNode *PathList::getHead() const {
    return head;
}

void PathList::setHead(PathNode *head) {
    PathList::head = head;
}

void PathList::addPath(int id) {
    if (this->head == nullptr){
        this->head = new PathNode(id);
        this->large++;
    }else{
        PathNode* tmp = this->head;
        while (tmp->getNext() != nullptr){
            tmp = tmp->getNext();
        }
        tmp->setNext(new PathNode(id));
        this->large++;
    }
}

void PathList::createPath11x19(int row, int column) {
    Pathfinding* pathfinding = Pathfinding::getInstance();
    int currentPath[11][19];
    if (this->head != nullptr){
        this->deletePath();
        this->head = nullptr;
    }
    int down;
    int up;
    int right;
    int left;
    while (true){
        addPath(ids11x19[row][column]);
        currentPath[row][column] = 1;
        down = row + 1;
        up = row - 1;
        left = column - 1;
        right = column + 1;
        if (row - 1 >= 0 && pathfinding->solution11x19[down][column] == 1 && currentPath[down][column] != 1){
            row--;
        }
        else if (row + 1 <= 10 && pathfinding->solution11x19[up][column] == 1 && currentPath[up][column] != 1){
            row++;
        }
        else if (column - 1 >= 0 && pathfinding->solution11x19[row][left] == 1 && currentPath[row][left] != 1){
            column--;
        }
        else if(column + 1 <= 18 && pathfinding->solution11x19[row][right] == 1 && currentPath[row][right] != 1){
            column++;
        }
        else{
            break;
        }
    }
}

void PathList::createPath8x17(int row, int column) {
    Pathfinding* pathfinding = Pathfinding::getInstance();
    int currentPath[8][17];
    if (this->head != nullptr){
        this->deletePath();
        this->head = nullptr;
    }
    while (true){
        addPath(ids8x17[row][column]);
        currentPath[row][column] = 1;
        if (!row - 1 < 0 && pathfinding->solution8x17[row - 1][column] == 1 && currentPath[row - 1][column] != 1){
            row--;
        }else if (!row + 1 > 7 && pathfinding->solution8x17[row + 1][column] == 1 && currentPath[row + 1][column] != 1){
            row++;
        }else if (!column - 1 < 0 && pathfinding->solution8x17[row][column - 1] == 1 && currentPath[row][column - 1] != 1){
            column--;
        }else if(!column + 1 > 16 && pathfinding->solution8x17[row][column + 1] == 1 && currentPath[row][column + 1]){
            column++;
        }else{
            break;
        }
    }
}

void PathList::initializeIDS() {
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

void PathList::deletePath() {
    if (this->head->getNext() == nullptr){
        delete this->head;
    }else{
        PathNode* tmp = this->head->getNext();
        PathNode* tmpDel = this->head;
        while (tmp != nullptr){
            delete tmpDel;
            tmpDel = tmp;
            tmp = tmp->getNext();
        }
        delete tmpDel;
        this->large = 0;
    }
}

QList<int>* PathList::toQList() {
    QList<int>* path = new QList<int>();
    PathNode* tmp = this->head;
    while (tmp != nullptr){
        path->append(tmp->getLocation());
        tmp = tmp->getNext();
    }
    return path;
}
//
// Created by kevin on 30/04/19.
//

#include "PathList.h"

PathList* PathList::pathList = nullptr;

PathList* PathList::getInstance() {
    if (!pathList) {
        pathList = new PathList();
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

void PathList::addPath(int location) {
    if (this->head == nullptr){
        this->head = new PathNode(location);
        this->large++;
    }else{
        PathNode* tmp = this->head;
        while (tmp->getNext() != nullptr){
            tmp = tmp->getNext();
        }
        tmp->setNext(new PathNode(location));
        this->large++;
    }
}

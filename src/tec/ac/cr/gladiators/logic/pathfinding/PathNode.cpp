//
// Created by kevin on 28/04/19.
//

#include "PathNode.h"


PathNode *PathNode::getNext() const {
    return next;
}

void PathNode::setNext(PathNode *next) {
    PathNode::next = next;
}

int PathNode::getLocation() const {
    return location;
}

void PathNode::setLocation(int location) {
    PathNode::location = location;
}

//
// Created by kevin on 28/04/19.
//

#include "PathNode.h"

int PathNode::getX() const {
    return x;
}

void PathNode::setX(int x) {
    PathNode::x = x;
}

int PathNode::getY() const {
    return y;
}

void PathNode::setY(int y) {
    PathNode::y = y;
}

int PathNode::getDir() const {
    return dir;
}

void PathNode::setDir(int dir) {
    PathNode::dir = dir;
}

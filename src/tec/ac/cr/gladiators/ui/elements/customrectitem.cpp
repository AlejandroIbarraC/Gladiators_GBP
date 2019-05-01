#include "customrectitem.h"
#include <iostream>

CustomRectItem::CustomRectItem(QGraphicsRectItem* parent) :
    QGraphicsRectItem(parent) {
}

void CustomRectItem::setID(int id) {
    this->id = id;
}

void CustomRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsRectItem::mouseMoveEvent(event);
    if (acceptDrops()) {
        setBrush(QBrush(QColor(0, 0, 0, 0)));
        setAcceptDrops(false);
    }
}

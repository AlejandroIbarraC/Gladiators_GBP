#include "draggablerectitem.h"
#include <iostream>

DraggableRectItem::DraggableRectItem(QGraphicsRectItem* parent, QString tower):
        QGraphicsRectItem(parent), m_dragged(false) {
    setFlags(QGraphicsRectItem::ItemIsSelectable|
             QGraphicsRectItem::ItemIsMovable);

    // Initializes default attributes.
    towerType = tower;
    QString towerdir = ":/towers/towers/" + towerType + "1.png";
    QString icondir = ":/towers/towers/" + towerType + "icon.png";
    QPixmap tPix = QPixmap(towerdir);
    QPixmap iPix = QPixmap(icondir);
    towerPix = tPix.scaled(40,40);
    iconPix = iPix.scaled(70, 70);
    this->setBrush(iconPix);
}

void DraggableRectItem::setAnchorPoint(const QPointF &anchorPoint) {
    this->anchorPoint = anchorPoint;
}

void DraggableRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    m_dragged = true;
    QGraphicsRectItem::mouseMoveEvent(event);
    this->setRect(smallRect);
    this->setBrush(QBrush(towerPix));
}

void DraggableRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(m_dragged){
        QList<QGraphicsItem*> colItems = collidingItems();
        if(colItems.isEmpty())
            this->setPos(anchorPoint);
        else {
            QGraphicsItem* closestItem = colItems.at(0);
            qreal shortestDist = 100000;
                    foreach(QGraphicsItem* item, colItems){
                    QLineF line(item->sceneBoundingRect().center(),
                                this->sceneBoundingRect().center());
                    if(line.length() < shortestDist){
                        shortestDist = line.length();
                        closestItem = item;
                    }
                }
            if (closestItem->acceptDrops() == false) {
                this->setPos(closestItem->scenePos());
            } else {
                this->setPos(anchorPoint);
            }
        }
        m_dragged = false;
    }
    this->setPos(anchorPoint);
    this->setRect(largeRect);
    this->setBrush(QBrush(iconPix));
    QGraphicsRectItem::mouseReleaseEvent(event);
}

int DraggableRectItem::randInt(int low, int high) {
    return qrand() % ((high + 1) - low) + low;
}

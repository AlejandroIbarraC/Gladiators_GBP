#include "draggablerectitem.h"
#include <iostream>

#include "../field.h"

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
    Field* field = Field::getInstance();
    QGraphicsRectItem::mouseMoveEvent(event);
    this->setRect(smallRect);
    this->setBrush(QBrush(towerPix));

    QList<QGraphicsItem*> colItems = collidingItems();
    if(colItems.isEmpty()) {
        field->deOpaqueGrid();
        safeReturn = true;
    } else {
        closestItem = colItems.at(0);
        qreal shortestDist = 100000;
        foreach(QGraphicsItem* item, colItems){
            QLineF line(item->sceneBoundingRect().center(),
                        this->sceneBoundingRect().center());
            if(line.length() < shortestDist){
                shortestDist = line.length();
                closestItem = item;
            }
        }
        int dimensions = field->rows * field->columns;
        QPointF closestPos = closestItem->pos();
        for (int i = 0; i < dimensions; i++) {
            CustomRectItem* currentSquare = field->allSquares.at(i);
            if (currentSquare->pos() == closestPos) {
                if (!currentSquare->acceptDrops()) {
                    field->opaqueGrid();
                    closestSquare = currentSquare;
                    field->allSquares.at(i)->setBrush(QColor(80, 80, 80, 255));
                }
            }
        }
        safeReturn = false;
    }
}

void DraggableRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    Field* field = Field::getInstance();
    this->setPos(anchorPoint);
    this->setRect(largeRect);
    this->setBrush(QBrush(iconPix));
    field->deOpaqueGrid();
    if (!safeReturn) {
        closestSquare->setBrush(towerPix);
        closestSquare->setAcceptDrops(true);
        closestSquare->initializeArea();
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}

int DraggableRectItem::randInt(int low, int high) {
    return qrand() % ((high + 1) - low) + low;
}

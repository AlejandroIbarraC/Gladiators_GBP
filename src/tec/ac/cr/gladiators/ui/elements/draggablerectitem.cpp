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
    build->setMedia(QUrl("qrc:/main/build.mp3"));
}

/// Sets point where item will return if dropped elsewhere
void DraggableRectItem::setAnchorPoint(const QPointF &anchorPoint) {
    this->anchorPoint = anchorPoint;
}

/// Executes while item is being dragged
void DraggableRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // While being moved, show default tower picture
    QGraphicsRectItem::mouseMoveEvent(event);
    m_dragged = true;
    Field* field = Field::getInstance();
    this->setRect(smallRect);
    this->setBrush(QBrush(towerPix));

    // Calculates closest square to paint it in real time
    QList<QGraphicsItem*> colItems = collidingItems();
    // If there are no colliding items while drag, don't show grid in checker pattern
    if(colItems.isEmpty()) {
        field->deOpaqueGrid();
        safeReturn = true;
    } else {
        // Calculates closest square
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

        // Paints current target square in real time and corrects paint for grid in checker pattern
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

        // Gets updated path and paints it
        QList<int>* path = field->getPath();
        field->paintPath(path);

        safeReturn = false;
    }
}

/// Executes if item is dropped on square
void DraggableRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    // Moves draggable tower to original position in dock
    QGraphicsRectItem::mouseReleaseEvent(event);
    Field* field = Field::getInstance();
    this->setPos(anchorPoint);
    this->setRect(largeRect);
    this->setBrush(QBrush(iconPix));
    field->deOpaqueGrid();

    // If item is dropped on grid, calculate closest square ID,
    // assign it to field damage matrix, add tower to pathfinding
    // data, and paint tower on UI
    if (!safeReturn) {
        int areaID = field->squareToID(closestSquare);
        field->allSquares[areaID]->damageIndex = TowersList::getInstance()->getTowersByPosition(field->towerIndex) / 2000;
        field->towerIndex++;
        field->assignDamageMatrix(areaID);
        closestSquare->setBrush(towerPix);
        closestSquare->setAcceptDrops(true);
        closestSquare->initializeArea();
        field->addTower(areaID);
        closestSquare->towerType = towerType;
        build->play();
    }
}

/// Calculates random integer from two limits
int DraggableRectItem::randInt(int low, int high) {
    return qrand() % ((high + 1) - low) + low;
}

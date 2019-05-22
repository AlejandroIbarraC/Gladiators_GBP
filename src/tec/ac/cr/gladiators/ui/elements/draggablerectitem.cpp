#include "draggablerectitem.h"

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
    build->setMedia(QUrl("qrc:/audio/audio/build.mp3"));
    blockingSquare = new CustomRectItem();
}

//! Adds tower to pathfinding matrix
//! \param tower ID
void DraggableRectItem::addTempTower(int id) {
    Field* field = Field::getInstance();
    QList<int>* IDCoords = field->idToCoords(id);
    int x = IDCoords->at(0);
    int y = IDCoords->at(1);
    if (field->currentStage == 1) {
        tempFieldMatrix[x][y] = 0;
    } else {
        tempCityMatrix[x][y] = 0;
    }
}


//! Sets point where item will return if dropped elsewhere
//! \param QPointF& Qt point to anchor
void DraggableRectItem::setAnchorPoint(const QPointF& anchorPoint) {
    this->anchorPoint = anchorPoint;
}

//! Activates while item is being dragged
void DraggableRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
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

        // Gets temporary path
        PathList* pathList = PathList::getInstance();
        Pathfinding* pathfinding = Pathfinding::getInstance();
        bool isPath = false;
        pathfinding->reset();
        if (field->currentStage == 1) {
            for (int i = 0; i < field->rows; i++) {
                for (int j = 0; j < field->columns; j++) {
                    tempFieldMatrix[i][j] = field->fieldMatrix[i][j];
                }
            }
            addTempTower(closestSquare->id);
            isPath = pathfinding->backTrack11x19(6, 0, tempFieldMatrix);
            pathList->createPath11x19(6, 0);
        } else {
            for (int i = 0; i < field->rows; i++) {
                for (int j = 0; j < field->columns; j++) {
                    tempCityMatrix[i][j] = field->cityMatrix[i][j];
                }
            }
            addTempTower(closestSquare->id);
            isPath = pathfinding->backTrack8x17(6, 0, tempCityMatrix);
            pathList->createPath8x17(6, 0);
        }

        // Paint temporary path
        field->paintPath(pathList->toQList());
        safeReturn = false;
    }
}

//! Activates if item is dropped on square
void DraggableRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event){
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
        int money = field->getMoney();
        if (towerType == "gatling" and money < 5) {}
        else if (towerType == "fire" and money < 10) {}
        else if (towerType == "electric" and money < 15) {}
        // There's not enough money to buy tower
        else {
            // Get square info to assign data
            int areaID = field->squareToID(closestSquare);
            closestSquare->towerType = towerType;
            int damageIndex = TowersList::getInstance()->getTowersByPosition(field->towerIndex);
            field->allSquares[areaID]->damageIndex = damageIndex;
            field->towerIndex++;
            field->assignDamageMatrix(areaID);
            closestSquare->setAcceptDrops(true);
            closestSquare->initializeArea();

            // Assigns tower level according to evolution level.
            if (damageIndex > 200) {
                closestSquare->towerLevel = 2;
            } else if (damageIndex > 500) {
                closestSquare->towerLevel = 3;
            }

            // Get correct tower picture
            QString towerLevel = QString::number(closestSquare->towerLevel);
            QString towerdir = ":/towers/towers/" + towerType + towerLevel + ".png";
            QPixmap tPix = QPixmap(towerdir);
            QPixmap newTowerPix = tPix.scaled(40,40);
            closestSquare->setBrush(newTowerPix);

            // Multiplies damage if tower is special
            if (towerType == "fire") {
                closestSquare->damageIndex *= 2;
                field->setMoney(field->getMoney() - 10);
            } else if (towerType == "electric") {
                closestSquare->damageIndex *= 4;
                field->setMoney(field->getMoney() - 15);
            } else {
                field->setMoney(field->getMoney() - 5);
            }
            field->addTower(areaID);
            build->play();
        }

        // Update soldier path in real time when tower is placed
        Game* game = Game::getInstance();
        Pathfinding* pathfinding = Pathfinding::getInstance();
        PathList* pathList = PathList::getInstance();
        pathfinding->reset();
        if (field->currentStage == 1) {
            pathfinding->backTrack11x19(6, 0, field->fieldMatrix);
            pathList->createPath11x19(6, 0);
        } else {
            pathfinding->backTrack8x17(6, 0, field->cityMatrix);
            pathList->createPath8x17(6, 0);
        }

        // Modify game path for all soldiers
        game->setPath(pathList->toQList());

    }
}

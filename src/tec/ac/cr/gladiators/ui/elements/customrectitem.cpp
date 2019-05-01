#include "customrectitem.h"
#include "../field.h"
#include "game.h"

CustomRectItem::CustomRectItem(QGraphicsRectItem* parent) :
    QGraphicsRectItem(parent) {
}

QGraphicsItem* CustomRectItem::getArea(){
    return area;
}

void CustomRectItem::initializeArea() {
    Field* field = Field::getInstance();
    Game* game = Game::getInstance();
    QGraphicsScene* soldierScene = field->getSoldierScene();
    area = new QGraphicsRectItem(QRect(0, 0, 120, 120));
    area->setBrush(Qt::white);
    area->setX(this->x() - 40);
    area->setY(this->y() - 40);
    area->setVisible(false);
    game->addArea(area);
    soldierScene->addItem(area);
}

void CustomRectItem::setID(int id) {
    this->id = id;
}

void CustomRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsRectItem::mouseMoveEvent(event);
    if (acceptDrops()) {
        if (!area->isVisible()) {
            area->setVisible(true);
        } else {
            area->setVisible(false);
        }
        //setBrush(QBrush(QColor(0, 0, 0, 0)));
        //setAcceptDrops(false);
    }
}

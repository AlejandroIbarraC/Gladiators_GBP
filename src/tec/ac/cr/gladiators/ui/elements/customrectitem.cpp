#include "customrectitem.h"
#include "../field.h"
#include "game.h"

CustomRectItem::CustomRectItem(QGraphicsRectItem* parent) :
    QGraphicsRectItem(parent) {
}

QGraphicsItem* CustomRectItem::getArea(){
    return area;
}

/// Creates invisible damage circular area of tower
void CustomRectItem::initializeArea() {
    Field* field = Field::getInstance();
    Game* game = Game::getInstance();
    QGraphicsScene* soldierScene = field->getSoldierScene();
    area = new QGraphicsEllipseItem(QRect(0, 0, 120, 120));
    area->setBrush(Qt::transparent);
    area->setX(this->x() - 40);
    area->setY(this->y() - 40);
    area->setVisible(false);
    game->addArea(area);
    soldierScene->addItem(area);
}

void CustomRectItem::setID(int id) {
    this->id = id;
}

/// Executes when tower is pressed to show additional options.
/// Click to show area. Secondary click to delete tower.
void CustomRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        if (acceptDrops()) {
            if (!area->isVisible()) {
                area->setVisible(true);
            } else {
                area->setVisible(false);
            }
        }
    } else {
        Field* field = Field::getInstance();
        field->deleteTower(id);
        field->unassignDamageMatrix(id);
        setBrush(QBrush(QColor(0, 0, 0, 0)));
        setAcceptDrops(false);
        area->setVisible(false);
    }
}

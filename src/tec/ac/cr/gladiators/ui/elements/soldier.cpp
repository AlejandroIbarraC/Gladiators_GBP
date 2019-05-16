#include "soldier.h"
#include "game.h"
#include <iostream>
#include "customrectitem.h"
#include "../../logic/GladiatorsList.h"
#include "../field.h"
#include <iostream>


Soldier::Soldier(QGraphicsRectItem* parent) {
    // Initializes default attributes.


}


/// Advances square ID in path.
void Soldier::advanceSquare() {
    this->currentSquare ++;
}

//! A method use to check soldiers damage
void Soldier::checkDamage() {
    if (life < 1) {
        this->setVisible(false);
    } else {
        Game* game = Game::getInstance();
        QList<QGraphicsItem*> colItems = collidingItems();
        QList<QGraphicsItem*> areas = game->getAreas();
        QList<QGraphicsItem*> intersection;

        for (int i = 0; i < colItems.length(); i++) {
            QGraphicsItem* item = colItems[i];
            for (int i = 0; i < areas.length(); i++) {
                QGraphicsItem* area = areas[i];
                if (area == item) {
                    intersection.append(area);
                }
            }
        }

        int damage = collidingItems().length();
        int size = intersection.size();
        if (size > 0) {
            qDebug() << "Made it" << size;
        }
        life-= damage;
    }
}

/// Sets damage to this soldier in cycle depending on position. Loop it for animated results.
void Soldier::damage() {
    if (life < 0) {
        Game* game = Game::getInstance();
        game->deleteSoldier(this);
    } else {
        Field* field = Field::getInstance();
        QList<int>* damageMatrix = field->damageMatrix;
        life -= damageMatrix->at(graphicalSquare);
        //qDebug() << life;
    }
}

//! A method that runs specific actions when a soldier is pressed
void Soldier::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    QGraphicsRectItem::mousePressEvent(event);
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    gladiatorsList->setSoldierToShowByID(this->id);
    Field* field = Field::getInstance();
    field->setSoldierLabels();
}



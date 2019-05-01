#include "soldier.h"
#include "game.h"
#include <iostream>

Soldier::Soldier(QGraphicsRectItem* parent) {
    rect = QRect(0, 0, 15, 15);
}

/// Advances square ID in path.
void Soldier::advanceSquare() {
    this->currentSquare ++;
}

QRectF Soldier::boundingRect() const {
    return QRectF(rect);
}

void Soldier::checkDamage() {
    if (life < 1) {
        delete this;
    } else {
        Game* game = Game::getInstance();
        QList<QGraphicsItem*> colItems = this->collidingItems();
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
        qDebug() << "Damage:" << damage;
        if (size > 0) {
            qDebug() << "Made it" << size;
        }
        life = life - damage;
    }
}

QRect Soldier::geometry() const {
    return rect;
}

void Soldier::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(QBrush(Qt::red));
    painter->drawRoundRect(rect);
}

void Soldier::setGeometry(const QRect &value) {
    if(rect!=value){
        rect = value;
        update();
    }
}

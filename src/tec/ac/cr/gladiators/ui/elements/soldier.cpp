#include "soldier.h"
#include "game.h"
#include <iostream>
#include "customrectitem.h"
#include "../../logic/GladiatorsList.h"
#include "../field.h"
#include <iostream>

Soldier::Soldier(QGraphicsRectItem* parent) {
    // Initializes default attributes.
    oof->setMedia(QUrl("qrc:/main/oof.mp3"));
}

/// Advances square ID in path.
void Soldier::advanceSquare() {
    this->currentSquare++;
}

/// Rotates towers accordingly. Loop it for animated results.
void Soldier::checkRotation() {
    Field* field = Field::getInstance();
    QList<int>* towers = field->towerList;
    QVector<CustomRectItem*> squares = field->allSquares;

    for (int i = 0; i < towers->length(); i++) {
        int towerID = towers->at(i);
        CustomRectItem* towerSquare = squares.at(towerID);
        QString towerType = towerSquare->towerType;

        int up = towers->at(i) - field->columns;
        int down = towers->at(i) + field->columns;
        int right = towers->at(i) + 1;
        int left = towers->at(i) - 1;
        int upLeft = up - 1;
        int upRight = up + 1;
        int downLeft = down - 1;
        int downRight = down + 1;

        if (graphicalSquare == up) {

            QString rotationDir = ":/towers/towers/" + towerType + "1b.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(up)->setBrush(adPix);

        } else if (graphicalSquare == down) {

            QString rotationDir = ":/towers/towers/" + towerType + "1f.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(down)->setBrush(adPix);

        } else if (graphicalSquare == right) {

            QString rotationDir = ":/towers/towers/" + towerType + "1d.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(right)->setBrush(adPix);

        } else if (graphicalSquare == left) {

            QString rotationDir = ":/towers/towers/" + towerType + "1.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(left)->setBrush(adPix);

        } else if (graphicalSquare == upLeft) {

            QString rotationDir = ":/towers/towers/" + towerType + "1a.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix= rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(upLeft)->setBrush(adPix);

        } else if (graphicalSquare == upRight) {

            QString rotationDir = ":/towers/towers/" + towerType + "1c.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(upRight)->setBrush(adPix);

        } else if (graphicalSquare == downLeft) {

            QString rotationDir = ":/towers/towers/" + towerType + "1g.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(downLeft)->setBrush(adPix);

        } else if (graphicalSquare == downRight) {

            QString rotationDir = ":/towers/towers/" + towerType + "1e.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(downRight)->setBrush(adPix);
        }
    }
}

/// Sets damage to this soldier in cycle depending on position. Loop it for animated results.
void Soldier::damage() {
    if (life < 0) {
        Game* game = Game::getInstance();
        if (isUndead) {
            game->deleteSoldier(this);
        } else {
            QString splatDir = ":/soldiers/soldiers/splat.png";
            QPixmap sPix = QPixmap(splatDir);
            sPix = sPix.scaled(15,15);
            this->setBrush(sPix);
            oof->play();
            game->getArmy()->removeOne(this);
            this->isUndead = true;
            game->addWalker(this);
        }
    } else {
        Field* field = Field::getInstance();
        QList<int>* damageMatrix = field->damageMatrix;
        if (graphicalSquare > 0) {
            life -= damageMatrix->at(graphicalSquare);
        }
    }
}

//! A method that runs specific actions when a soldier is pressed
void Soldier::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsRectItem::mousePressEvent(event);
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    gladiatorsList->setSoldierToShowByID(this->id);
    if (gladiatorsList->soldierToShow != nullptr){
        Field* field = Field::getInstance();
        field->setSoldierLabels();
    }
}

void Soldier::setLife(int nlife) {
    life = nlife;
}



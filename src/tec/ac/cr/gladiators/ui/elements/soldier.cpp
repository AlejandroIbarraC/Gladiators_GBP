#include "soldier.h"
#include "game.h"
#include <iostream>
#include "customrectitem.h"
#include "../../logic/GladiatorsList.h"
#include "../field.h"
#include <iostream>

Soldier::Soldier(QGraphicsRectItem* parent) {
    // Initializes default attributes.
    oof->setMedia(QUrl("qrc:/audio/audio/oof.mp3"));
    growl->setMedia(QUrl("qrc:/audio/audio/growl.mp3"));
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
        QString towerLevel = QString::number(towerSquare->towerLevel);

        int up = towers->at(i) - field->columns;
        int down = towers->at(i) + field->columns;
        int right = towers->at(i) + 1;
        int left = towers->at(i) - 1;
        int upLeft = up - 1;
        int upRight = up + 1;
        int downLeft = down - 1;
        int downRight = down + 1;

        if (graphicalSquare == up and up >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + "b.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(up)->setBrush(adPix);

        } else if (graphicalSquare == down and down >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + "f.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(down)->setBrush(adPix);

        } else if (graphicalSquare == right and right >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + "d.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(right)->setBrush(adPix);

        } else if (graphicalSquare == left and left >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + ".png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(left)->setBrush(adPix);

        } else if (graphicalSquare == upLeft and upLeft >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + "a.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix= rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(upLeft)->setBrush(adPix);

        } else if (graphicalSquare == upRight and upRight >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + "c.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(upRight)->setBrush(adPix);

        } else if (graphicalSquare == downLeft and downLeft >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + "g.png";
            QPixmap rPix = QPixmap(rotationDir);
            rPix = rPix.scaled(40,40);
            towerSquare->setBrush(rPix);

            QString areaDamage = ":/soldiers/soldiers/" + towerType + ".png";
            QPixmap adPix = QPixmap(areaDamage);
            adPix = adPix.scaled(40,40);
            field->allSquares.at(downLeft)->setBrush(adPix);

        } else if (graphicalSquare == downRight and downRight >= 0) {

            QString rotationDir = ":/towers/towers/" + towerType + towerLevel + "e.png";
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
        Field* field = Field::getInstance();
        if (isUndead) {
            growl->play();
            game->deleteSoldier(this);
            field->addMoney();
            field->addMoney();
        } else {
            QString splatDir = ":/soldiers/soldiers/splat.png";
            QPixmap sPix = QPixmap(splatDir);
            if (isBoss) {
                sPix = sPix.scaled(40,40);
                growl->play();
            } else {
                sPix = sPix.scaled(15,15);
                oof->play();
            }
            this->setBrush(sPix);
            game->getArmy()->removeOne(this);
            this->isUndead = true;
            game->addWalker(this);
            field->addMoney();
        }
    } else {
        Field* field = Field::getInstance();
        QList<int>* damageMatrix = field->damageMatrix;
        if (graphicalSquare >= 0) {
            int dodgeChange = field->randInt(0, 20);
            if (dodgeChange != 7) {
                life -= damageMatrix->at(graphicalSquare);
            }
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



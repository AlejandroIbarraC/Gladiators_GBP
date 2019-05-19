#include "game.h"
#include "../field.h"
#include "../../logic/GladiatorsList.h"
#include "../../client/Client.h"
#include "soldier.h"


Game *Game::instance = new Game();

Game::Game() {
    army = new QList<Soldier*>();
    updateTime = 10;
}

void Game::addArea(QGraphicsItem *area) {
    allAreas.append(area);
}

void Game::addSoldier(Soldier *soldier) {
    army->append(soldier);
}

/// Creates army of soldiers with distance between them
/// @param int army size
void Game::createArmy(int size) {
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getScene();
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    size = gladiatorsList->getLenght();
    allSquares = field->allSquares;
    distanceX = -20;

    QRect rect = QRect(0, 0, 15, 15);
    for(int i = 0; i < size; i++) {
        Soldier* soldier = new Soldier();
        soldier->id = i;
        soldier->setPen(Qt::NoPen);
        soldier->setLife(GladiatorsList::getInstance()->getGladiatorLifeByID(i) * 100);

        QString soldierdir = ":/soldiers/soldiers/soldierFlashRight.png";
        QPixmap sPix = QPixmap(soldierdir);
        soldier->soldierPix = sPix.scaled(15,15);
        soldier->setBrush(soldier->soldierPix);

        soldier->setRect(rect);
        addSoldier(soldier);
        soldier->setX(distanceX);
        distanceX = distanceX - 20;
        soldier->setY(350);
        scene->addItem(soldier);

    }
}

/// Deletes soldier in army.
/// @param Soldier* soldier to delete
void Game::deleteSoldier(Soldier *soldier) {
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    gladiatorsList->deleteGladiatorByID(soldier->id);
    army->removeOne(soldier);
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getScene();
    scene->removeItem(soldier);
    delete soldier;
}

/// Updates soldier position. Loop it for animated results.
/// @param Soldier to move
void Game::followPath(Soldier* soldier) {
    // Gets specific current square objective for soldier.
    int squareObjective = soldier->currentSquare;
    int IDObjective = path->at(squareObjective);
    soldier->graphicalSquare = IDObjective;

    // Define x and y values
    int XObjective = 0;
    int currentX = 0;
    int absXDifference = 0;
    int YObjective = 0;
    int currentY = 0;
    int absYDifference = 0;
    int endSquareX = 0;
    int endSquareY = 0;

    if (IDObjective > 0) {
        XObjective = static_cast<int>(allSquares[IDObjective]->x()) + 15;
        YObjective = static_cast<int>(allSquares[IDObjective]->y()) + 15;
    } else {
        if (IDObjective == -1) {
            XObjective = 100;
        } else {
            XObjective = 1100;
        }
        YObjective = 350;
    }

    // X axis values
    currentX = static_cast<int>(soldier->x());
    absXDifference = abs(abs(XObjective) - abs(currentX));

    // Y axis values
    currentY = static_cast<int>(soldier->y());
    absYDifference = abs(abs(YObjective) - abs(currentY));


    if (absXDifference > 1) {
        // Move right or left.
        if (XObjective > currentX) {
            soldier->setX(soldier->x() + 1);
            QString soldierdir = ":/soldiers/soldiers/soldierFlashRight.png";
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);

        } else {
            soldier->setX(soldier->x() - 1);
            QString soldierdir = ":/soldiers/soldiers/soldierFlashLeft.png";
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);
        }
    } else if (absYDifference > 1) {
        // Move up or down.
        if (YObjective > currentY) {

            soldier->setY(soldier->y() + 1);
            QString soldierdir = ":/soldiers/soldiers/soldierFlashDown.png";
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);

        } else {
            soldier->setY(soldier->y() - 1);
            QString soldierdir = ":/soldiers/soldiers/soldierFlashUp.png";
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);
        }
    } else {
        // Checks if end is reached.
        if (IDObjective > 0) {
            endSquareX = static_cast<int>(allSquares[lastID]->x()) + 15;
            endSquareY = static_cast<int>(allSquares[lastID]->y()) + 15;
        } else {
            if (IDObjective == -1) {
                endSquareX = 100;
            } else {
                endSquareX = 1100;
            }
            endSquareY = 350;
        }
        int xEndDifference = abs(abs(currentX) - abs(endSquareX));
        int yEndDifference = abs(abs(currentY) - abs(endSquareY));

        if (xEndDifference > 1 or yEndDifference > 1) {
            soldier->advanceSquare();
        } else {
            soldier->done = true;
        }
    }
    soldier->update();
}

QList<QGraphicsItem*> Game::getAreas() {
    return allAreas;
}

QList<Soldier*>* Game::getArmy() const {
    return army;
}

Game* Game::getInstance() {
    return instance;
}

void Game::setArmy(QList<Soldier*> *nArmy) {
    delete army;
    army = nArmy;
}

void Game::setPath(QList<int> *nPath) {
    delete path;
    nPath->prepend(-1);
    nPath->append(-2);
    path = nPath;
    lastID = path->constLast();
}

//! A method use to remove Areas
//! \param area
void Game::removeArea(QGraphicsItem *area) {
    allAreas.removeOne(area);
}

void Game::pause() {
    timer->stop();
}

void Game::play() {
    timer->start();
}

//! A method that runs the game
void Game::run() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(updateTime);
}

//! A method that upadates the game constantly
/// Main game loop.
void Game::updateGame() {
    // Updates each soldier in game.

    for(int i = 0; i < army->length(); i++) {
        Soldier* currentSoldier = army->at(i);
        if (currentSoldier->done) {
            Field* field = Field::getInstance();
            field->lowerLife();
            deleteSoldier(currentSoldier);
        } else {            
            followPath(currentSoldier);
            currentSoldier->damage();
            currentSoldier->checkRotation();
        }
    }
}



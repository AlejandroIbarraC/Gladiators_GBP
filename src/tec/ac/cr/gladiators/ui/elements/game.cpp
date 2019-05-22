#include "game.h"
#include "../field.h"
#include "../../logic/GladiatorsList.h"
#include "../../client/Client.h"
#include "soldier.h"


Game *Game::instance = new Game();

Game::Game() {
    army = new QList<Soldier*>();
    deadArmy = new QList<Soldier*>();
}

void Game::addArea(QGraphicsItem *area) {
    allAreas.append(area);
}

void Game::addSoldier(Soldier *soldier) {
    army->append(soldier);
}

void Game::addWalker(Soldier *soldier) {
    deadArmy->append(soldier);
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
        int life = GladiatorsList::getInstance()->getGladiatorLifeByID(i) * 100;
        soldier->setLife(life);
        soldier->fullLife = life;

        QString soldierdir = ":/soldiers/soldiers/soldierFlashRight.png";
        QPixmap sPix = QPixmap(soldierdir);
        soldier->soldierPix = sPix.scaled(15,15);
        soldier->setBrush(soldier->soldierPix);

        soldier->setRect(rect);
        addSoldier(soldier);
        soldier->setX(distanceX);
        distanceX = distanceX - 20;
        soldier->setY(340);
        scene->addItem(soldier);

    }
}

/// Deletes whole army.
void Game::deleteArmy() {
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getScene();
    for (int i = 0; i < gladiatorsList->getLenght(); i++) {
        gladiatorsList->deleteGladiatorByID(i);
    }
    for (int i = 0; i < army->length(); i++){
        scene->removeItem(army->at(i));
    }
    army->clear();
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
            XObjective = 1000;
        }
        YObjective = 340;
    }

    // X axis values
    currentX = static_cast<int>(soldier->x());
    absXDifference = abs(currentX - XObjective);

    // Y axis values
    currentY = static_cast<int>(soldier->y());
    absYDifference = abs(currentY - YObjective);


    if (absXDifference > 1) {
        // Move right or left.
        if (XObjective > currentX) {
            soldier->setX(soldier->x() + 1);
            QString soldierdir;
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashRight.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerRight.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);
        } else {
            soldier->setX(soldier->x() - 1);
            QString soldierdir;
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashLeft.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerLeft.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);
        }
    } else if (absYDifference > 1) {
        // Move up or down.
        if (YObjective > currentY) {
            soldier->setY(soldier->y() + 1);
            QString soldierdir;
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashDown.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerDown.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);
        } else {
            soldier->setY(soldier->y() - 1);
            QString soldierdir;
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashUp.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerUp.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            soldier->setBrush(soldier->soldierPix);
        }
    } else {
        // Checks if end is reached.
        endSquareX = 1000;
        endSquareY = 350;
        int xEndDifference = abs(abs(currentX) - abs(endSquareX));
        int yEndDifference = abs(abs(currentY) - abs(endSquareY));

        if (xEndDifference > 1 or yEndDifference > 1) {
            if (IDObjective == -2) {
                soldier->done = true;
            } else {
                soldier->advanceSquare();
            }
        }
    }
    soldier->update();
}

void Game::floatAllToggle() {
    for (int i = 0; i < army->length(); i++) {
        Soldier* currentSoldier = army->at(i);
        currentSoldier->isFloating = true;
    }
}

void Game::floatSoldier(Soldier *soldier) {
    if (soldier->y() < -10) {
        deleteSoldier(soldier);
    } else {
        soldier->setY(soldier->y() -1);
    }
}

QList<QGraphicsItem*> Game::getAreas() {
    return allAreas;
}

QList<Soldier*>* Game::getDeadArmy() const {
    return deadArmy;
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
    nPath->prepend(-1);
    nPath->append(-2);
    path = nPath;
    lastID = path->constLast();
}

void Game::setUpdateTime(int nTime) {
    updateTime = nTime;
    timer->setInterval(nTime);
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

void Game::toggleFreeze() {
    if (frozenArmy) {
        frozenArmy = false;
    } else {
        frozenArmy = true;
    }
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
            bool isFloating = currentSoldier->isFloating;
            if (!frozenArmy) {
                if (!isFloating) {
                    followPath(currentSoldier);
                    currentSoldier->damage();
                    currentSoldier->checkRotation();
                } else {
                    floatSoldier(currentSoldier);
                }
            }
        }
    }
}



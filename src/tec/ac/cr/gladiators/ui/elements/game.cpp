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

        int randomBit = rand() % 2;
        //qDebug() << "Numb: " << randomBit;

        QString soldierdir = ":/soldiers/soldiers/soldierFlashRight.png";

        QPixmap sPix = QPixmap(soldierdir);
        soldier->soldierPix = sPix.scaled(15,15);
        soldier->setBrush(soldier->soldierPix);
        soldier->setRect(rect);
        soldier->id = i;
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
    QGraphicsScene* scene = field->getSoldierScene();
    scene->removeItem(soldier);
    delete soldier;
}

/// Updates soldier position. Loop it for animated results.
/// @param Soldier to move
void Game::followPath(Soldier* soldier) {
    // Gets specific current square objective for soldier.
    int squareObjective = soldier->currentSquare;
    int IDObjetive = path->at(squareObjective);
    soldier->graphicalSquare = IDObjetive;

    // X axis values
    int XObjective = static_cast<int>(allSquares[IDObjetive]->x()) + 15;
    int currentX = static_cast<int>(soldier->x());
    int absXDifference = abs(abs(XObjective) - abs(currentX));

    // Y Axis values
    int YObjective = static_cast<int>(allSquares[IDObjetive]->y()) + 15;
    int currentY = static_cast<int>(soldier->y());
    int absYDifference = abs(abs(YObjective) - abs(currentY));

    if (absXDifference > 1) {
        // Move right or left.
        if (XObjective > currentX) {
            soldier->setX(soldier->x() + 1);
        } else {
            soldier->setX(soldier->x() - 1);
        }
    } else if (absYDifference > 1) {
        // Move up or down.
        if (YObjective > currentY) {
            soldier->setY(soldier->y() + 1);
        } else {
            soldier->setY(soldier->y() - 1);
        }
    } else {
        // Checks if end is reached.
        int endSquareX = static_cast<int>(allSquares[lastID]->x()) + 15;
        int endSquareY = static_cast<int>(allSquares[lastID]->y()) + 15;
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
    army = nArmy;
}

void Game::setPath(QList<int> *nPath) {
    path = nPath;
    lastID = path->constLast();
}

//! A method use to remove Areas
//! \param area
void Game::removeArea(QGraphicsItem *area) {
    allAreas.removeOne(area);
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
        }
    }
}



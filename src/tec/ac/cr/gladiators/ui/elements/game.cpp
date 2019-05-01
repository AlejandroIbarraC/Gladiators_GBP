#include "game.h"
#include "../field.h"

Game *Game::instance = new Game();

Game::Game() {
    army = new QList<Soldier*>();
    updateTime = 10;
}

void Game::addSoldier(Soldier *soldier) {
    army->append(soldier);
}

/// Creates army of soldiers with distance between them
/// @param int army size
void Game::createArmy(int size) {
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getSoldierScene();
    allSquares = field->allSquares;
    distanceX = -20;
    for(int i = 0; i < size; i++) {
        Soldier* soldier = new Soldier();
        addSoldier(soldier);
        soldier->setX(distanceX);
        distanceX = distanceX - 20;
        soldier->setY(350);
        scene->addItem(soldier);
    }
}

void Game::deleteSoldier(Soldier *soldier) {
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

    // X axis values
    int XObjective = static_cast<int>(allSquares[IDObjetive]->x());
    int currentX = static_cast<int>(soldier->x());
    int absXDifference = abs(abs(XObjective) - abs(currentX));

    // Y Axis values
    int YObjective = static_cast<int>(allSquares[IDObjetive]->y());
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
        int endSquareX = static_cast<int>(allSquares[lastID]->x());
        int endSquareY = static_cast<int>(allSquares[lastID]->y());
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

void Game::run() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(updateTime);
}

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
        }
    }
}

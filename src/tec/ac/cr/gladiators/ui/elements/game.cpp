#include "game.h"
#include "../field.h"


// Game is a Singleton
Game *Game::instance = new Game();

Game::Game() {
    // Initialize army and dead army
    army = new QList<Soldier*>();
    deadArmy = new QList<Soldier*>();
}

//! Adds tower area to internal area list
//! \param QGraphicsItem* area to delete
void Game::addArea(QGraphicsItem* area) {
    allAreas.append(area);
}

//! Adds soldier to army
//! \param Soldier* soldier to delete
void Game::addSoldier(Soldier* soldier) {
    army->append(soldier);
}

//! Adds dead soldier to dead army
//! \param Soldier* dead soldier to add
void Game::addWalker(Soldier* soldier) {
    deadArmy->append(soldier);
}

//! Creates army of soldiers with distance between them
//! \param int army size
void Game::createArmy(int size) {
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getScene();

    // Get Gladiators List from server
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    size = gladiatorsList->getLenght();
    allSquares = field->allSquares;
    distanceX = -20;

    // Iteratively creates army
    QRect rect = QRect(0, 0, 15, 15);
    for(int i = 0; i < size; i++) {
        // Soldier atrributes
        Soldier* soldier = new Soldier();
        soldier->id = i;
        soldier->setPen(Qt::NoPen);
        int life = GladiatorsList::getInstance()->getGladiatorLifeByID(i) * 100;
        soldier->setLife(life);
        soldier->fullLife = life;

        // Soldier picture
        QString soldierdir = ":/soldiers/soldiers/soldierFlashRight.png";
        QPixmap sPix = QPixmap(soldierdir);
        soldier->soldierPix = sPix.scaled(15,15);
        soldier->setBrush(soldier->soldierPix);

        // Assign position and add to scene
        soldier->setRect(rect);
        addSoldier(soldier);
        soldier->setX(distanceX);
        distanceX = distanceX - 20;
        soldier->setY(340);
        scene->addItem(soldier);
    }
}

//! Creates boss
void Game::createBoss() {
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getScene();
    distanceX = -20;

    // Define boss atributes
    QRect rect = QRect(0, 0, 40, 40);
    Soldier* boss = new Soldier();
    boss->isBoss = true;
    boss->setPen(Qt::NoPen);
    int life = 50000;
    boss->setLife(life);
    boss->fullLife = life;

    // Set boss picture
    QString bossDir = ":/soldiers/soldiers/BossRight.png";
    QPixmap bPix = QPixmap(bossDir);
    boss->soldierPix = bPix.scaled(40,40);
    boss->setBrush(boss->soldierPix);

    // Add boss to scene
    boss->setRect(rect);
    addSoldier(boss);
    boss->setX(distanceX);
    distanceX = distanceX - 20;
    boss->setY(340);
    scene->addItem(boss);
}

//! Deletes whole army.
void Game::deleteArmy() {
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getScene();

    // Delete gladiator in GladiatorsList
    for (int i = 0; i < gladiatorsList->getLenght(); i++) {
        gladiatorsList->deleteGladiatorByID(i);
    }

    // Delete soldier in arm and resets army
    for (int i = 0; i < army->length(); i++){
        scene->removeItem(army->at(i));
    }
    army->clear();
}

//! Deletes soldier in army.
//! \param Soldier* soldier to delete
void Game::deleteSoldier(Soldier* soldier) {
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    gladiatorsList->deleteGladiatorByID(soldier->id);
    army->removeOne(soldier);
    Field* field = Field::getInstance();
    QGraphicsScene* scene = field->getScene();
    scene->removeItem(soldier);
}

//! Updates soldier position. Loop it for animated results.
//! \param Soldier* to move
void Game::followPath(Soldier* soldier) {
    // Gets specific current square objective for soldier.
    int squareObjective = soldier->currentSquare;
    int IDObjective = path->at(squareObjective);
    soldier->graphicalSquare = IDObjective;

    // Define X and Y values
    int XObjective = 0;
    int currentX = 0;
    int absXDifference = 0;
    int YObjective = 0;
    int currentY = 0;
    int absYDifference = 0;
    int endSquareX = 0;
    int endSquareY = 0;

    // Set X and Y objectives according to next square in path
    if (IDObjective > 0) {
        XObjective = static_cast<int>(allSquares[IDObjective]->x()) + 15;
        YObjective = static_cast<int>(allSquares[IDObjective]->y()) + 15;
    } else {
        // Objective is start or end of field
        if (IDObjective == -1) {
            // Objective is start
            XObjective = 100;
        } else {
            // Objective is end
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
            // Move right
            soldier->setX(soldier->x() + 1);
            QString soldierdir;

            // Assigns correct picture between normal soldier, undead or boss
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashRight.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerRight.png";
            }
            if (soldier->isBoss){
                soldierdir = ":/soldiers/soldiers/bossRight.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            if (soldier->isBoss) {
                soldier->soldierPix = sPix.scaled(40, 40);
            }
            soldier->setBrush(soldier->soldierPix);
        } else {
            // Move left
            soldier->setX(soldier->x() - 1);
            QString soldierdir;

            // Assigns correct picture between normal soldier, undead or boss
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashLeft.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerLeft.png";
            }
            if (soldier->isBoss){
                soldierdir = ":/soldiers/soldiers/bossLeft.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            if (soldier->isBoss) {
                soldier->soldierPix = sPix.scaled(40, 40);
            }
            soldier->setBrush(soldier->soldierPix);
        }
    } else if (absYDifference > 1) {
        // Move up or down.
        if (YObjective > currentY) {
            // Move down
            soldier->setY(soldier->y() + 1);
            QString soldierdir;

            // Assigns correct picture between normal soldier, undead or boss
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashDown.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerDown.png";
            }
            if (soldier->isBoss){
                soldierdir = ":/soldiers/soldiers/bossDown.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            if (soldier->isBoss) {
                soldier->soldierPix = sPix.scaled(40, 40);
            }
            soldier->setBrush(soldier->soldierPix);
        } else {
            // Move up
            soldier->setY(soldier->y() - 1);
            QString soldierdir;

            // Assigns correct picture between normal soldier, undead or boss
            if (!soldier->isUndead) {
                soldierdir = ":/soldiers/soldiers/soldierFlashUp.png";
            } else {
                soldierdir = ":/soldiers/soldiers/walkerUp.png";
            }
            if (soldier->isBoss){
                soldierdir = ":/soldiers/soldiers/bossUp.png";
            }
            QPixmap sPix = QPixmap(soldierdir);
            soldier->soldierPix = sPix.scaled(15,15);
            if (soldier->isBoss) {
                soldier->soldierPix = sPix.scaled(40, 40);
            }
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
                // Soldier has reached end of field
                soldier->done = true;
            } else {
                // Soldier still needs to keep following path
                soldier->advanceSquare();
            }
        }
    }
    soldier->update();
}

//! Sends all army floating
void Game::floatAllToggle() {
    for (int i = 0; i < army->length(); i++) {
        Soldier* currentSoldier = army->at(i);
        currentSoldier->isFloating = true;
    }
}

//! Moves soldier up to make it float. Loop it for animated results.
//! \param Soldier* soldier to make float
void Game::floatSoldier(Soldier* soldier) {
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

//! Gets Game Singleton
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

//! Remove specific area
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

//! Runs game
void Game::run() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(updateTime);
}

//! Toggles if army is frozen
void Game::toggleFreeze() {
    if (frozenArmy) {
        frozenArmy = false;
    } else {
        frozenArmy = true;
    }
}

//! Main game loop.
void Game::updateGame() {
    // Updates each soldier in game.
    for(int i = 0; i < army->length(); i++) {
        Soldier* currentSoldier = army->at(i);
        if (currentSoldier->done) {
            // Soldier is at end of field
            Field* field = Field::getInstance();

            // Lower life accordingly. Boss removes 5 life points
            field->lowerLife();
            if (currentSoldier->isBoss) {
                field->lowerLife();
                field->lowerLife();
                field->lowerLife();
                field->lowerLife();
            }
            deleteSoldier(currentSoldier);
        } else {
            // Main movement game loop
            bool isFloating = currentSoldier->isFloating;

            if (!frozenArmy) {
                if (!isFloating) {
                    // Move soldier, damage it and rotate towers accordingly
                    followPath(currentSoldier);
                    currentSoldier->damage();
                    currentSoldier->checkRotation();
                } else {
                    // If soldier is floating, make it float upwards
                    floatSoldier(currentSoldier);
                }
            } else {
                // If army is frozen, damage soldiers and check for tower rotation, but don't move army
                currentSoldier->damage();
                currentSoldier->checkRotation();
            }
        }
    }
}



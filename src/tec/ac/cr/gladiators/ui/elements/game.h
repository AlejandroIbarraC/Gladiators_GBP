#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTimer>

#include "soldier.h"
#include "customrectitem.h"


class Game : public QObject {
    Q_OBJECT

public:
    int waveCount = 1;

    void addArea(QGraphicsItem* area);
    void addSoldier(Soldier *soldier);
    void addWalker(Soldier *soldier);
    void createArmy(int size);
    void createBoss();
    void deleteArmy();
    void deleteSoldier(Soldier *soldier);
    void floatAllToggle();
    void floatSoldier(Soldier* soldier);
    QList<QGraphicsItem*> getAreas();
    QList<Soldier*>* getDeadArmy() const;
    QList<Soldier*>* getArmy() const;
    static Game* getInstance();
    void pause();
    void play();
    void removeArea(QGraphicsItem* area);
    void run();
    void setArmy(QList<Soldier*> *nArmy);
    void setPath(QList<int>* nPath);
    void setUpdateTime(int nTime);
    void toggleFreeze();


public slots:
    void updateGame();

private:
    Game();
    QList<QGraphicsItem*> allAreas;
    QVector<CustomRectItem*> allSquares;
    QList<Soldier*>* army;
    QList<Soldier*>* deadArmy;
    int distanceX = -20;
    bool frozenArmy = false;
    static Game* instance;
    int lastID;
    QList<int>* path;
    QTimer* timer;
    int updateTime = 15;

    void followPath(Soldier* soldier);
};

#endif // GAME_H

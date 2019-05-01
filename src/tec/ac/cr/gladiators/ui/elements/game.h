#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTimer>

#include "soldier.h"


class Game : public QObject {
    Q_OBJECT

public:
    void addSoldier(Soldier *soldier);
    void createArmy(int size);
    void deleteSoldier(Soldier *soldier);
    QList<Soldier*>* getArmy() const;
    static Game* getInstance();
    void run();
    void setArmy(QList<Soldier*> *nArmy);
    void setPath(QList<int>* nPath);

public slots:
    void updateGame();

private:
    Game();
    QVector<QGraphicsRectItem*> allSquares;
    QList<Soldier*>* army;
    int distanceX = -20;
    static Game* instance;
    int lastID;
    QList<int>* path;
    QTimer* timer;
    int updateTime;

    void followPath(Soldier* soldier);
};
#endif // GAME_H

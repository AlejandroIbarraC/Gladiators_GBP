#ifndef SOLDIER_H
#define SOLDIER_H

#include <QBrush>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

#include "customrectitem.h"
#include "../../logic/GladiatorsList.h"


class Soldier : public QGraphicsRectItem {

public:
    Soldier(QGraphicsRectItem* parent = nullptr);
    int currentSquare = 0;
    int done = false;
    int fullLife = 10000;
    int graphicalSquare;
    int id;
    bool isBoss = false;
    bool isFloating = false;
    bool isUndead = false;
    int lastAD = -1;
    QPixmap soldierPix;

    void advanceSquare();
    void checkRotation();
    void damage();
    void setLife(int nlife);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QMediaPlayer* growl = new QMediaPlayer();
    int life = 200;
    QMediaPlayer* oof = new QMediaPlayer();

};

#endif // SOLDIER_H

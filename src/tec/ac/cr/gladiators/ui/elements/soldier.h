#ifndef SOLDIER_H
#define SOLDIER_H

#include <QDebug>
#include <QObject>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QMediaPlayer>


class Soldier : public QGraphicsRectItem {

public:
    Soldier(QGraphicsRectItem* parent = nullptr);
    int currentSquare = 0;
    int done = false;
    int fullLife = 10000;
    int graphicalSquare;
    int id;
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
    QMediaPlayer* oof = new QMediaPlayer();
    int life = 200;
};

#endif // SOLDIER_H

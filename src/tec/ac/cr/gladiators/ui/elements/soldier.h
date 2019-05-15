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


class Soldier : public QGraphicsRectItem {

public:
    Soldier(QGraphicsRectItem* parent = nullptr);
    int id;
    int currentSquare = 0;
    int done = false;
    int graphicalSquare;

    void advanceSquare();
    void damage();
    void checkDamage();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int life = 200;
};

#endif // SOLDIER_H

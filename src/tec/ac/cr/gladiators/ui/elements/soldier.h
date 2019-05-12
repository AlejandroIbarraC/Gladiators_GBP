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


class Soldier : public QObject, public QGraphicsRectItem {
    Q_OBJECT
    Q_PROPERTY(QRect geometry READ geometry WRITE setGeometry)

public:
    Soldier(QGraphicsRectItem* parent = nullptr);
    int id;
    int currentSquare = 0;
    int done = false;

    void advanceSquare();
    void checkDamage();
    QRect geometry() const;
    void setGeometry(const QRect &value);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QRect rect;
    int life = 10;
};

#endif // SOLDIER_H

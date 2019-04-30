#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPainter>

class Soldier : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QRect geometry READ geometry WRITE setGeometry)
public:
    Soldier(QGraphicsRectItem* parent = nullptr);
    QRect geometry() const;
    void setGeometry(const QRect &value);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

private:
    QRect rect;
};

#endif // SOLDIER_H

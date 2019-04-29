#include "soldier.h"

Soldier::Soldier(QGraphicsRectItem* parent)
{
    rect = QRect(0, 0, 15, 15);
}

QRect Soldier::geometry() const
{
    return rect;
}

void Soldier::setGeometry(const QRect &value)
{
    if(rect!=value){
        rect = value;
        update();
    }
}

QRectF Soldier::boundingRect() const
{
    return QRectF(rect);
}


void Soldier::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(QBrush(Qt::red));
    painter->drawRoundRect(rect);
}

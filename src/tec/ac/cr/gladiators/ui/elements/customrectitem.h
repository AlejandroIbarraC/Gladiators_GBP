#ifndef CUSTOMRECTITEM_H
#define CUSTOMRECTITEM_H

#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>

#include "../field.h"

class CustomRectItem : public QGraphicsRectItem {
public:
    CustomRectItem(QGraphicsRectItem* parent = nullptr);
    int id;
    void setID(int id);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CUSTOMRECTITEM_H

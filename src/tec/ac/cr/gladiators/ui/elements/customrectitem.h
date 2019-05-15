#ifndef CUSTOMRECTITEM_H
#define CUSTOMRECTITEM_H

#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPushButton>


class CustomRectItem : public QGraphicsRectItem {

public:
    CustomRectItem(QGraphicsRectItem* parent = nullptr);
    int id;

    QGraphicsItem* getArea();
    void initializeArea();
    void setID(int id);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsEllipseItem* area;

};

#endif // CUSTOMRECTITEM_H

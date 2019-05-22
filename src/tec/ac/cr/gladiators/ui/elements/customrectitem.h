#ifndef CUSTOMRECTITEM_H
#define CUSTOMRECTITEM_H

#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>


class CustomRectItem : public QGraphicsRectItem {

public:
    CustomRectItem(QGraphicsRectItem* parent = nullptr);
    int damageIndex = 1;
    int id;
    int towerLevel = 1;
    QString towerType;

    QGraphicsItem* getArea();
    void initializeArea();
    void setID(int id);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    QGraphicsEllipseItem* area;

};

#endif // CUSTOMRECTITEM_H

#ifndef DRAGGABLERECTITEM_H
#define DRAGGABLERECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDateTime>
#include <QBrush>

#include "customrectitem.h"
#include "../../logic/pathfinding/Pathfinding.h"
#include "../../logic/pathfinding/PathList.h"


class DraggableRectItem : public QGraphicsRectItem {

public:
    DraggableRectItem(QGraphicsRectItem* parent = nullptr, QString tower = "gatling");
    QPointF anchorPoint;
    QString towerType;

    void setAnchorPoint(const QPointF& anchorPoint);
    int randInt(int low, int high);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsItem* closestItem;
    CustomRectItem* closestSquare;
    QPixmap iconPix;
    QRectF largeRect = QRectF(0,0,70,70);
    bool m_dragged;
    QPixmap towerPix;
    bool safeReturn;
    QRectF smallRect = QRectF(0,0,40,40);
};

#endif // DRAGGABLERECTITEM_H

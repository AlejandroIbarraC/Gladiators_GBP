#ifndef DRAGGABLERECTITEM_H
#define DRAGGABLERECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QDateTime>
#include <QBrush>


class DraggableRectItem : public QGraphicsRectItem {

public:
    QPointF anchorPoint;
    QString towerType;
    DraggableRectItem(QGraphicsRectItem* parent = 0, QString tower = "gatling");
    void setAnchorPoint(const QPointF& anchorPoint);
    int randInt(int low, int high);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    bool m_dragged;
    bool safeReturn;
    QRectF smallRect = QRectF(0,0,40,40);
    QRectF largeRect = QRectF(0,0,70,70);
    QPixmap towerPix;
    QPixmap iconPix;
    QGraphicsItem* closestItem;
    QGraphicsRectItem* closestSquare;
};

#endif // DRAGGABLERECTITEM_H

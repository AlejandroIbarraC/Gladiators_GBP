#ifndef DRAGGABLERECTITEM_H
#define DRAGGABLERECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QDateTime>


class DraggableRectItem : public QGraphicsRectItem {

public:
    QPointF anchorPoint;
    QString letter;
    DraggableRectItem(QGraphicsRectItem* parent = 0);
    void setAnchorPoint(const QPointF& anchorPoint);
    int randInt(int low, int high);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    bool m_dragged;
};

#endif // DRAGGABLERECTITEM_H

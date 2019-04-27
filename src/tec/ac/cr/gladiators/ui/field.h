#ifndef FIELD_H
#define FIELD_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "elements/draggablerectitem.h"

namespace Ui {
class Field;
}

class Field : public QMainWindow
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr, int stage = 1);
    ~Field();

private:
    Ui::Field *ui;
    int columns;
    int rows;
    int startingx;
    int startingy;
    int currentStage;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QVector<QGraphicsRectItem*> allSquares;
    void initializeField();

};

#endif // FIELD_H

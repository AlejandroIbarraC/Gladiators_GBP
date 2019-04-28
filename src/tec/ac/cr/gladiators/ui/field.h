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
    QVector<QGraphicsRectItem*> allSquares;
    int columns;
    int rows;
    static Field* getInstance();
    void opaqueGrid();
    void deOpaqueGrid();
    static void setInstance(Field* nfield);

private:
    Ui::Field *ui;
    int startingx;
    int startingy;
    int currentStage;
    QGraphicsView* view;
    QGraphicsScene* scene;
    void initializeField();
    static Field* field;

};

#endif // FIELD_H

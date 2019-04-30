#ifndef FIELD_H
#define FIELD_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <iostream>
#include <ctime>
#include <QThread>

#include "elements/draggablerectitem.h"
#include "elements/soldier.h"

namespace Ui {
class Field;
}

class Field : public QMainWindow
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr,
                   int stage = 1);
    ~Field();
    QVector<QGraphicsRectItem*> allSquares;
    int columns;
    int rows;
    void delay(int millisecondsToWait);
    void generateArmy(int amount, QList<int>* path);
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
    QGraphicsView* soldier_view;
    QGraphicsScene* scene;
    QGraphicsScene* soldier_scene;
    QParallelAnimationGroup group;

    void animateSoldier(Soldier* soldier, QList<int>* path, int speed);
    void initializeField();
    static Field* field;

private slots:
    void on_playButton_clicked();

};

#endif // FIELD_H

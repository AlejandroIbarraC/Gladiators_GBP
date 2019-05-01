#ifndef FIELD_H
#define FIELD_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QGraphicsView>
#include <iostream>

#include "elements/customrectitem.h"
#include "elements/draggablerectitem.h"
#include "elements/soldier.h"
#include "elements/game.h"

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
    QVector<CustomRectItem*> allSquares;
    int columns;
    int rows;

    void lowerLife();
    static Field* getInstance();
    QGraphicsScene* getScene();
    QGraphicsScene* getSoldierScene();
    void opaqueGrid();
    void deOpaqueGrid();
    static void setInstance(Field* nfield);
    void setSoldierScene(QGraphicsScene* newScene);

private:
    int life = 20;
    int startingx;
    int startingy;
    int currentStage;
    Game* game;
    QGraphicsView* view;
    QGraphicsView* soldier_view;
    QGraphicsScene* scene;
    QGraphicsScene* soldier_scene;
    Ui::Field *ui;

    void animateSoldier(Soldier* soldier, QList<int>* path, int speed);
    void initializeField();
    static Field* field;

private slots:
    void on_playButton_clicked();

};

#endif // FIELD_H

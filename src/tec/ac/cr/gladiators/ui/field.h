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
    QList<int>* damageMatrix;
    int rows;

    void addTower(int id);
    void assignDamageMatrix(int id);
    void deleteTower(int id);
    void lowerLife();
    static Field* getInstance();
    QGraphicsScene* getScene();
    QGraphicsScene* getSoldierScene();
    QList<int>* idToCoords(int id);
    void opaqueGrid();
    void deOpaqueGrid();
    static void setInstance(Field* nfield);
    void setSoldierScene(QGraphicsScene* newScene);
    void setSoldierLabels();
    int squareToID(CustomRectItem* square);

private:
    int life = 20;
    int startingx;
    int startingy;
    int currentStage;
    int fieldMatrix[11][19] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    Game* game;
    QGraphicsView* view;
    QGraphicsView* soldier_view;
    QGraphicsScene* scene;
    QGraphicsScene* soldier_scene;
    Ui::Field *ui;

    void initializeField();
    static Field* field;

private slots:
    void on_playButton_clicked();
    void on_skipButton_pressed();

};

#endif // FIELD_H

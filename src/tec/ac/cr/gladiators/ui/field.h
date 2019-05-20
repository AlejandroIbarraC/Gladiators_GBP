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
#include "elements/buttonhoverwatcher.h"

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
    int cityMatrix[8][17] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int columns;
    QList<int>* damageMatrix;
    QMediaPlayer* ding = new QMediaPlayer();
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
    QMediaPlayer* growl = new QMediaPlayer();
    QMediaPlayer* rewind = new QMediaPlayer();
    QMediaPlayer* roar = new QMediaPlayer();
    QMediaPlayer* roll = new QMediaPlayer();
    int rows;
    QMediaPlayer* snap = new QMediaPlayer();
    int towerIndex = 0;
    QList<int>* towerList;
    QMediaPlayer* trumpet = new QMediaPlayer();

    void addTower(int id);
    void assignDamageMatrix(int id);
    int currentStage;
    void deleteTower(int id);
    QList<int>* findCoverage(int id);
    void deOpaqueGrid();
    void deOpaqueID(int id);
    void lowerLife();
    QList<int>* getBlockedIDList();
    static Field* getInstance();
    QList<int>* getPath();
    QGraphicsScene* getScene();
    QGraphicsScene* getSoldierScene();
    QList<int>* idToCoords(int id);
    void opaqueGrid();
    void paintPath(QList<int>* path);
    void resetField();
    static void setInstance(Field* nfield);
    void setSoldierScene(QGraphicsScene* newScene);
    void setSoldierLabels();
    int squareToID(CustomRectItem* square);
    void unassignDamageMatrix(int id);

private:
    static Field* field;
    Game* game;
    int life = 20;
    bool pathAlgorithm = true;
    QGraphicsScene* scene;
    QGraphicsScene* soldier_scene;
    QGraphicsView* soldier_view;
    int startingx;
    int startingy;
    QGraphicsView* view;
    Ui::Field *ui;

    void initializeField();

private slots:
    void on_fastForwardButton_clicked();
    void on_nextButton_clicked();
    void on_nightKingButton_clicked();
    void on_pauseButton_clicked();
    void on_playButton_clicked();
    void on_resetButton_clicked();
    void on_thanosButton_clicked();
    void on_skipButton_clicked();

};

#endif // FIELD_H

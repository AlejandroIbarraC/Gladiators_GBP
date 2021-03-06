#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsView>
#include <QMainWindow>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QTimer>
#include <QPropertyAnimation>

#include "elements/customrectitem.h"
#include "elements/draggablerectitem.h"
#include "elements/soldier.h"
#include "elements/game.h"
#include "elements/buttonhoverwatcher.h"
#include "endgame.h"
#include "../client/Client.h"
#include "../logic/GladiatorsList.h"
#include "../logic/pathfinding/Pathfinding.h"
#include "../logic/pathfinding/PathList.h"


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
    int currentStage;
    QList<int>* damageMatrix;
    QMediaPlayer* ding = new QMediaPlayer();
    QMediaPlayer* dracarys = new QMediaPlayer();
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
    QMediaPlayer* fly = new QMediaPlayer();
    QMediaPlayer* freeze = new QMediaPlayer();
    QMediaPlayer* growl = new QMediaPlayer();
    QMediaPlayer* rewind = new QMediaPlayer();
    QMediaPlayer* roar = new QMediaPlayer();
    QMediaPlayer* roll = new QMediaPlayer();
    int rows;
    QMediaPlayer* snap = new QMediaPlayer();
    QMediaPlayer* startup = new QMediaPlayer();
    int towerIndex = 0;
    QList<int>* towerList;
    QMediaPlayer* trumpet = new QMediaPlayer();

    void addMoney();
    void addTower(int id);
    void assignDamageMatrix(int id);
    void deleteTower(int id);
    void deOpaqueGrid();
    void deOpaqueID(int id);
    void endGame();
    QList<int>* findCoverage(int id);
    void lowerLife();
    QList<int>* getBlockedIDList();
    static Field* getInstance();
    QList<int>* getPath();
    int getMoney();
    QGraphicsScene* getScene();
    QGraphicsScene* getSoldierScene();
    QList<int>* idToCoords(int id);
    void opaqueGrid();
    void paintPath(QList<int>* path);
    int randInt(int low, int high);
    void resetField();
    static void setInstance(Field* nfield);
    void setMoney(int nmoney);
    void setSoldierScene(QGraphicsScene* newScene);
    void setSoldierLabels();
    int squareToID(CustomRectItem* square);
    void unassignDamageMatrix(int id);

private:
    QList<int>* blockedIDs;
    EndGame* endGame_window;
    static Field* field;
    QTimer* freezeTimer;
    Game* game;
    int life = 20;
    int money = 20;
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
    void freeze_aux();
    void on_dracarysButton_clicked();
    void on_fastForwardButton_clicked();
    void on_flyButton_clicked();
    void on_frozenButton_clicked();
    void on_fullresetButton_clicked();
    void on_nextButton_clicked();
    void on_nightKingButton_clicked();
    void on_pauseButton_clicked();
    void on_playButton_clicked();
    void on_resetButton_clicked();
    void on_skipButton_clicked();
    void on_thanosButton_clicked();

};

#endif // FIELD_H

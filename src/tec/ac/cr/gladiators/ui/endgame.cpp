#include "endgame.h"
#include "ui_endgame.h"

EndGame::EndGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndGame)
{
    ui->setupUi(this);
}

EndGame::~EndGame()
{
    delete ui;
}

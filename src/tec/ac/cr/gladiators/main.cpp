#include <iostream>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QApplication>
#include <QTime>

#include "client/Client.h"
#include "logic/GladiatorsList.h"
#include "logic/TowersList.h"
#include "ui/menu.h"
#include "logic/pathfinding/Pathfinding.h"


using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Menu w;
    w.show();
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    return a.exec();

}

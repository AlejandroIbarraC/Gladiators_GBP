#include <iostream>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include "client/Client.h"
#include "logic/GladiatorsList.h"
#include "logic/TowersList.h"

using namespace std;

int main() {

/*    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    gladiatorsList->addGladiator(1, 1, 1, 1, 1, 1, 1, 1, 1);
    gladiatorsList->addGladiator(2, 2, 2, 2, 2, 2, 2, 2, 2);
    gladiatorsList->addGladiator(3, 3, 3, 3, 3, 3, 3, 3, 3);
    QJsonArray jsonArray = gladiatorsList->serialize();

    QJsonDocument jsonDocument(jsonArray);
    QByteArray byteArray = jsonDocument.toJson();
    QString qString = QString(byteArray);
    string string = qString.toStdString();
    cout << string << endl;

    gladiatorsList->deserialize(jsonArray);*/

    TowersList* towersList = TowersList::getInstance();
    towersList->createTowers(3);
    QJsonArray jsonArray = towersList->serialize();

    QJsonDocument jsonDocument(jsonArray);
    QByteArray byteArray = jsonDocument.toJson();
    QString qString = QString(byteArray);
    string string = qString.toStdString();
    cout << string << endl;

    towersList->deserialize(jsonArray);

    return 0;
}
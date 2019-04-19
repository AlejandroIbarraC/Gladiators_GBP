//
// Created by kevin on 18/04/19.
//

#ifndef GLADIATORS_GBP_TOWERSLIST_H
#define GLADIATORS_GBP_TOWERSLIST_H


#include "Towers.h"

class TowersList {

public:

    static TowersList* getInstance();
    static void setInstance(TowersList* towersList);

    Towers *getHead() const;
    void setHead(Towers *head);
    int getLenght() const;
    void setLenght(int lenght);
    void createTowers(int num);
    void addTower(int typeOfAmmo, int damageOutput, int range);
    void addCreatedTower(Towers* towers);
    void deleteAll();
    QJsonArray serialize();
    static void deserialize(QJsonArray jsonArray);

private:

    TowersList() = default;
    TowersList(TowersList const&)= default;
    TowersList& operator = (TowersList const&) = default;

    static TowersList* towersList;
    Towers* head = nullptr;
    int lenght = 0;

};


#endif //GLADIATORS_GBP_TOWERSLIST_H

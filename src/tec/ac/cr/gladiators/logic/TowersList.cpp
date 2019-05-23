//
// Created by kevin on 18/04/19.
//

#include <iostream>
#include <QtCore/QJsonArray>
#include "TowersList.h"

using namespace std;

TowersList* TowersList::towersList = nullptr;
Towers* TowersList::head = nullptr;

TowersList* TowersList::getInstance() {
    if (!towersList){
        towersList = new TowersList();
    }
    return towersList;
}

void TowersList::setInstance(TowersList* towersList) {
    TowersList::towersList = towersList;
}

Towers *TowersList::getHead() const {
    return head;
}

void TowersList::setHead(Towers* head) {
    TowersList::head = head;
}

int TowersList::getLenght() const {
    return lenght;
}

void TowersList::setLenght(int lenght) {
    TowersList::lenght = lenght;
}

//! Adds a tower to the list
//! \param typeOfAmmo number of the tower
//! \param damageOutput number of the tower
//! \param range number of the tower
void TowersList::addTower(int typeOfAmmo, int damageOutput, int range) {
    if (this->head == nullptr){
        this->head = new Towers(typeOfAmmo, damageOutput, range);
        this->lenght++;
    }else{
        Towers* tmp = this->head;
        while (tmp->getNext() != nullptr){
            tmp = tmp->getNext();
        }
        tmp->setNext(new Towers(typeOfAmmo, damageOutput, range));
        this->lenght++;
    }
}

//! Adds a tower to the list that was previously created
//! \param towers that will be added
void TowersList::addCreatedTower(Towers* towers) {
    if (this->head == nullptr){
        this->head = towers;
        this->lenght++;
    }else{
        Towers* tmp = this->head;
        while (tmp->getNext() != nullptr){
            tmp = tmp->getNext();
        }
        tmp->setNext(towers);
        this->lenght++;
    }
}

//! Deletes all towers from the list
void TowersList::deleteAll() {
    if (!towersList){
        towersList = new TowersList();
    }else if (this->head == nullptr){
        cout << "Error, no hay torres por borrar" << endl;
    }else{
        Towers* toDel = this->head;
        Towers* tmp = this->head->getNext();
        while (tmp != nullptr){
            delete toDel;
            toDel = tmp;
            tmp = tmp->getNext();
        }
        delete toDel;
        this->lenght = 0;
        this->head = nullptr;
    }
}

//! Serializes the towerList
//! \return json with the towers
QJsonArray TowersList::serialize() {
    if (head == nullptr){
        cout << "Error, no hay lista para serializar" << endl;
    }else{
        QJsonArray jsonArray;
        Towers* tmp = head;
        while (tmp != nullptr){
            jsonArray.append(tmp->serialize());
            tmp = tmp->getNext();
        }
        return jsonArray;
    }
}

//! Deserializes a received towerList
//! \param jsonArray with the towers data
void TowersList::deserialize(QJsonArray jsonArray) {
    towersList->deleteAll();
    if (!jsonArray.empty()) {
        for (int i = 0; i < jsonArray.size(); i++) {
            QJsonObject node = jsonArray[i].toObject();
            Towers *tmp = new Towers();
            tmp->deserialize(node);
            towersList->addCreatedTower(tmp);
        }
    }
    else {
        towersList->head = nullptr;
    }
}

//! Returns the damageOutput of a tower
//! \param pos where the tower is in the list
//! \return the damageOutput of the tower
int TowersList::getTowersByPosition(int pos) {
    if (this->head == nullptr){
        cout << "Error, nothing found" << endl;
    }else{
        Towers* towers = this->head;
        int i = 0;
        while (towers != nullptr){
            if (i == pos){
                return towers->getDamageOutput();
            }else{
                towers = towers->getNext();
                i++;
            }
        }
    }
}
//
// Created by kevin on 18/04/19.
//

#include <iostream>
#include <QtCore/QJsonArray>
#include "GladiatorsList.h"

using namespace std;

GladiatorsList* GladiatorsList::gladiatorsList = nullptr;
Gladiators* GladiatorsList::head = nullptr;

GladiatorsList* GladiatorsList::getInstance() {
    if (!gladiatorsList){
        gladiatorsList = new GladiatorsList();
    }
    return gladiatorsList;
}

void GladiatorsList::setInstance(GladiatorsList* gladiatorsList) {
    GladiatorsList::gladiatorsList = gladiatorsList;
}

Gladiators* GladiatorsList::getHead() const {
    return head;
}

void GladiatorsList::setHead(Gladiators* head) {
    GladiatorsList::head = head;
}

int GladiatorsList::getLenght() const {
    return lenght;
}

void GladiatorsList::setLenght(int lenght) {
    GladiatorsList::lenght = lenght;
}

//Temporal para pruebas, los gladiadores se crean en el server
void GladiatorsList::createGladiators(int num) {
    for (int i = 1; i < (num + 1); i++){
        addGladiator(i, i, i, i, i, i, i, i, i);
    }
}

void GladiatorsList::addGladiator(int identification, int ageNumber, int probability, int gensToSurvive, int emotionInteligence, int condition, int strenghtUT, int strenghtLT, int calculatedResistence) {
    if (this->head == nullptr){
        this->head = new Gladiators(identification, ageNumber, probability, gensToSurvive, emotionInteligence, condition, strenghtUT, strenghtLT, calculatedResistence);
        this->lenght++;
    }else{
        Gladiators* tmp = this->head;
        while (tmp->getNext() != nullptr){
            tmp = tmp->getNext();
        }
        tmp->setNext(new Gladiators(identification, ageNumber, probability, gensToSurvive, emotionInteligence, condition, strenghtUT, strenghtLT, calculatedResistence));
        this->lenght++;
    }
}

void GladiatorsList::addCreatedGladiator(Gladiators* gladiators) {
    if (this->head == nullptr){
        this->head = gladiators;
        this->lenght++;
    }else{
        Gladiators* tmp = this->head;
        while (tmp->getNext() != nullptr){
            tmp = tmp->getNext();
        }
        tmp->setNext(gladiators);
        this->lenght++;
    }
}

void GladiatorsList::deleteGladiatorByID(int id) {
    if (this->head == nullptr){
        cout << "Error, no gladiators in list" << endl;
    }else if (this->head->getId() == id){
        Gladiators* toDel = this->head;
        this->head = this->head->getNext();
        delete toDel;
        this->lenght--;
    }else{
        Gladiators* tmp = this->head;
        while (tmp->getNext() != nullptr){
            if (tmp->getNext()->getId() == id){
                Gladiators* toDel = tmp->getNext();
                tmp->setNext(tmp->getNext()->getNext());
                this->lenght--;
                delete toDel;
                break;
            }
            tmp = tmp->getNext();
        }
    }
}

void GladiatorsList::deleteAll() {
    if (!gladiatorsList){
        gladiatorsList = new GladiatorsList();
    }else if (this->head == nullptr){
        cout << "Error, no hay gladiadores por borrar" << endl;
    }else{
        Gladiators* toDel = this->head;
        Gladiators* tmp = this->head->getNext();
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

QJsonArray GladiatorsList::serialize() {
    if (head == nullptr){
        cout << "Error, no hay lista para serializar" << endl;
    }else{
        QJsonArray jsonArray;
        Gladiators* tmp = head;
        while (tmp != nullptr){
            jsonArray.append(tmp->serialize());
            tmp = tmp->getNext();
        }
        return jsonArray;
    }
}

void GladiatorsList::deserialize(QJsonArray jsonArray) {
    gladiatorsList->deleteAll();
    if (!jsonArray.empty()){
        for (int i = 0; i < jsonArray.size(); i++){
            QJsonObject node = jsonArray[i].toObject();
            Gladiators* tmp = new Gladiators();
            tmp->deserialize(node);
            gladiatorsList->addCreatedGladiator(tmp);
        }
    }else{
        gladiatorsList->head = nullptr;
    }
}

void GladiatorsList::setSoldierToShowByID(int id) {
    if (this->head == nullptr){
        cout << "Error, no gladiators in list" << endl;
    }else if (this->head->getId() == id){
        this->soldierToShow = this->head;
    }else{
        Gladiators* tmp = this->head;
        while (tmp->getNext() != nullptr){
            if (tmp->getNext()->getId() == id){
                this->soldierToShow = tmp->getNext();
                break;
            }
            tmp = tmp->getNext();
        }
    }
}



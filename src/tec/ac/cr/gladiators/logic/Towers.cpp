//
// Created by kevin on 18/04/19.
//

#include "Towers.h"

Towers *Towers::getNext() const {
    return next;
}

void Towers::setNext(Towers *next) {
    Towers::next = next;
}

int Towers::getTypeOfAmmo() const {
    return typeOfAmmo;
}

void Towers::setTypeOfAmmo(int typeOfAmmo) {
    Towers::typeOfAmmo = typeOfAmmo;
}

int Towers::getDamageOutput() const {
    return damageOutput;
}

void Towers::setDamageOutput(int damageOutput) {
    Towers::damageOutput = damageOutput;
}

int Towers::getRange() const {
    return range;
}

void Towers::setRange(int range) {
    Towers::range = range;
}

//! Serializes a tower that will be sent
//! \return json of the tower
QJsonObject Towers::serialize() {
    QJsonObject jsonObject;
    jsonObject["typeOfAmmo"] = typeOfAmmo;
    jsonObject["damageOutput"] = damageOutput;
    jsonObject["range"] = range;
    return jsonObject;
}

//! Deserializes a tower that was received
//! \param jsonObject with the tower data
void Towers::deserialize(QJsonObject jsonObject) {
    typeOfAmmo = jsonObject["typeOfAmmo"].toInt();
    damageOutput = jsonObject["damageOutput"].toInt();
    range = jsonObject["range"].toInt();
}
//
// Created by kevin on 18/04/19.
//

#ifndef GLADIATORS_GBP_TOWERS_H
#define GLADIATORS_GBP_TOWERS_H


#include <QtCore/QJsonObject>

class Towers {

public:

    Towers(int typeOfTheAmmo, int damageOfTheAmmo, int rangeOfTheAmmo){
        this->typeOfAmmo = typeOfTheAmmo;
        this->damageOutput = damageOfTheAmmo;
        this->range = rangeOfTheAmmo;
    }

    Towers() = default;

    Towers* getNext() const;
    void setNext(Towers* next);
    int getTypeOfAmmo() const;
    void setTypeOfAmmo(int typeOfAmmo);
    int getDamageOutput() const;
    void setDamageOutput(int damageOutput);
    int getRange() const;
    void setRange(int range);
    QJsonObject serialize();
    void deserialize(QJsonObject jsonObject);

private:

    Towers* next = nullptr;
    int typeOfAmmo;
    int damageOutput;
    int range;

};


#endif //GLADIATORS_GBP_TOWERS_H

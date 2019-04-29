//
// Created by kevin on 18/04/19.
//

#ifndef GLADIATORS_GBP_GLADIATORSLIST_H
#define GLADIATORS_GBP_GLADIATORSLIST_H


#include <QtCore/QJsonObject>
#include "Gladiators.h"

class GladiatorsList {

public:

    static GladiatorsList* getInstance();
    static void setInstance(GladiatorsList* gladiatorsList);

    Gladiators *getHead() const;
    void setHead(Gladiators *head);
    int getLenght() const;
    void setLenght(int lenght);
    void createGladiators(int num);
    void addGladiator(int identification, int ageNumber, int probability, int gensToSurvive, int emotionInteligence, int condition, int strenghtUT, int strenghtLT, int calculatedResistence);
    void addCreatedGladiator(Gladiators* gladiators);
    void deleteGladiatorByID(int id);
    void deleteAll();
    static QJsonArray serialize();
    static void deserialize(QJsonArray jsonArray);

private:

    GladiatorsList() = default;
    GladiatorsList(GladiatorsList const&)= default;
    GladiatorsList& operator = (GladiatorsList const&) = default;

    static GladiatorsList* gladiatorsList;
    static Gladiators* head;
    int lenght = 0;

};


#endif //GLADIATORS_GBP_GLADIATORSLIST_H

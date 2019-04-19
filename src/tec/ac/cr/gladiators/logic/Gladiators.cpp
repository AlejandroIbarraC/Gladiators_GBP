//
// Created by kevin on 18/04/19.
//

#include "Gladiators.h"

Gladiators *Gladiators::getNext() const {
    return next;
}

void Gladiators::setNext(Gladiators *next) {
    Gladiators::next = next;
}

int Gladiators::getId() const {
    return id;
}

void Gladiators::setId(int id) {
    Gladiators::id = id;
}

int Gladiators::getAge() const {
    return age;
}

void Gladiators::setAge(int age) {
    Gladiators::age = age;
}

int Gladiators::getSurvivalProbability() const {
    return survivalProbability;
}

void Gladiators::setSurvivalProbability(int survivalProbability) {
    Gladiators::survivalProbability = survivalProbability;
}

int Gladiators::getHowManyGensWillSurvive() const {
    return howManyGensWillSurvive;
}

void Gladiators::setHowManyGensWillSurvive(int howManyGensWillSurvive) {
    Gladiators::howManyGensWillSurvive = howManyGensWillSurvive;
}

int Gladiators::getEmotionalInteligence() const {
    return emotionalInteligence;
}

void Gladiators::setEmotionalInteligence(int emotionalInteligence) {
    Gladiators::emotionalInteligence = emotionalInteligence;
}

int Gladiators::getPhysicalCondition() const {
    return physicalCondition;
}

void Gladiators::setPhysicalCondition(int physicalCondition) {
    Gladiators::physicalCondition = physicalCondition;
}

int Gladiators::getStrenghtInUpperTrunk() const {
    return strenghtInUpperTrunk;
}

void Gladiators::setStrenghtInUpperTrunk(int strenghtInUpperTrunk) {
    Gladiators::strenghtInUpperTrunk = strenghtInUpperTrunk;
}

int Gladiators::getStrenghtInLowerTrunk() const {
    return strenghtInLowerTrunk;
}

void Gladiators::setStrenghtInLowerTrunk(int strenghtInLowerTrunk) {
    Gladiators::strenghtInLowerTrunk = strenghtInLowerTrunk;
}

int Gladiators::getResistence() const {
    return resistence;
}

void Gladiators::setResistence(int resistence) {
    Gladiators::resistence = resistence;
}


QJsonObject Gladiators::serialize() {
    QJsonObject jsonObject;
    jsonObject["id"] = id;
    jsonObject["age"] = age;
    jsonObject["survivalProbability"] = survivalProbability;
    jsonObject["howManyGensWillSurvive"] = howManyGensWillSurvive;
    jsonObject["emotionalInteligence"] = emotionalInteligence;
    jsonObject["physicalCondition"] = physicalCondition;
    jsonObject["strenghtInUpperTrunk"] = strenghtInUpperTrunk;
    jsonObject["strenghtInLowerTrunk"] = strenghtInLowerTrunk;
    jsonObject["resistence"] = resistence;
    return jsonObject;
}

void Gladiators::deserialize(QJsonObject jsonObject) {
    id = jsonObject["id"].toInt();
    age = jsonObject["age"].toInt();
    survivalProbability = jsonObject["survivalProbability"].toInt();
    howManyGensWillSurvive = jsonObject["howManyGensWillSurvive"].toInt();
    emotionalInteligence = jsonObject["emotionalInteligence"].toInt();
    physicalCondition = jsonObject["physicalCondition"].toInt();
    strenghtInUpperTrunk = jsonObject["strenghtInUpperTrunk"].toInt();
    strenghtInLowerTrunk = jsonObject["strenghtInLowerTrunk"].toInt();
    resistence = jsonObject["resistence"].toInt();
}

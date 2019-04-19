//
// Created by kevin on 18/04/19.
//

#ifndef GLADIATORS_GBP_GLADIATORS_H
#define GLADIATORS_GBP_GLADIATORS_H

#include <QtCore/QJsonObject>

class Gladiators {

public:

    Gladiators(int identification, int ageNumber, int probability, int gensToSurvive, int emotionInteligence, int condition, int strenghtUT, int strenghtLT, int calculatedResistence){
        this->id = identification;
        this->age = ageNumber;
        this->survivalProbability = probability;
        this->howManyGensWillSurvive = gensToSurvive;
        this->emotionalInteligence = emotionInteligence;
        this->physicalCondition = condition;
        this->strenghtInUpperTrunk = strenghtUT;
        this->strenghtInLowerTrunk = strenghtLT;
        this->resistence = calculatedResistence;
    }

    Gladiators() = default;

    Gladiators* getNext() const;
    void setNext(Gladiators* next);
    int getId() const;
    void setId(int id);
    int getAge() const;
    void setAge(int age);
    int getSurvivalProbability() const;
    void setSurvivalProbability(int survivalProbability);
    int getHowManyGensWillSurvive() const;
    void setHowManyGensWillSurvive(int howManyGensWillSurvive);
    int getEmotionalInteligence() const;
    void setEmotionalInteligence(int emotionalInteligence);
    int getPhysicalCondition() const;
    void setPhysicalCondition(int physicalCondition);
    int getStrenghtInUpperTrunk() const;
    void setStrenghtInUpperTrunk(int strenghtInUpperTrunk);
    int getStrenghtInLowerTrunk() const;
    void setStrenghtInLowerTrunk(int strenghtInLowerTrunk);
    int getResistence() const;
    void setResistence(int resistence);
    QJsonObject serialize();
    void deserialize(QJsonObject jsonObject);

private:

    Gladiators* next = nullptr;
    int id;
    int age;
    int survivalProbability;
    int howManyGensWillSurvive;
    int emotionalInteligence;
    int physicalCondition;
    int strenghtInUpperTrunk;
    int strenghtInLowerTrunk;
    int resistence;

};


#endif //GLADIATORS_GBP_GLADIATORS_H

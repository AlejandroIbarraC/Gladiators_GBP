//
// Created by kevin on 15/04/19.
//

#include "Client.h"
#include "../logic/GladiatorsList.h"
#include "../logic/TowersList.h"
#include <iostream>
#include <cpr/cpr.h>
#include <QtCore/QJsonDocument>

using namespace std;

void Client::retrieveGladiators() {

    future<QJsonArray> fn = async(launch::async, getGladiators);
    QJsonArray jsonArray = fn.get();
    GladiatorsList::deserialize(jsonArray);

}

QJsonArray Client::getGladiators() {

    auto response = cpr::Get(cpr::Url{"http://192.168.100.6:9080/Gladiators_GBP_war_exploded/genetics/populations/gladiators"});
    string jsonString = response.text;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(QByteArray(jsonString.c_str()));
    return jsonDocument.array();

}

void Client::retrieveTowers() {

    future<QJsonArray> fn = async(launch::async, getTowers);
    QJsonArray jsonArray = fn.get();
    TowersList::deserialize(jsonArray);

}

QJsonArray Client::getTowers() {

    auto response = cpr::Get(cpr::Url{"http://192.168.100.6:9080/Gladiators_GBP_war_exploded/genetics/populations/towers"});
    string jsonString = response.text;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(QByteArray(jsonString.c_str()));
    return jsonDocument.array();

}



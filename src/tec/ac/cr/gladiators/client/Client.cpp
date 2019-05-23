//
// Created by kevin on 15/04/19.
//

#include "Client.h"
#include "../logic/GladiatorsList.h"
#include "../logic/TowersList.h"
#include "../ui/field.h"
#include <iostream>
#include <cpr/cpr.h>
#include <QtCore/QJsonDocument>

using namespace std;

int Client::skipNumber = 0;
string Client::ip = "192.168.43.10";

void Client::retrieveGladiators() {

    future<QJsonArray> fn = async(launch::async, getGladiators);
    QJsonArray jsonArray = fn.get();
    GladiatorsList::deserialize(jsonArray);

}

QJsonArray Client::getGladiators() {

    auto response = cpr::Get(cpr::Url{"http://" + ip + ":9080/Gladiators_GBP_war_exploded/genetics/populations/gladiators"});
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

    auto response = cpr::Get(cpr::Url{"http://" + ip + ":9080/Gladiators_GBP_war_exploded/genetics/populations/towers"});
    string jsonString = response.text;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(QByteArray(jsonString.c_str()));
    return jsonDocument.array();

}

void Client::sendGladiatorsData() {

    future<void> fn = async(launch::async, postGladiators);
    fn.get();

}

void Client::postGladiators() {

    auto response = cpr::Post(cpr::Url{"http://" + ip + ":9080/Gladiators_GBP_war_exploded/genetics/populations/gladiators/stats"});

}

void Client::sendTowersData() {

    future<void> fn = async(launch::async, postTowers);
    fn.get();

}

void Client::postTowers() {

    auto response = cpr::Post(cpr::Url{"http://" + ip + ":9080/Gladiators_GBP_war_exploded/genetics/populations/towers/stats"});

}

void Client::reset() {

    future<void> fn = async(launch::async, postReset);
    fn.get();

}

void Client::postReset() {

    auto response = cpr::Post(cpr::Url{"http://" + ip + ":9080/Gladiators_GBP_war_exploded/genetics/populations"});

}

void Client::skip() {

    future<void> fn = async(launch::async, postSkip);
    fn.get();

}

void Client::postSkip() {

    Gladiators gladiators(1, skipNumber, 1, 1, 1, 1, 1, 1, 1);
    QJsonDocument jsonDocument(gladiators.serialize());
    QByteArray byteArray = jsonDocument.toJson();
    QString qString = QString(byteArray);
    string str = qString.toStdString();
    auto response = cpr::Post(cpr::Url{"http://" + ip + ":9080/Gladiators_GBP_war_exploded/genetics/populations/skip"}, cpr::Body{str}, cpr::Header{{"Content-Type", "application/json"}});

}

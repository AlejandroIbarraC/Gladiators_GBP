//
// Created by kevin on 15/04/19.
//

#ifndef GLADIATORS_GBP_CLIENT_H
#define GLADIATORS_GBP_CLIENT_H


#include <QtCore/QJsonArray>

using namespace std;

class Client{

public:

    static int skipNumber;
    static string ip;

    static void retrieveGladiators();
    static void retrieveTowers();
    static void sendGladiatorsData();
    static void sendTowersData();
    static void reset();
    static void skip();

private:

    static QJsonArray getGladiators();
    static QJsonArray getTowers();
    static void postGladiators();
    static void postTowers();
    static void postReset();
    static void postSkip();

};


#endif //GLADIATORS_GBP_CLIENT_H

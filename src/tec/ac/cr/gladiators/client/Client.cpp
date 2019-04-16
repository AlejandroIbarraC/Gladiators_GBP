//
// Created by kevin on 15/04/19.
//

#include "Client.h"
#include <iostream>
#include <cpr/cpr.h>

void Client::connectTo() {

    auto response = cpr::Get(cpr::Url{"http://192.168.100.5:9080/Gladiators_GBP_war_exploded/genetics/populations/"});
    std::cout << response.text << std::endl;

}

#ifndef GALAXY_B03_FUNCTIONS_H
#define GALAXY_B03_FUNCTIONS_H
#include <iostream>
#include "spaceObjects.h"
#include "spaceShip.h"

using namespace std;

class functions {
public:
    static pair<unsigned int, unsigned int> attraction(const spaceObjects& Slave, const spaceObjects& Master) ;
    static void runUdpClient(sf::RenderWindow& window, spaceShip, unsigned short port = 50001);
};

#endif //GALAXY_B03_FUNCTIONS_H
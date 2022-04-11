#ifndef GALAXY_B03_FUNCTIONS_H
#define GALAXY_B03_FUNCTIONS_H
#include <iostream>
#include "spaceObjects.h"
#include "spaceShip.h"

using namespace std;

class functions {
public:
    static pair<unsigned int, unsigned int> attraction(const spaceShip& Slave, const spaceObjects& Master) ;
};

#endif //GALAXY_B03_FUNCTIONS_H
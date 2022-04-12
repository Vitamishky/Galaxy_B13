

#ifndef GALAXY_B03_FUNCTIONS_H
#define GALAXY_B03_FUNCTIONS_H
#include <iostream>
#include "spaceObjects.h"
#include "Planet.h"
#include "spaceShip.h"

using namespace std;

class functions {
public:
    static pair<float, float> planetAttraction(const spaceObjects& Slave, const Planet& Master) ;
};

#endif //GALAXY_B03_FUNCTIONS_H
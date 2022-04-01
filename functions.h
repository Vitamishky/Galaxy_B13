

#ifndef GALAXY_B03_FUNCTIONS_H
#define GALAXY_B03_FUNCTIONS_H
#include <iostream>
#include "spaceObjects.h"

using namespace std;

class functions {
public:
    static pair<float, float> attraction(const spaceObjects& Slave, const spaceObjects& Master) ;
};

#endif //GALAXY_B03_FUNCTIONS_H
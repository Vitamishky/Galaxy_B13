#ifndef GALAXY_B13_MODULE_H
#define GALAXY_B13_MODULE_H
#include "spaceObjects.h"

class MODULE: public spaceObjects{
private:
    pair<float,float> acceleration;
public:
    MODULE();
    void draw(float x, float y, pair<float,float> direction);
    pair<float,float> Acceleration() const;
    void editAcceleration(float, float);
};

#endif //GALAXY_B13_MODULE_H

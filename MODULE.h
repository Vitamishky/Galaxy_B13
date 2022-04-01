#ifndef GALAXY_B13_MODULE_H
#define GALAXY_B13_MODULE_H
#include "spaceObjects.h"

class MODULE: public spaceObjects{
private:
    pair<float,float> acceleration;
    float potAcceleration;
public:
    bool IsController = false;
    bool IsEngine = false;
    bool IsTurner = false;
    void draw(float x, float y, pair<float,float> direction);
    pair<float,float> Acceleration() const;
    float PotAcceleration() const;
    void EditAcceleration(pair<float, float>);
};

#endif //GALAXY_B13_MODULE_H

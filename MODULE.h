#ifndef GALAXY_B13_MODULE_H
#define GALAXY_B13_MODULE_H
#include "spaceObjects.h"

class MODULE: public spaceObjects{
private:
    float potAcceleration;
    pair<float,float> acceleration = make_pair(0,0);
public:
    MODULE();
    bool IsController = false;
    bool IsEngine = false;
    bool IsTurner = false;
    pair<float,float> Acceleration() const;
    float PotAcceleration() const;
    void EditAcceleration(pair<float, float> dop);
    void NewCord(float ,float);
};

#endif //GALAXY_B13_MODULE_H

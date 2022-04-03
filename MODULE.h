#ifndef GALAXY_B13_MODULE_H
#define GALAXY_B13_MODULE_H
#include "spaceObjects.h"

class MODULE: public spaceObjects{
private:
    float potAcceleration;
    pair<float,float> acceleration = make_pair(0,0);
public:
    MODULE(float potentialAceleration=0, bool IsEngine = false, bool IsController = false, bool IsTurner = false);
    bool IsController;
    bool IsEngine;
    bool IsTurner;
    pair<float,float> Acceleration() const;
    float PotAcceleration() const;
    void EditAcceleration(pair<float, float> dop);
    void NewCord(float ,float);
};

#endif //GALAXY_B13_MODULE_H

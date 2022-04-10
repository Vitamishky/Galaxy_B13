#ifndef GALAXY_B13_MODULE_H
#define GALAXY_B13_MODULE_H
#include "spaceObjects.h"

class MODULE: public spaceObjects{
private:
    float forward_potAcceleration = 1000;
    pair<float,float> acceleration = make_pair(0,0);
    float side_potAcceleration = 100;
    float fuel = 1000;
    float air = 1000;
public:
    MODULE(float potentialAceleration=0, bool IsEngine = false, bool IsController = false, bool IsTurner = false);
    bool IsController;
    bool IsEngine;
    bool IsTurner;
    pair<float,float> Acceleration() const;
    float Forward_PotAcceleration() const;
    void EditAcceleration(pair<float, float> dop);
    float Side_PotAcceleration() const;
    bool Use_Fuel(float);
    bool Use_Air(float);

    void NewCord(float ,float);
    void NewAcceleration(pair<float, float>);
};

#endif //GALAXY_B13_MODULE_H
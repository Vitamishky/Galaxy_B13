#ifndef GALAXY_B13_MODULE_H
#define GALAXY_B13_MODULE_H
#include "spaceObjects.h"
#include "Planet.h"

class MODULE: public spaceObjects{
private:
    float forward_potAcceleration = 1000;
    pair<float,float> acceleration = make_pair(0,0);
    float side_potAcceleration = 100;
    float fuel = 10000000;
    float air = 10000000;
public:
    MODULE(float Masse = 100,
           int Width = 10,
           int Height = 10,
           bool IsController = false,
           bool IsTurner = false,
           float Side_PotAcceleration = 0,
           float Air = 0,
           bool IsEngine = false,
           float Forward_PotAcceleration = 0,
           float fuel = 0
    );
    bool IsController;
    bool IsEngine;
    bool IsTurner;
    pair<float, float> Acceleration() const;
    float Forward_PotAcceleration() const;
    void EditAcceleration(pair<float, float> dop);
    float Side_PotAcceleration() const;
    bool Use_Fuel(float);
    bool Use_Air(float);
    float getAir();
    float getFuel();
    void NewCord(float, float);
    void NewAcceleration(pair<float, float>);
    void planetAttraction(vector<Planet>& v);
};

#endif //GALAXY_B13_MODULE_H
#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdio>
#include "parametrizationScreen.h"
#include "MODULE.h"


using namespace std;

class spaceShip {
private:
    float length = 0, Mass = 0;
    pair<float, float> velocity;
    float angularVelocity;
    float fuel, MomentOfInertia = 0;
    pair<float, float> route;
    float x = 0, y = 0;
    vector<MODULE>& rocket;
public:
    spaceShip(const vector<MODULE> &rocket);
    void move(float);
    void control();
};
#endif 
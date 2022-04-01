#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Planet.h"
#include "parametrizationScreen.h"
#include "MODULE.h."

using namespace std;

class spaceShip {
protected:
    float length = 0, Mass = 0;
    pair<float, float> velocity;
    float angularVelocity;
    float fuel, MomentOfInertia;
    pair<float, float> route;
    float x, y;
    vector<MODULE> modules;
public:
    spaceShip();
    void drawSprite(sf::RenderWindow&);
    spaceShip(const vector<MODULE>& rocket);
    void move(vector<MODULE>& rocket);
    void planetAttraction(const Planet& planet);
};

#endif 
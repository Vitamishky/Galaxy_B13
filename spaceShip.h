#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdio>
#include "parametrizationScreen.h"
#include "MODULE.h"
#include "Planet.h"
#include "sounds.h"

using namespace std;

class spaceShip {
private:
    float cordCentreMass = 0;
    pair<float, float> velocity = make_pair(0, 0);
    float angularVelocity = 0;
    float MomentOfInertia = 0;
    float angle = 0;
    float x, y;
    float maxFuel = 0, maxAir = 0;
    vector<MODULE> rocket;

public:
    spaceShip(const vector<MODULE>& rocket, float, float);
    void move(float, vector<Planet>&);
    vector<sf::Sprite> getSprite() const;
    pair<float, float> getCoordinates() const;
    float getMaxFuel() const;
    float getMaxAir() const;
    float getMass() const;
    void control(sounds, sounds);
    float FUEL();
    float AIR();
    float SPEED() const;
    float ANGLE();
    void draw(sf::RenderWindow&);
    bool Use_Air(float);
    bool Use_Fuel(float);
};
#endif 
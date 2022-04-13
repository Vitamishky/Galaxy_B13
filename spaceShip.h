#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdio>
#include "parametrizationScreen.h"
#include "MODULE.h"

using namespace std;

class spaceShip {
private:
    float cordCentreMass = 0;
    float Mass = 0;
    pair<float, float> velocity = make_pair(0, 0);
    float angularVelocity = 0;
    float MomentOfInertia = 0;
    float angle = 0;
    float x = 0, y = 0;
    vector<MODULE> rocket;

public:
    spaceShip(const vector<MODULE>& rocket);
    void move(float);
    pair<float, float> getCoordinates();
    void control();
    float FUEL();
    float AIR();
    int SPEED() const;
    float ANGLE();
    void draw(sf::RenderWindow&);
};
#endif 
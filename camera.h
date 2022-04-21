#ifndef camera_hpp
#define camera_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"

using namespace std;

class camera {
private:
    sf::View view;
    sf::Vector2f position;
    bool locked;
    float scale;
public:
    camera(sf::RenderWindow&);
    ~camera();
    void resetView(sf::RenderWindow&);
    void lockedCamera(float x, float y);
    void unlockCamera();
    void moveCamera(float x, float y);
    void zoomCamera(sf::Event, sf::RenderWindow&);
    void backFromShip(sf::RenderWindow&, spaceShip);
    sf::View getViewCamera();
    sf::View getCoordinatesForView(float x, float y);
};

#endif 
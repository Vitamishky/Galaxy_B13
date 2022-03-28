#ifndef camera_hpp
#define camera_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace std;

class camera {
private:
    sf::View view;
    sf::Vector2f position;
    bool locked;
public:
    camera(sf::RenderWindow&);
    ~camera();
    void resetView();
    void lockedCamera(float x, float y);
    void unlockCamera();
    void moveCamera(float x, float y);
    void zoomCamera(sf::Event);
    sf::View getViewCamera();
    sf::View getCoordinatesForView(float x, float y);
};

#endif 
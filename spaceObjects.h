#ifndef spaceObjects_hpp
#define spaceObjects_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "parametrizationScreen.h"

using namespace std;

class spaceObjects {
protected:
    parametrizationScreen screen;
    float x, y;
    float xSpeed=0, ySpeed=0;
    int Width = 10, Height = 10;
    sf::Sprite Sprite;
    sf::Texture texture;
    pair<float,float> direction;
    float Masse = 1;
public:
    spaceObjects();
    void move(float, char);
    pair<float, float> getCoordinates() const;
    pair<float, float> getParametrization() const;
    void drawSprite(sf::RenderWindow&);
    pair<float, float> route;
    float getMasse() const;
};

#endif  

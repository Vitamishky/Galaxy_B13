#ifndef spaceObjects_hpp
#define spaceObjects_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdio>
#include "parametrizationScreen.h"

using namespace std;

class spaceObjects {
protected:
    parametrizationScreen screen;
    float x, y;
    float xSpeed=0, ySpeed=0;
    int Width = 0, Height = 0;
    sf::Sprite Sprite;
    sf::Texture texture;
    float angle = 0;
    float Masse;
public:
    spaceObjects();
    spaceObjects(float, float, float, int, int);
    pair<float, float> getCoordinates() const;
    pair<float, float> getParametrization() const;
    virtual void drawSprite(sf::RenderWindow&);
    void newAngle(float);
    float getMasse() const;
};
#endif
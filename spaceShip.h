#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "parametrizationScreen.h"

using namespace std;

class spaceShip {
private:
    parametrizationScreen screen;
    float spaceShip_x, spaceShip_y;
    float spaceShipSpeed_x, spaceShipSpeed_y;
    int spaceShipWidth, spaceShipHeight;
    sf::Sprite spaceShipSprite;
    sf::Texture textureShip;
    float spaceShipMasse = 1;
public:
    spaceShip();
    void moveShip(float, char);
    void drawSprite(sf::RenderWindow&);
    pair<float, float> getCoordinates() const;
    float getMasse() const;
};

#endif 

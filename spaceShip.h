#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "parametrizationScreen.h"
#include "spaceObjects.h"

using namespace std;

class spaceShip : public spaceObjects{
public:
    spaceShip();
    void drawSprite(sf::RenderWindow& gameWindow);
};

#endif 

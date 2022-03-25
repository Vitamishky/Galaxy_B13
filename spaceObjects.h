#ifndef spaceObjects_hpp
#define spaceObjects_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "parametrizationScreen.h"

using namespace std;

class spaceObjects {
private:
    parametrizationScreen screen;
    float spaceObjects_x, spaceObjects_y;
    float spaceObjectsSpeed_x, spaceObjectsSpeed_y;
    int spaceObjectsWidth, spaceObjectsHeight;
    sf::Sprite spaceObjectsSprite;
    sf::Texture textureObjects;
public:
    spaceObjects();
    ~spaceObjects();
    void moveObjects(float, char);
    void drawSprite(sf::RenderWindow&);
};

#endif 
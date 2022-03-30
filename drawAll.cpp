#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "drawAll.h"

drawAll::drawAll() {
    texBg.loadFromFile("image/bg.png");
    xBg = texBg.getSize().x * 1.0f;
    yBg = texBg.getSize().y * 1.0f;
    sprBg.setTexture(texBg);
}

void drawAll::drawBg(sf::RenderWindow& window) {
    sprBg.setScale(window.getSize().x / xBg, window.getSize().y / yBg);
    window.draw(sprBg);
}

void drawAll::drawIcon(sf::RenderWindow& window) {
    //Отрисовка иконки около названия окна
    sf::Image icon;
    icon.loadFromFile("image/spaceShip.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

drawAll::~drawAll() {}
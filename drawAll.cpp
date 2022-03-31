#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "drawAll.h"

drawAll::drawAll() {
    texBg.loadFromFile("image/bg.png");
    sprBg.setTexture(texBg);
}

void drawAll::drawBg(sf::RenderWindow& window, sf::View view) {
    float vSize_x = 2.0f * view.getSize().x;
    float vSize_y = 2.0f * view.getSize().y;
    float xBg = sprBg.getLocalBounds().width;
    float yBg = sprBg.getLocalBounds().height;
    sprBg.setScale(vSize_x / xBg, vSize_y / yBg);
    sprBg.setPosition(sf::Vector2f(view.getCenter().x - vSize_x / 2, view.getCenter().y - vSize_y / 2));
    window.draw(sprBg);
}

void drawAll::drawIcon(sf::RenderWindow& window) {
    //Отрисовка иконки около названия окна
    sf::Image icon;
    icon.loadFromFile("image/spaceShip.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

drawAll::~drawAll() {}
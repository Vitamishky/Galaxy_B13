#define _USE_MATH_DEFINES
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceObjects.h"
#include "cmath"

spaceObjects::spaceObjects(float x, float y, float angel): x(x), y(y), angle(angel) {
    xSpeed = 5.f / float(screen.getParametrizationScreen().first);
    ySpeed = 5.f / float(screen.getParametrizationScreen().second);
    Width = 128;
    Height = 128;
    texture.loadFromFile("image/spaceShip.png");
}

pair<float, float> spaceObjects::getCoordinates() const {
    pair<float, float> result = make_pair(x, y);
    return result;
}
pair<float, float> spaceObjects::getParametrization() const {
    pair<float, float> result = make_pair(Width, Height);
    return result;
}
float spaceObjects::getMasse() const {
    return Masse;
}

void spaceObjects::drawSprite(sf::RenderWindow& window) {
    Sprite.setTexture(texture);
    float l = sqrtf(float(Height * Height + Width * Width)) / 2;
    float b = acos(float(Height) / (2 * l)) + angle;
    Sprite.setScale(float(Width) / float(this->texture.getSize().x), float(Height) / float(this->texture.getSize().y));
    Sprite.setPosition(sf::Vector2f(x + l * sin(b), y + l * cos(b)));
    Sprite.setRotation(float(180-angle * 180 / M_PI));
    window.draw(Sprite);
}

void spaceObjects::newAngle(float injection){
    this->angle = injection;
}
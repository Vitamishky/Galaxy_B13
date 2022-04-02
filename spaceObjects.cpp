#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceObjects.h"

spaceObjects::spaceObjects() {
    x = y = 0.5f;
    xSpeed = 5.f / float(screen.getParametrizationScreen().first);
    ySpeed = 5.f / float(screen.getParametrizationScreen().second);
    Width = 128;
    Height = 128;
    texture.loadFromFile("image/spaceShip.png");
    Sprite.setTexture(texture);
}

void spaceObjects::move(float dt, char move) {
    switch (move)
    {
    case 'l': x -= dt * xSpeed; break;
    case 'r': x += dt * xSpeed; break;
    case 'u': y -= dt * ySpeed; break;
    case 'd': y += dt * ySpeed; break;
    default: break;
    }
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
    float angle =0;
    Sprite.setPosition(sf::Vector2f(x,y));
    Sprite.setRotation(angle);
    window.draw(Sprite);
}


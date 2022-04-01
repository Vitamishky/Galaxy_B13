#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceObjects.h"

spaceObjects::spaceObjects() {
    x = y = 0.5f;
    xSpeed = 5.f / float(screen.getParametrizationScreen().first);
    ySpeed = 5.f / float(screen.getParametrizationScreen().second);
    Width = 128;
    Height = 128;
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

void spaceObjects::drawSprite(sf::RenderWindow &gameWindow) {
    Sprite = sf::Sprite(texture);
    Sprite.setOrigin(float(Width) / 4, float(Height) / 4);
    Sprite.setPosition(x * float(screen.getParametrizationScreen().first),
                       y * float(screen.getParametrizationScreen().second));
    gameWindow.draw(Sprite);
}


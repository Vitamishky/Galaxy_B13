#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceObjects.h"

spaceObjects::spaceObjects() {
    x = y = 0.5f;
    xSpeed = 5.f / float(screen.getParametrizationScreen().first);
    ySpeed = 5.f / float(screen.getParametrizationScreen().second);
    Width = 128;
    Height = 128;

    if (!texture.loadFromFile("image/spaceObjects.png")) {
        exit(EXIT_FAILURE);
    }
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
sf::Texture spaceObjects::getTexture() const {
    return texture;
}

sf::Sprite spaceObjects::getSprite() const {
    return Sprite;
}

parametrizationScreen spaceObjects::getScreen() const {
    return screen;
}

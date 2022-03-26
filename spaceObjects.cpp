#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceObjects.h"
#include "parametrizationScreen.h"

spaceObjects::spaceObjects() {
    spaceObjects_x = spaceObjects_y = 0.5f;
    spaceObjectsSpeed_x = 5.f / screen.getParametrizationScreen().first;
    spaceObjectsSpeed_y = 5.f / screen.getParametrizationScreen().second;
    spaceObjectsWidth = 128;
    spaceObjectsHeight = 128;

    if (!textureObjects.loadFromFile("image/spaceObjects.png")) {
        exit(EXIT_FAILURE);
    }
}

void spaceObjects::drawSprite(sf::RenderWindow& gameWindow) {
    spaceObjectsSprite = sf::Sprite(textureObjects);
    spaceObjectsSprite.setOrigin(spaceObjectsWidth / 4, spaceObjectsHeight / 4);
    spaceObjectsSprite.setPosition(spaceObjects_x * screen.getParametrizationScreen().first,
                                   spaceObjects_y * screen.getParametrizationScreen().second);
    gameWindow.draw(spaceObjectsSprite);
}

void spaceObjects::moveObjects(float dt, char move) {
    switch (move)
    {
    case 'l': spaceObjects_x -= dt * spaceObjectsSpeed_x; break;
    case 'r': spaceObjects_x += dt * spaceObjectsSpeed_x; break;
    case 'u': spaceObjects_y -= dt * spaceObjectsSpeed_y; break;
    case 'd': spaceObjects_y += dt * spaceObjectsSpeed_y; break;
    }
}

spaceObjects::~spaceObjects() {}
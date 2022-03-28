#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "parametrizationScreen.h"

spaceShip::spaceShip() {
    spaceShip_x = spaceShip_y = 0.5f;
    spaceShipSpeed_x = 5.f / screen.getParametrizationScreen().first;
    spaceShipSpeed_y = 5.f / screen.getParametrizationScreen().second;
    spaceShipWidth = 128.f;
    spaceShipHeight = 128.f;
    float spaceShipMasse = 1;
    
    if (!textureShip.loadFromFile("spaceShip.png")) {
        exit(EXIT_FAILURE);
    }
}

void spaceShip::drawSprite(sf::RenderWindow& gameWindow) {
    spaceShipSprite = sf::Sprite(textureShip);
    spaceShipSprite.setOrigin(spaceShipWidth, spaceShipHeight);
    spaceShipSprite.setPosition(spaceShip_x * screen.getParametrizationScreen().first,
                                spaceShip_y * screen.getParametrizationScreen().second);
    gameWindow.draw(spaceShipSprite);
}

void spaceShip::moveShip(float dt, char move) {
    switch (move)
    {
        case 'l': spaceShip_x -= dt * spaceShipSpeed_x; break;
        case 'r': spaceShip_x += dt * spaceShipSpeed_x; break;
        case 'u': spaceShip_y -= dt * spaceShipSpeed_y; break;
        case 'd': spaceShip_y += dt * spaceShipSpeed_y; break;
    }
}
pair<float, float> spaceShip::getCoordinates() const {
    float x = spaceShip_x;
    float y = spaceShip_y;
    pair<float, float> result = make_pair(x, y);
    return result;
}

float spaceShip::getMasse() const {
    return spaceShipMasse;
}

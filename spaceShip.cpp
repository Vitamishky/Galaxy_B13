#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "parametrizationScreen.h"

spaceShip::spaceShip() {
    spaceShip_x = spaceShip_y = 0.5f;
    spaceShipSpeed_x = 0.f / screen.getParametrizationScreen().first;
    spaceShipSpeed_y = 0.f / screen.getParametrizationScreen().second;
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

pair<float, float> spaceShip::getCoordinates() const {
    float x = spaceShip_x;
    float y = spaceShip_y;
    pair<float, float> result = make_pair(x, y);
    return result;
}

float spaceShip::getMasse() const {
    return spaceShipMasse;
}

//Изменяем скорости корабля
pair<float, float> spaceShip::increaseSpeed_x(float additionalSpeed_x) {
    pair<float, float> v0_x_v_x = make_pair(spaceShipSpeed_x, spaceShipSpeed_x + additionalSpeed_x  / screen.getParametrizationScreen().first);
    spaceShipSpeed_x += additionalSpeed_x  / screen.getParametrizationScreen().first;
}
pair<float, float> spaceShip::increaseSpeed_y(float additionalSpeed_y) {
    pair<float, float> v0_y_v_y = make_pair(spaceShipSpeed_y, spaceShipSpeed_y + additionalSpeed_y  / screen.getParametrizationScreen().second);
    spaceShipSpeed_y += additionalSpeed_y  / screen.getParametrizationScreen().second;

}
//Проверяем есть ли скорость(ненулевая)
bool spaceShip::isSpeed_x() const {
    return spaceShipSpeed_x != 0;
}
bool spaceShip::isSpeed_y() const {
    return spaceShipSpeed_y != 0;
}

sf::Vector2f spaceShip::getSpaceShipSpeed() const {
    sf::Vector2f result {spaceShipSpeed_x, spaceShipSpeed_y};
    return result;
}

void spaceShip::moveShip(float dt) {
    if (isSpeed_x()) {
        spaceShip_x += spaceShipSpeed_x * dt;
    }
    if (isSpeed_y()) {
        spaceShip_y += spaceShipSpeed_y * dt;
    }
}
//Остановка корабля
void spaceShip::tormoz() {
    spaceShipSpeed_x = 0;
    spaceShipSpeed_y = 0;
}

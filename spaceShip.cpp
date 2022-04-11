#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"

spaceShip::spaceShip() {
    texture.loadFromFile("image/spaceShip.png");
    Sprite.setTexture(texture);
}

void spaceShip::drawSprite(sf::RenderWindow& gameWindow) {
    Sprite.setOrigin(Width, Height);
    Sprite.setPosition(x * screen.getParametrizationScreen().first,
        y * screen.getParametrizationScreen().second);
    gameWindow.draw(Sprite);
}
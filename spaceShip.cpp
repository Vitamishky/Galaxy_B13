#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"

spaceShip::spaceShip(){
    if (!texture.loadFromFile("spaceShip.png")) {
        exit(EXIT_FAILURE);
    }
}

void spaceShip::drawSprite(sf::RenderWindow& gameWindow) {
    Sprite = sf::Sprite(texture);
    Sprite.setOrigin(Width, Height);
    Sprite.setPosition(x * screen.getParametrizationScreen().first,
                                y * screen.getParametrizationScreen().second);
    gameWindow.draw(Sprite);
}



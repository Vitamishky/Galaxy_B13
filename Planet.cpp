#include "Planet.h"

void Planet::drawSprite(sf::RenderWindow &gameWindow) {
    Sprite = sf::Sprite(texture);
    Sprite.setOrigin(Width / 4, Height / 4);
    Sprite.setPosition(x * screen.getParametrizationScreen().first,
                                   y * screen.getParametrizationScreen().second);
    gameWindow.draw(Sprite);
}

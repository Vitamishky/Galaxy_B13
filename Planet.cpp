#include "Planet.h"
#include "spaceObjects.h"

Planet::Planet(float x, float y, float masse, float r, std::string file): spaceObjects(x, y, masse, 0, 0) {
    radius = r;
    texture.loadFromFile(file);
    sprite.setTexture(texture);
};

void Planet::drawSprite(sf::RenderWindow& window) {
    window.draw(sprite);
}

float Planet::getRadius() const {
    return this->radius;
}
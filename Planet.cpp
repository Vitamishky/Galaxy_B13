#include "Planet.h"
#include "spaceObjects.h"

Planet::Planet(float x, float y, float masse, float r): spaceObjects(x, y, masse, 0, 0) {
    radius = r;
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(x, y);
    //sf::Color color {masse, masse, masse, 255};
    //circle.setFillColor(sf::Color::Red);
    sf::Texture tex;
    tex.loadFromFile("image/about1.png");
    circle.setTexture(&tex);
};

void Planet::drawSprite(sf::RenderWindow& window) {
    window.draw(circle);
}

float Planet::getRadius() const {
    return this->radius;
}

sf::CircleShape Planet::getSprite() {
    return circle;
}
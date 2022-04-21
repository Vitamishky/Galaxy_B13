#include "Planet.h"
#include "spaceObjects.h"

Planet::Planet(float x, float y, float masse, float r): spaceObjects(x, y, masse, 0, 0) {
    radius = r;
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(x, y);
    circle.setTexture(&texCircle);
    //sf::Color color {masse, masse, masse, 255};
    //circle.setFillColor(sf::Color::Red);
};

void Planet::drawSprite(sf::RenderWindow& window) {
    window.draw(circle);
}

void Planet::setTex(sf::Texture tex) {
    texCircle = tex;
}

float Planet::getRadius() const {
    return this->radius;
}

std::pair<float, float> Planet::getCenter() {
    return std::make_pair(this->x, this->y);
}

sf::CircleShape Planet::getSprite() {
    return circle;
}
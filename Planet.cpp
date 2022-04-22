#include "Planet.h"
#include "spaceObjects.h"

Planet::Planet(float x, float y, float masse, float r, int i) : spaceObjects(x, y, masse, 0, 0) {
    radius = r;
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(x, y);
    for (int i = 0; i < 10; i++) {
        sf::Texture tex;
        string s = "image/planet" + to_string(i + 1) + ".png";
        tex.loadFromFile(s);
        vTex.push_back(tex);
    }
    circle.setTexture(&vTex[i % 10]);
};

void Planet::drawSprite(sf::RenderWindow& window) {
    window.draw(circle);
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
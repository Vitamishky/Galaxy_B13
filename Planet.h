#ifndef GALAXY_B13_PLANET_H
#define GALAXY_B13_PLANET_H
#include "spaceObjects.h"


class Planet : public spaceObjects{
protected:
    float radius;
private:
    sf::CircleShape circle;
    sf::Texture texCircle;
public:
    void drawSprite (sf::RenderWindow&);
    void setTex(sf::Texture);
    Planet(float, float, float, float);
    float getRadius() const;
    sf::CircleShape getSprite();
    std::pair<float, float> getCenter();
};

#endif //GALAXY_B13_PLANET_H

#ifndef GALAXY_B13_PLANET_H
#define GALAXY_B13_PLANET_H
#include "spaceObjects.h"


class Planet : public spaceObjects{
protected:
    float radius;
    sf::CircleShape circle;
public:
    void drawSprite (sf::RenderWindow&) override;
    Planet(float, float, float, float);
    float getRadius() const;
    sf::CircleShape getSprite();
};

#endif //GALAXY_B13_PLANET_H
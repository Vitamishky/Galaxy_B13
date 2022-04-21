#ifndef GALAXY_B13_PLANET_H
#define GALAXY_B13_PLANET_H
#include "spaceObjects.h"


class Planet : public spaceObjects{
protected:
    float radius;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    void drawSprite (sf::RenderWindow&) override;
    Planet(float, float, float, float, std::string);
    float getRadius() const;
};

#endif //GALAXY_B13_PLANET_H

#ifndef GALAXY_B13_PLANET_H
#define GALAXY_B13_PLANET_H
#include "spaceObjects.h"

class Planet : public spaceObjects{
public:
    void drawSprite(sf::RenderWindow& gameWindow);
};

#endif //GALAXY_B13_PLANET_H
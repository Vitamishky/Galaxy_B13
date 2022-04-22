#ifndef GALAXY_B13_PLANET_H
#define GALAXY_B13_PLANET_H
#include "spaceObjects.h"

class Planet : public spaceObjects{
protected:
    float radius;
private:
    sf::CircleShape circle;
    sf::Texture texCircle;
    vector<sf::Texture> vTex;
public:
    void drawSprite (sf::RenderWindow&);
    void setTex(int i);
    Planet(float, float, float, float, int);
    float getRadius() const;
    sf::CircleShape getSprite();
    std::pair<float, float> getCenter();
};

#endif //GALAXY_B13_PLANET_H
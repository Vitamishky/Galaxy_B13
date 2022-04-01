#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "parametrizationScreen.h"
#include "spaceObjects.h"

using namespace std;

class spaceShip : public spaceObjects {
public:
    spaceShip();
    void drawSprite(sf::RenderWindow&);
};

#endif 
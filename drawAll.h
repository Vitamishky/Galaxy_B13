#pragma
#ifndef drawAll_hpp
#define drawAll_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MODULE.h"
#include "spaceShip.h"
using namespace std;

class drawAll {
private:
    sf::Font font;
    sf::Text text, textFuel, textAir, textSpeed, textSpace, textFuelConsumption, textAirConsumption;
    vector<sf::Text> vLText;
    sf::Image icon;
    sf::Texture texBg;
    sf::Sprite sprBg;
    sf::Texture texLeftInter, texRightInter, texFuel, texCompasRadar, texArrow;
    sf::Sprite sprLeftInter, sprRightInter, sprFuel, sprArrow;
    sf::CircleShape shapeCompas;
    MODULE module;
    sf::Texture buttonPlayFull, buttonOptionsFull, buttonExitFull, aboutTextureFull, menuBackground;
    sf::Sprite buttonPlay, buttonOptions, buttonExit, aboutTexture;
    sf::Sprite play, options, exit, about, menuBg;
public:
    drawAll();
    void drawBg(sf::RenderWindow&, sf::View);
    void drawIcon(sf::RenderWindow&);
    void drawLeftInter(sf::RenderWindow&, sf::View, spaceShip);
    void drawRightInter(sf::RenderWindow&, sf::View);
    void drawFuel(sf::RenderWindow&, sf::View, spaceShip);
    void drawCompas(sf::RenderWindow&, sf::View);
    void drawArrow(sf::RenderWindow&, sf::View);
    float xBg, yBg, xPl, yPl, xOp, yOp, xEx, yEx, xAb, yAb;
    sf::Sprite getSpriteMenuBackground(sf::RenderWindow&);
    sf::Sprite getSpritePlay(sf::RenderWindow&);
    sf::Sprite getSpriteOptions(sf::RenderWindow&);
    sf::Sprite getSpriteExit(sf::RenderWindow&);
    sf::Sprite getSpriteAbout(sf::RenderWindow&);
    void moveMenu(sf::RenderWindow&, vector<sf::Sprite>, vector<sf::Sprite>);
    ~drawAll();
};

#endif
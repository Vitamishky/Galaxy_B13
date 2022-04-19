﻿#pragma 
#ifndef drawAll_hpp
#define drawAll_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MODULE.h"
#include "spaceShip.h"
#include "MODULE.h"

using namespace std;

class drawAll {
private:
	//Òåêñò
	sf::Font font;
	sf::Text text, textSpeed, textSpace, textFuelConsumption, textAirConsumption, textMass, textAbout;
	vector<sf::Text> vLText;
	//Èêîíêà
	sf::Image icon;
	//Îòðèñîâêà çàäíåãî ôîíà
	sf::Texture texBg, texFuelPanel, texAirPanel;
	sf::Sprite sprBg, sprFuelPanel, sprAirPanel;
	//Îòðèñîâêà èíòåðôåéñà
	sf::Texture texLeftInter, texRightInter, texFuel, texCompasRadar, texArrow;
	sf::Sprite sprLeftInter, sprRightInter, sprFuel, sprArrow;
	sf::CircleShape shapeCompas;
	//Ñòàðòîâîãî ìåíþ
	sf::Texture buttonStartFull, buttonOptionsFull, buttonExitFull, aboutTextureFull, buttonStartFull_1, buttonOptionsFull_1, buttonExitFull_1, aboutTextureFull_1, menuBackground;
	sf::Sprite buttonStart, buttonOptions, buttonExit, aboutTexture, buttonStartWithMouse, buttonOptionsWithMouse, buttonExitWithMouse, aboutTextureWithMouse;
	sf::Sprite start, options, exit, about, menuBg;
	//меню в настройках
	sf::Texture buttonMusicFull, buttonBackFull, buttonBackFull_1, buttonBackgroundFull, buttonLayoutFull;
	sf::Sprite buttonMusic, buttonBack, buttonBackWithMouse, buttonBackground, buttonLayout;
	sf::Sprite music, back, background, layout, optionsBg;
	sf::Texture menuBackgroundCat, menuBackgroundSpace, menuBackgroundSpace2, menuBackgroundMain;
	sf::Sprite menuBgCat, menuBgSpace, menuBgSpace2, menuBgMain;
	sf::Text textMusic1, textMusic2, textMusic3, textLayout;

	//BuildRocket
	sf::Texture buttonPlayFull, buttonPlayFull_1, buttonBuiltFull, buttonBuiltFull_1;
	sf::Sprite buttonPlay, buttonPlayWithMouse, buttonBuilt, buttonBuiltWithMouse;
	sf::Sprite play, playWithMouse, built, builtWithMouse;

public:
	drawAll();
	void drawBg(sf::RenderWindow&, sf::View);
	void drawIcon(sf::RenderWindow&);
	void drawLeftInter(sf::RenderWindow&, sf::View, spaceShip);
	void drawRightInter(sf::RenderWindow&, sf::View);
	void drawFuel(sf::RenderWindow&, sf::View, spaceShip);
	void drawCompas(sf::RenderWindow&, sf::View, spaceShip);
	void drawArrow(sf::RenderWindow&, sf::View);
	void drawTextAboutAll(sf::RenderWindow&, sf::View, spaceShip);
	sf::Text drawTextAbout(sf::RenderWindow&);
	sf::Text drawTextMusic1(sf::RenderWindow&);
	sf::Text drawTextMusic2(sf::RenderWindow&);
	sf::Text drawTextMusic3(sf::RenderWindow&);
	sf::Text drawTextLayout(sf::RenderWindow&);
	float xBg, yBg, xSt, ySt, xOp, yOp, xEx, yEx, xAb, yAb, xBag, yBag, xMu, yMu, xBack, yBack, xLa, yLa, xBgCat, yBgCat, xBgSpace, yBgSpace, xBgSpace2, yBgSpace2;


	sf::Sprite getSpriteMenuBackground(sf::RenderWindow&, sf::Texture);
	sf::Sprite getSpriteStart(sf::RenderWindow&);
	sf::Sprite getSpriteOptions(sf::RenderWindow&);
	sf::Sprite getSpriteExit(sf::RenderWindow&);
	sf::Sprite getSpriteAbout(sf::RenderWindow&);

	sf::Sprite getSpriteStartWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteOptionsWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteExitWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteAboutWithMouse(sf::RenderWindow&);

	//Спрайты для настроек
	sf::Sprite getSpriteMusic(sf::RenderWindow&);
	sf::Sprite getSpriteBackground(sf::RenderWindow&);
	sf::Sprite getSpriteLayout(sf::RenderWindow&);
	sf::Sprite getSpriteBack(sf::RenderWindow&);
	sf::Sprite getSpriteBackWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteBackgroundCat(sf::RenderWindow&);
	sf::Sprite getSpriteBackgroundSpace(sf::RenderWindow&);
	sf::Sprite getSpriteBackgroundSpace2(sf::RenderWindow&);
	sf::Sprite getSpriteBackgroundMain(sf::RenderWindow&);

	sf::Sprite getSpritePlay(sf::RenderWindow&);
	sf::Sprite getSpritePlayWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteBuilt(sf::RenderWindow&);
	sf::Sprite getSpriteBuiltWithMouse(sf::RenderWindow&);
};

#endif
#pragma 
#ifndef drawAll_hpp
#define drawAll_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MODULE.h"

using namespace std;

class drawAll {
private:
	//Текст
	sf::Font font;
	sf::Text text, textFuel, textAir, textSpeed, textSpace, textFuelConsumption, textAirConsumption;
	vector<sf::Text> vLText;
	//Иконка
	sf::Image icon;
	//Отрисовка заднего фона
	sf::Texture texBg;	
	sf::Sprite sprBg;
	//Отрисовка интерфейса
	sf::Texture texLeftInter, texRightInter, texFuel, texCompasRadar, texArrow;
	sf::Sprite sprLeftInter, sprRightInter, sprFuel, sprArrow;
	sf::CircleShape shapeCompas;
	MODULE module;
	//Стартового меню
	sf::Texture buttonStartFull, buttonOptionsFull, buttonExitFull, aboutTextureFull, buttonStartFull_1, buttonOptionsFull_1, buttonExitFull_1, aboutTextureFull_1, menuBackground;
	sf::Sprite buttonStart, buttonOptions, buttonExit, aboutTexture, buttonStartWithMouse, buttonOptionsWithMouse, buttonExitWithMouse, aboutTextureWithMouse;
	sf::Sprite start, options, exit, about, menuBg;
	//меню в настройках
	sf::Sprite buttonSettingsFull, buttonMusicFull, buttonBackFull, buttonBackFull_1, buttonBackgroundFull, buttonLayoutFull;
	sf::Sprite buttonSettings, buttonMusic, buttonBack, buttonBackWithMouse, buttonBackground, buttonLayout;
	sf::Sprite settings, music, back, background, layout, optionsBg;

public:
	drawAll();
	void drawBg(sf::RenderWindow&, sf::View);
	void drawIcon(sf::RenderWindow&);
	void drawLeftInter(sf::RenderWindow&, sf::View);
	void drawRightInter(sf::RenderWindow&, sf::View);
	void drawFuel(sf::RenderWindow&, sf::View);
	void drawCompas(sf::RenderWindow&, sf::View);
	void drawArrow(sf::RenderWindow&, sf::View);
	float xBg, yBg, xSt, ySt, xOp, yOp, xEx, yEx, xAb, yAb;
	
	//Спрайты для основного меню
	sf::Sprite getSpriteMenuBackground(sf::RenderWindow&);
	sf::Sprite getSpriteStart(sf::RenderWindow&);
	sf::Sprite getSpriteOptions(sf::RenderWindow&);
	sf::Sprite getSpriteExit(sf::RenderWindow&);
	sf::Sprite getSpriteAbout(sf::RenderWindow&);
	
	sf::Sprite getSpriteStartWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteOptionsWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteExitWithMouse(sf::RenderWindow&);
	sf::Sprite getSpriteAboutWithMouse(sf::RenderWindow&);
	
	//Спрайты для настроек
	sf::Sprite getSpriteSettings(sf::RenderWindow&);
	sf::Sprite getSpriteMusic(sf::RenderWindow&);
	sf::Sprite getSpriteBackground(sf::RenderWindow&);
	sf::Sprite getSpriteLayout(sf::RenderWindow&);
	sf::Sprite getSpriteBack(sf::RenderWindow&);
	sf::Sprite getSpriteBackWithMouse(sf::RenderWindow&);
	
	void moveMenu(sf::RenderWindow&, vector<sf::Sprite>, vector<sf::Sprite>);
	~drawAll();
};

#endif
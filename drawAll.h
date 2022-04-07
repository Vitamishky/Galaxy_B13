#pragma 
#ifndef drawAll_hpp
#define drawAll_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class drawAll {
private:
	sf::Image icon;
	//Отрисовка заднего фона
	sf::Texture texBg;	
	sf::Sprite sprBg;
	//Отрисовка интерфейса
	sf::Texture texLeftInter, texRightInter, texFuel, texCompas;
	sf::Sprite sprLeftInter, sprRightInter, sprFuel;
	sf::CircleShape shapeCompas;
	//Стартового меню
	sf::Texture buttonPlayFull, buttonOptionsFull, buttonExitFull, aboutTextureFull, menuBackground;
	sf::Sprite buttonPlay, buttonOptions, buttonExit, aboutTexture;	
	sf::Sprite play, options, exit, about, menuBg;
public:
	drawAll();
	void drawBg(sf::RenderWindow&, sf::View);
	void drawIcon(sf::RenderWindow&);
	void drawLeftInter(sf::RenderWindow&, sf::View);
	void drawRightInter(sf::RenderWindow&, sf::View);
	void drawFuel(sf::RenderWindow&, sf::View);
	void drawCompas(sf::RenderWindow&, sf::View);
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
#pragma
#ifndef drawAll_hpp
#define drawAll_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class drawAll {
private:
	sf::Texture texBg;	
	sf::Sprite sprBg;
	sf::Texture buttonPlayFull, buttonOptionsFull, buttonExitFull, aboutTextureFull, menuBackground;
	sf::Sprite buttonPlay, buttonOptions, buttonExit, aboutTexture;	
	sf::Sprite play, options, exit, about, menuBg;
public:
	drawAll();
	void drawBg(sf::RenderWindow&, sf::View);
	void drawIcon(sf::RenderWindow&);
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
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"

class aboutMenu {
private:
	int menuNum;
	sf::Text text;
	sf::Sprite back, backWithMouse, sprite;
	sf::Sprite finalMeme;
	drawAll draw;
public:
	aboutMenu();
	string drawAboutMenu(sf::RenderWindow&, sf::Texture);
};
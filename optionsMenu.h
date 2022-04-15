#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"
#include "startMenu.h"

class optionsMenu {
private:
	bool isMenu;
	int menuNum;
	drawAll draw;
	sf::Sprite music, back, backWithMouse, background, layout, changeBg, about;
public:
	optionsMenu();
	string drawOptionsMenu(sf::RenderWindow&);
	~optionsMenu();
};
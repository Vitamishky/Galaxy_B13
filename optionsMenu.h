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
	sf::Sprite settings, music, back, background, layout, optionsBg, about;
public:
	optionsMenu();
	void drawOptionsMenu(sf::RenderWindow&);
	~optionsMenu();
};
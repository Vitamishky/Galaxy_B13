#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"

class optionsMenu {
private:
	bool isOptionsMenu;
	int menuNum;
	drawAll draw;
	sf::Sprite settings, music, back, background, layout, optionsBg, about;
	vector<sf::Sprite> vSStartMenu, vSOptionsMenu;
public:
	optionsMenu();
	void drawOptionsMenu(sf::RenderWindow&);
	~optionsMenu();
};
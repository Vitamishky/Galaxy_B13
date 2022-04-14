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
	sf::Sprite start, options, exit, about;
	vector<sf::Sprite> vSStartMenu, vSOptionsMenu;
public:
	optionsMenu();
	void drawOptionsMenu(sf::RenderWindow&);
	~optionsMenu();
};
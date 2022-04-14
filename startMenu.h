#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"
#include "optionsMenu.h"

class startMenu {
private:
	bool isMenu;
	int menuNum;
	drawAll draw;
	optionsMenu optionsMainMenu;
	sf::Sprite start, options, exit, about, startWithMouse, optionsWithMouse, exitWithMouse, aboutWithMouse;
	vector<sf::Sprite> vSStartMenu, vSOptionsMenu;
public:
	startMenu();
	void drawStartMenu(sf::RenderWindow&);
	~startMenu();
};
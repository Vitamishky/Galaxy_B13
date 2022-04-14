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
	sf::Sprite start, options, exit, about;
public:
	startMenu();
	string drawStartMenu(sf::RenderWindow&);
	~startMenu();
};
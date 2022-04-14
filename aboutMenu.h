#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"
#include "startMenu.h"



class aboutMenu {
private:
	bool isAboutMenu;
	int menuNum;
	drawAll draw;
	startMenu startMenu;
	sf::Sprite about, music, back, settings, background, backWithMouse;
	vector<sf::Sprite> vSStartMenu, vSOptionsMenu;
public:
	aboutMenu();
	void drawAboutMenu(sf::RenderWindow&);
	~aboutMenu();
};


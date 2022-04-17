#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"
#include "startMenu.h"

class optionsMenu {
private:
	bool isMenu;
	int menuNum, musicNum, backgroundNum, soundValue;
	drawAll draw;
	sf::Sprite music, back, backWithMouse, background, layout, changeBg, about;
	sf::Sprite changeBg1, changeBg2, changeBg3, changeBg4;
	sf::Text music1, music2, music3, textLayout;
public:
	optionsMenu();
	std::pair < std::string, std::vector < int>> drawOptionsMenu(sf::RenderWindow&);
	~optionsMenu();
};
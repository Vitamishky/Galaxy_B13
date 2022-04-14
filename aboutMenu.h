#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"

class aboutMenu {
private:
	sf::Text text;
	drawAll draw;
public:
	aboutMenu();
	string drawAboutMenu(sf::RenderWindow&);
};
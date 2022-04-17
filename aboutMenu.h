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

    [[noreturn]] string drawAboutMenu(sf::RenderWindow&);
};
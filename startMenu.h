#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "parametrizationScreen.h"

class menu {
private:
	bool isMenu;
	int menuNum;
public:
	menu();
	void drawMenu(sf::RenderWindow&);
	~menu();
};
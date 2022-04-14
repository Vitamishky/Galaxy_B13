#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"
<<<<<<< HEAD
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

=======

class aboutMenu {
private:
	sf::Text text;
	drawAll draw;
public:
	aboutMenu();
	string drawAboutMenu(sf::RenderWindow&);
};
>>>>>>> abd34c38fac046cb155eeca84ee22256f46301c1

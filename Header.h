#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "parametrizationScreen.h"



class menu {
private:
	play.setTexture(playTexture);
	//settings.setTextureRect();
	exit.setPosition();
public:
	menu();
	~menu();
	void menu(sf::RenderWindow&));
};


void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	play.loadFromFile("image/buttons.png");
	options.loadFromFile("image/buttons.png");
	mexit.loadFromFile("image/buttons.png");
	aboutTexture.loadFromFile("image/buttons.png");
	menuBackground.loadFromFile("image/background.jpg");

	if (!play.loadFromFile("image/buttons.png") ||
	    !options.loadFromFile("image/buttons.png") ||
		!exit.loadFromFile("image/buttons.png") ||
		!aboutTexture.loadFromFile("image/buttons.png") ||
		!menuBackground.loadFromFile("image/background.jpg")) {
		exit(EXIT_FAILURE);
	}


	Sprite menu1(play), menu2(options), menu3(exit), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1; //Нужно ли меню
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menuBg.setPosition(345, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////
}

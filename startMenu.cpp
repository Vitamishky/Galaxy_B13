#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "startMenu.h"


menu::menu() {
	isMenu = 1;
	menuNum = 0;
}

void menu::drawMenu(sf::RenderWindow& window) {
	sf::Texture buttonPlay, buttonOptions, buttonExit, aboutTexture, menuBackground;
	buttonPlay.loadFromFile("image/buttons.png");
	buttonOptions.loadFromFile("image/buttons.png");
	buttonExit.loadFromFile("image/buttons.png");
	aboutTexture.loadFromFile("image/buttons.png");
	menuBackground.loadFromFile("image/background.jpg");
	float xBg = menuBackground.getSize().x;
	float yBg = menuBackground.getSize().y;
	float xPl = buttonPlay.getSize().x;
	float yPl = buttonPlay.getSize().y;
	float xOp = buttonOptions.getSize().x;
	float xEx = buttonExit.getSize().x;
	float xAb = aboutTexture.getSize().x;

	if (!buttonPlay.loadFromFile("image/buttons.png") ||
		!buttonOptions.loadFromFile("image/buttons.png") ||
		!buttonExit.loadFromFile("image/buttons.png") ||
		!aboutTexture.loadFromFile("image/buttons.png") ||
		!menuBackground.loadFromFile("image/background.jpg")) {
		exit(EXIT_FAILURE);
	}


	sf::Sprite menu1(buttonPlay), menu2(buttonOptions), menu3(buttonExit), about(aboutTexture), menuBg(menuBackground);
	menu1.setPosition((window.getSize().x - xPl) / 2 , window.getSize().y * 0.1f);
	menu2.setPosition((window.getSize().x - xOp) / 2 , window.getSize().y * 0.2f);
	menu3.setPosition((window.getSize().x - xEx) / 2 , window.getSize().y * 0.3f);
	about.setPosition( window.getSize().x * 0.9f - xAb , window.getSize().y * 0.9f);
	menuBg.setScale(window.getSize().x / xBg , window.getSize().y / yBg);

	//////////////////////////////МЕНЮ///////////////////

	while (isMenu) {
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));

		if (sf::IntRect((window.getSize().x - xPl) / 2, window.getSize().y * 0.1f, (window.getSize().x + xPl) / 2, window.getSize().y * 0.1f).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(100, 90, 300, 50).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect(100, 150, 300, 50).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

	    window.draw(menuBg);
		
		window.draw(menu1);
		
		window.draw(menu2);
		
		window.draw(menu3);
		
		//window.draw(about);

		window.display();
	}
	////////////////////////////////////////////////////
}
menu::~menu() {}
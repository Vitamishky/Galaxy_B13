#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "startMenu.h"


menu::menu() {
	isMenu = 1;
	menuNum = 0;
}


void menu::drawMenu(sf::RenderWindow& window) {
	sf::Texture buttonPlayFull, buttonOptionsFull, buttonExitFull, aboutTextureFull, menuBackground;
	buttonPlayFull.loadFromFile("image/buttons.png");
	buttonOptionsFull.loadFromFile("image/buttons.png");
	buttonExitFull.loadFromFile("image/buttons.png");
	aboutTextureFull.loadFromFile("image/buttons.png");
	menuBackground.loadFromFile("image/background.jpg");

	if (!buttonPlayFull.loadFromFile("image/buttons.png") ||
		!buttonOptionsFull.loadFromFile("image/buttons.png") ||
		!buttonExitFull.loadFromFile("image/buttons.png") ||
		!aboutTextureFull.loadFromFile("image/buttons.png") ||
		!menuBackground.loadFromFile("image/background.jpg")) {
		exit(EXIT_FAILURE);
	}

	sf::Sprite buttonPlay, buttonOptions, buttonExit, aboutTexture;
	buttonPlay.setTexture(buttonPlayFull);
	buttonOptions.setTexture(buttonOptionsFull);
	buttonExit.setTexture(buttonExitFull);
	aboutTexture.setTexture(aboutTextureFull);

	//вырезка необходимых значков из изображения
	buttonPlay.setTextureRect(sf::IntRect(34, 138, 50, 20));
	buttonOptions.setTextureRect(sf::IntRect(253, 138, 50, 20));
	buttonExit.setTextureRect(sf::IntRect(542, 138, 50, 20));
	aboutTexture.setTextureRect(sf::IntRect(0, 138, 50, 20));

	//Получение высоты и ширины sprite'ов 
	float xBg = menuBackground.getSize().x;
	float yBg = menuBackground.getSize().y;
	float xPl = buttonPlay.getTextureRect().width;
	float yPl = buttonPlay.getTextureRect().height;
	float xOp = buttonOptions.getTextureRect().width;
	float yOp = buttonOptions.getTextureRect().height;
	float xEx = buttonExit.getTextureRect().width;
	float yEx = buttonExit.getTextureRect().height;
	float xAb = aboutTexture.getTextureRect().width;
	float yAb = aboutTexture.getTextureRect().height;

	sf::Sprite menu1(buttonPlay), menu2(buttonOptions), menu3(buttonExit), about(aboutTexture), menuBg(menuBackground);
	menu1.setPosition((window.getSize().x - xPl) / 2 , window.getSize().y * 0.45f);
	menu2.setPosition((window.getSize().x - xOp) / 2 , window.getSize().y * 0.5f);
	menu3.setPosition((window.getSize().x - xEx) / 2 , window.getSize().y * 0.55f);
	about.setPosition( window.getSize().x * 0.8f, window.getSize().y * 0.8f);
	menuBg.setScale(window.getSize().x / xBg , window.getSize().y / yBg);

	//////////////////////////////МЕНЮ///////////////////

	sf::Text nameOfGame;
	nameOfGame.setString("GALAXY B13");
	nameOfGame.setCharacterSize(window.getSize().x / 10);
	nameOfGame.setStyle(sf::Text::Bold);
	nameOfGame.setPosition(0, 0);
	//nameOfGame.setColor()






	while (isMenu) {
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));

		if (sf::IntRect((window.getSize().x - xPl) / 2, window.getSize().y * 0.45f, xPl, yPl).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect((window.getSize().x - xOp) / 2, window.getSize().y * 0.5f, xOp, yOp).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect((window.getSize().x - xEx) / 2, window.getSize().y * 0.55f,  xEx, yEx).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }
		//if (sf::IntRect(window.getSize().x * 0.8f, window.getSize().y * 0.8f, xAb, yAb).contains(sf::Mouse::getPosition(window))) { about.setColor(sf::Color::Blue); }

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
		
		window.draw(about);

		window.display();
	}
	////////////////////////////////////////////////////
}
menu::~menu() {}
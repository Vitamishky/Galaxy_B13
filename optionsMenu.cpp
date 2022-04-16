#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "optionsMenu.h"

optionsMenu::optionsMenu() {
	isMenu = true;
	menuNum = 0;
	drawAll draw;
}

string optionsMenu::drawOptionsMenu(sf::RenderWindow& window) {
	background = draw.getSpriteMenuBackground(window);
	backWithMouse = draw.getSpriteBackWithMouse(window);
	music = draw.getSpriteMusic(window);
	back = draw.getSpriteBack(window);
	layout = draw.getSpriteLayout(window);
	changeBg = draw.getSpriteBackground(window);

	music1 = draw.drawTextMusic1(window);
	music2 = draw.drawTextMusic2(window);
	music3 = draw.drawTextMusic3(window);
	
	while (isMenu) {
		music.setColor(sf::Color::White);
		background.setColor(sf::Color::White);
		back.setColor(sf::Color::White);
		layout.setColor(sf::Color::White);
		menuNum = 0;

		if (sf::IntRect(window.getSize().x * 0.05f - (draw.xAb / 10.0f), window.getSize().y * 0.88f - (draw.xAb / 10.0f), window.getSize().x / 13.0f, window.getSize().x / 13.0f).contains(sf::Mouse::getPosition(window))) {
			menuNum = 1;
		}

		//if (sf::IntRect(window.getSize().x * 0.8f, window.getSize().y * 0.8f, xAb, yAb).contains(sf::Mouse::getPosition(window))) { about.setColor(sf::Color::Blue); }
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//Если нажали кнопку
			if (menuNum == 1) {
				break;
			}
			////Если нажали кнопку
			//if (menuNum == 2) {
			//	//draw.moveMenu(window, vSStartMenu, vSOptionsMenu);
			//	break;
			//}
			////Если нажали кнопку
			//if (menuNum == 3) {
			//	//window.close();
			//	break;
			//}

		}

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				isMenu = false;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
				isMenu = false;
			}
		}

		//window.draw(draw.getSpriteMenuBackground(window));

		window.draw(background);
		
		window.draw(back);

		window.draw(music);
		
		window.draw(music1);

		window.draw(music2);

		window.draw(music3);

		window.draw(layout);

		window.draw(changeBg);

		if (menuNum == 1)
			window.draw(backWithMouse);

		window.display();
	}
	return "main";
}
optionsMenu::~optionsMenu() {}

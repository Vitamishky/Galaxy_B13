#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "optionsMenu.h"

optionsMenu::optionsMenu() {
	isMenu = true;
	menuNum = 0;
	drawAll draw;
}

void optionsMenu::drawOptionsMenu(sf::RenderWindow& window) {
	settings = draw.getSpriteSettings(window);
	background = draw.getSpriteMenuBackground(window);
	music = draw.getSpriteMusic(window);
	back = draw.getSpriteBack(window);
	about = draw.getSpriteAbout(window);
	
	while (isMenu) {
		settings.setColor(sf::Color::White);
		music.setColor(sf::Color::White);
		background.setColor(sf::Color::White);
		back.setColor(sf::Color::White);
		layout.setColor(sf::Color::White);
		menuNum = 0;
		/*
		if (sf::IntRect((window.getSize().x * 0.2f - draw.xLa), window.getSize().y * 0.45f, draw.xLa, draw.yLa).contains(sf::Mouse::getPosition(window))) {
			menuNum = 1;
		}
		if (sf::IntRect((window.getSize().x * 0.4f - draw.xSet), window.getSize().y * 0.3f, draw.xSet, draw.ySet).contains(sf::Mouse::getPosition(window))) {
			menuNum = 2;
		}
		if (sf::IntRect((window.getSize().x * 0.6f - draw.xMu), window.getSize().y * 0.3f, draw.xMu, draw.yMu).contains(sf::Mouse::getPosition(window))) {
			menuNum = 3;
		}
		if (sf::IntRect((window.getSize().x * 0.8f - draw.xBag), window.getSize().y * 0.3f, draw.xBag, draw.yBag).contains(sf::Mouse::getPosition(window))) {
			menuNum = 4;
		}
		//if (sf::IntRect(window.getSize().x * 0.8f, window.getSize().y * 0.8f, xAb, yAb).contains(sf::Mouse::getPosition(window))) { about.setColor(sf::Color::Blue); }
		*/
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//Если нажали кнопку
			if (menuNum == 1) {
				break;
			}
			//Если нажали кнопку
			if (menuNum == 2) {
				break;
			}
			//Если нажали кнопку
			if (menuNum == 3) {
				//window.close();
				break;
			}

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

		window.draw(settings);

		window.draw(music);

		window.draw(background);

		window.draw(layout);

		window.display();
	}
}
optionsMenu::~optionsMenu() {}

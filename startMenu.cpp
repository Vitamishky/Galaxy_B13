#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "optionsMenu.h"

startMenu::startMenu() {
	isMenu = 1;
	menuNum = 0;
	drawAll draw;
}

string startMenu::drawStartMenu(sf::RenderWindow& window) {
	start = draw.getSpritePlay(window);
	options = draw.getSpriteOptions(window);
	exit = draw.getSpriteExit(window);
	about = draw.getSpriteAbout(window);

	while (isMenu) {
		start.setColor(sf::Color::White);
		options.setColor(sf::Color::White);
		exit.setColor(sf::Color::White);
		menuNum = 0;

		if (sf::IntRect((window.getSize().x - draw.xPl) / 2, window.getSize().y * 0.45f, draw.xPl, draw.yPl).contains(sf::Mouse::getPosition(window))) {
			start.setColor(sf::Color::Blue);
			menuNum = 1;
		}
		if (sf::IntRect((window.getSize().x - draw.xOp) / 2, window.getSize().y * 0.5f, draw.xOp, draw.yOp).contains(sf::Mouse::getPosition(window))) {
			options.setColor(sf::Color::Blue);
			menuNum = 2; 
		}
		if (sf::IntRect((window.getSize().x - draw.xEx) / 2, window.getSize().y * 0.55f, draw.xEx, draw.yEx).contains(sf::Mouse::getPosition(window))) {
			exit.setColor(sf::Color::Blue);
			menuNum = 3; 
		}
		//if (sf::IntRect(window.getSize().x * 0.8f, window.getSize().y * 0.8f, xAb, yAb).contains(sf::Mouse::getPosition(window))) { about.setColor(sf::Color::Blue); }

		

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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (menuNum == 1) {
				return "go";
				break;
			}
			if (menuNum == 2) { 
				for (int i = 0; i < 100; i++) {
					options.setColor(sf::Color::White);

					start.move(10.f, 10.f);
					options.move(-10.f, -10.f);
					exit.move(-10.f, 10.f);
					window.draw(draw.getSpriteMenuBackground(window));

					window.draw(start);

					window.draw(options);

					window.draw(exit);

					window.draw(about);

					window.display();
				}
				return "options";
				break;
			}
			if (menuNum == 3) { 
				window.close(); 
				break;
			}

		}
		else {
			window.draw(draw.getSpriteMenuBackground(window));

			window.draw(start);

			window.draw(options);

			window.draw(exit);

			window.draw(about);

			window.display();
		}
	}
}
startMenu::~startMenu() {}
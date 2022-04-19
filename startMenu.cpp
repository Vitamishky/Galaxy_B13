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
	start = draw.getSpriteStart(window);
	options = draw.getSpriteOptions(window);
	exit = draw.getSpriteExit(window);
	about = draw.getSpriteAbout(window);

	//Новые иконки при наведении на кнопки
	startWithMouse = draw.getSpriteStartWithMouse(window);
	optionsWithMouse = draw.getSpriteOptionsWithMouse(window);
	exitWithMouse = draw.getSpriteExitWithMouse(window);
	aboutWithMouse = draw.getSpriteAboutWithMouse(window);


    while (isMenu) {
        start.setColor(sf::Color::White);
        options.setColor(sf::Color::White);
        exit.setColor(sf::Color::White);
        menuNum = 0;

		start.setColor(sf::Color::White);
		options.setColor(sf::Color::White);
		exit.setColor(sf::Color::White);
		menuNum = 0;

		if (sf::IntRect((window.getSize().x - (draw.xSt / 5.0f)) / 2, window.getSize().y * 0.35f, window.getSize().x / 10.0f, window.getSize().y / 13.0f).contains(sf::Mouse::getPosition(window))) {
			menuNum = 1;
		}
		if (sf::IntRect((window.getSize().x - (draw.xOp / 5.0f)) / 2, window.getSize().y * 0.45f, window.getSize().x / 10.0f, window.getSize().y / 13.0f).contains(sf::Mouse::getPosition(window))) {
			menuNum = 2;
		}
		if (sf::IntRect((window.getSize().x - (draw.xEx / 5.0f)) / 2, window.getSize().y * 0.55f, window.getSize().x / 10.0f, window.getSize().y / 13.0f).contains(sf::Mouse::getPosition(window))) {
			menuNum = 3;
		}

		if (sf::IntRect(window.getSize().x * 0.97f - (draw.xAb / 10.0f), window.getSize().y * 0.92f - (draw.xAb / 10.0f), window.getSize().x / 18.0f, window.getSize().x / 18.0f).contains(sf::Mouse::getPosition(window))) {
			menuNum = 4;
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
				for (int i = 0; i < 50; i++) {
					options.setColor(sf::Color::White);

					start.move(10.f, 10.f);
					options.move(-10.f, -10.f);
					exit.move(-10.f, 10.f);
					about.move(0.0f, -15.0f);
					window.draw(draw.getSpriteMenuBackground(window));

					window.draw(start);

					window.draw(options);

					window.draw(exit);

					window.draw(about);

					window.display();
				}
				window.clear();
				return "start"; 
			}
			if (menuNum == 2) { 
				for (int i = 0; i < 50; i++) {
					options.setColor(sf::Color::White);

					start.move(10.f, 10.f);
					options.move(-10.f, -10.f);
					exit.move(-10.f, 10.f);
					about.move(0, -15.f);
					window.draw(draw.getSpriteMenuBackground(window));

					window.draw(start);

					window.draw(options);

					window.draw(exit);

					window.draw(about);

					window.display();
				}
				return "options";
			}
			if (menuNum == 3) {
				for (int i = 0; i < 50; i++) {
					options.setColor(sf::Color::White);

					start.move(10.f, 10.f);
					options.move(-10.f, -10.f);
					exit.move(-10.f, 10.f);
					about.move(0.0f, -15.0f);
					window.draw(draw.getSpriteMenuBackground(window));

					window.draw(start);

					window.draw(options);

					window.draw(exit);

					window.draw(about);

					window.display();
				}
				window.close();
				return "exit";
			}
			if (menuNum == 4) {
				for (int i = 0; i < 50; i++) {
					options.setColor(sf::Color::White);

					start.move(10.f, 10.f);
					options.move(-10.f, -10.f);
					exit.move(-10.f, 10.f);
					about.move(0.0f, -15.0f);

					window.draw(draw.getSpriteMenuBackground(window));

					window.draw(start);

					window.draw(options);

					window.draw(exit);

					window.draw(about);

					window.display();
				}
				return "about";
			}

		}
		else {

			window.draw(draw.getSpriteMenuBackground(window));

			window.draw(start);

			window.draw(options);

			window.draw(exit);

			window.draw(about);
			if (menuNum == 1)
				window.draw(startWithMouse);
			if (menuNum == 2)
				window.draw(optionsWithMouse);
			if (menuNum == 3)
				window.draw(exitWithMouse);
			if (menuNum == 4)
				window.draw(aboutWithMouse);

			window.display();
		}
	}
}
startMenu::~startMenu() {}
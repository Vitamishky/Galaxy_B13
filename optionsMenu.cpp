#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "optionsMenu.h"

optionsMenu::optionsMenu() {
	isMenu = true;
	menuNum = 0;
	musicNum = 1;
	backgroundNum = 1;
	soundValue = 5;
	drawAll draw;
}

std::pair < std::string, std::vector <int>> optionsMenu::drawOptionsMenu(sf::RenderWindow& window) {
	std::vector <int> v;
	background = draw.getSpriteMenuBackground(window);
	backWithMouse = draw.getSpriteBackWithMouse(window);
	music = draw.getSpriteMusic(window);
	back = draw.getSpriteBack(window);
	layout = draw.getSpriteLayout(window);
	changeBg = draw.getSpriteBackground(window);
	changeBg2 = draw.getSpriteBackgroundCat(window);

	music1 = draw.drawTextMusic1(window);
	music2 = draw.drawTextMusic2(window);
	music3 = draw.drawTextMusic3(window);
	textLayout = draw.drawTextLayout(window);
	
	while (isMenu) {
		music.setColor(sf::Color::White);
		background.setColor(sf::Color::White);
		changeBg.setColor(sf::Color::White);
		changeBg2.setColor(sf::Color::White);
		back.setColor(sf::Color::White);
		layout.setColor(sf::Color::White);
		menuNum = 0;
		music1.setFillColor(sf::Color::White);
		music2.setFillColor(sf::Color::White);
		music3.setFillColor(sf::Color::White);

		if (sf::IntRect(window.getSize().x * 0.05f - (draw.xAb / 10.0f), window.getSize().y * 0.88f - (draw.xAb / 10.0f), window.getSize().x / 13.0f, window.getSize().x / 13.0f).contains(sf::Mouse::getPosition(window))) {
			menuNum = 1;
		}
		if (sf::IntRect(window.getSize().x * 0.1f, window.getSize().y * 0.4f, music1.getGlobalBounds().width + 0.04f, music1.getGlobalBounds().height + 0.04f).contains(sf::Mouse::getPosition(window)))
			music1.setFillColor(sf::Color::Blue);
		if (sf::IntRect(window.getSize().x * 0.1f, window.getSize().y * 0.5f, music2.getGlobalBounds().width + 0.04f, music2.getGlobalBounds().height + 0.04f).contains(sf::Mouse::getPosition(window)))
			music2.setFillColor(sf::Color::Blue);
		if (sf::IntRect(window.getSize().x * 0.1f, window.getSize().y * 0.6f, music3.getGlobalBounds().width + 0.04f, music3.getGlobalBounds().height + 0.04f).contains(sf::Mouse::getPosition(window)))
			music3.setFillColor(sf::Color::Blue);
		
		if (sf::IntRect(window.getSize().x * 0.8f - (draw.xBgCat / 10.0f), window.getSize().y * 0.4f, changeBg2.getGlobalBounds().width , changeBg2.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
			changeBg2.setColor(sf::Color::Green);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//Если нажали кнопку
			if (menuNum == 1) {
				break;
			}
			//Если нажали кнопку
			if (menuNum == 2) {
				musicNum = 1;
			}
			//Если нажали кнопку
			if (menuNum == 3) {
				musicNum = 2;
			}
			if (menuNum == 4) {
				musicNum = 3;
			}
			v.push_back(musicNum);

			if (menuNum == 5) {
				backgroundNum = 1;
			}
			if (menuNum == 6) {
				backgroundNum = 3;
			}
			if (menuNum == 7) {
				backgroundNum = 3;
			}
			v.push_back(backgroundNum);
			v.push_back(soundValue);
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
		
		window.draw(textLayout);

		window.draw(changeBg);


		window.draw(changeBg2);

		if (menuNum == 1)
			window.draw(backWithMouse);

		window.display();
	}
	return std::make_pair("main", v); 
}
optionsMenu::~optionsMenu() {}

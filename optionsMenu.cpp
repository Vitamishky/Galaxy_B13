#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "optionsMenu.h"

optionsMenu::optionsMenu() {
	isMenu = true;
	menuNum = 0;
	musicNum = 0;
	backgroundNum = 0;
	soundValue = 5;
	drawAll draw;
}

std::pair < std::string, std::vector <int>> optionsMenu::drawOptionsMenu(sf::RenderWindow& window, sf::Texture texBg) {
	std::vector <int> v;
	v.push_back(backgroundNum);
	v.push_back(musicNum);
	v.push_back(soundValue);

	/*background = draw.getSpriteMenuBackground(window, texBg);*/
	backWithMouse = draw.getSpriteBackWithMouse(window);
	music = draw.getSpriteMusic(window);
	back = draw.getSpriteBack(window);
	layout = draw.getSpriteLayout(window);
	changeBg = draw.getSpriteBackground(window);
	changeBg1 = draw.getSpriteBackgroundMain(window);	
	changeBg2 = draw.getSpriteBackgroundCat(window);
	changeBg3 = draw.getSpriteBackgroundSpace(window);
	changeBg4 = draw.getSpriteBackgroundSpace2(window);
	sprite.setTexture(texBg);
	sprite.setScale(window.getSize().x / sprite.getGlobalBounds().width, window.getSize().y / sprite.getGlobalBounds().height);
	if (sprite.getGlobalBounds().width < window.getSize().x * 0.8f || sprite.getGlobalBounds().width > window.getSize().x * 1.2f)
		sprite.setScale(window.getSize().x / sprite.getGlobalBounds().width, window.getSize().y / sprite.getGlobalBounds().height);

	music1 = draw.drawTextMusic1(window);
	music2 = draw.drawTextMusic2(window);
	music3 = draw.drawTextMusic3(window);
	textLayout = draw.drawTextLayout(window);

	while (isMenu) {
		music.setColor(sf::Color::White);
		background.setColor(sf::Color::White);
		changeBg.setColor(sf::Color::White);
		changeBg1.setColor(sf::Color::White);
		changeBg2.setColor(sf::Color::White);
		changeBg3.setColor(sf::Color::White);
		changeBg4.setColor(sf::Color::White);
		back.setColor(sf::Color::White);
		layout.setColor(sf::Color::White);
		menuNum = 0;
		music1.setFillColor(sf::Color::White);
		music2.setFillColor(sf::Color::White);
		music3.setFillColor(sf::Color::White);

		if ((back.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			menuNum = 1;
		}
		if ((music1.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			music1.setFillColor(sf::Color::Blue);
			menuNum = 2;
		}
		if ((music2.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			music2.setFillColor(sf::Color::Blue);
			menuNum = 3;
		}
		if ((music3.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			music3.setFillColor(sf::Color::Blue);
			menuNum = 4;
		}
		if ((changeBg3.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			changeBg3.setColor(sf::Color::Red);
			menuNum = 7;
		}
		if ((changeBg2.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			changeBg2.setColor(sf::Color::Green);
			menuNum = 6;
		}
		if ((changeBg4.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			changeBg4.setColor(sf::Color::Magenta);
			menuNum = 8;
		}
		if ((changeBg1.getGlobalBounds()).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition().y - 0.04f * window.getSize().y)) {
			changeBg1.setColor(sf::Color::Yellow);
			menuNum = 5;
		}

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
			v[1] = musicNum;
		

			if (menuNum == 5) {
				backgroundNum = 0;
			//основной фон
			}
			if (menuNum == 6) {
				backgroundNum = 3;
			// котик
			}
			if (menuNum == 7) {
				backgroundNum = 1;
			// космос
			}
			if (menuNum == 8) {
				backgroundNum = 2;
			// космос2 (с планетой)
			}
			v[0] = backgroundNum;
			v[2] = soundValue;
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

		//if (backgroundNum == 0)
		//	window.draw(background);
		//if (backgroundNum == 1)
		//	window.draw(background);
		//if (backgroundNum == 2)
		//	window.draw(background);
		//if (backgroundNum == 3)
		//	window.draw(background);

		window.draw(sprite);

		window.draw(back);

		window.draw(music);
		
		window.draw(music1);

		window.draw(music2);

		window.draw(music3);

		window.draw(layout);
		
		window.draw(textLayout);

		window.draw(changeBg);

		window.draw(changeBg1);

		window.draw(changeBg2);

		window.draw(changeBg3);
		
		window.draw(changeBg4);

		if (menuNum == 1)
			window.draw(backWithMouse);

		window.display();

		window.clear();
	}
	return std::make_pair("main", v); 
}
optionsMenu::~optionsMenu() {}

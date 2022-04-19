#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "buildRocket.h"

buildRocket::buildRocket() {
	texBackground.loadFromFile("image/bg.png");
	texHeadRocket.loadFromFile("image/module1.png");
	texAirRocket.loadFromFile("image/module3.png");
	texEngineRocket.loadFromFile("image/module4.png");
	texEmptyRocket.loadFromFile("image/module2.png");
	texRAir.loadFromFile("image/module3.png");
	texREmpty.loadFromFile("image/module2.png");
	sprRAir.setTexture(texRAir);
	sprREmpty.setTexture(texREmpty);
	sprBackground.setTexture(texBackground);
	sprHeadRocket.setTexture(texHeadRocket);
	sprAirRocket.setTexture(texAirRocket);
	sprEngineRocket.setTexture(texEngineRocket);
	sprEmptyRocket.setTexture(texEmptyRocket);
	texRightInter.loadFromFile("image/right_panel.png");
	sprRightInter.setTexture(texRightInter);
	xRightInter = sprRightInter.getLocalBounds().width;
	yRightInter = sprRightInter.getLocalBounds().height;
}

std::string buildRocket::drawBuildRocket(sf::RenderWindow& window) {
	sprBackground.setScale(window.getSize().x / sprBackground.getGlobalBounds().width, window.getSize().y / sprBackground.getGlobalBounds().height);
	sprRightInter.setScale(window.getSize().x * 0.7f / xRightInter, window.getSize().y / yRightInter);
	sprRightInter.setPosition(sf::Vector2f(window.getSize().x * 0.7f, 0));
	sprRAir.setScale(window.getSize().x * 0.12f / sprRAir.getGlobalBounds().width, window.getSize().y * 0.15f / sprRAir.getGlobalBounds().height);
	sprREmpty.setScale(window.getSize().x * 0.12f / sprREmpty.getGlobalBounds().width, window.getSize().y * 0.15f / sprREmpty.getGlobalBounds().height);
	sprRAir.setPosition(window.getSize().x * 0.78f, window.getSize().y * 0.25f - sprRAir.getGlobalBounds().height / 2);
	sprREmpty.setPosition(window.getSize().x * 0.79f, window.getSize().y * 0.75f - sprREmpty.getGlobalBounds().height / 2);
	sizeXForSprite = (window.getSize().x * 0.7f - sprEngineRocket.getGlobalBounds().width) / 2;
	sizeYForSprite = window.getSize().y * 0.9f - sprEngineRocket.getGlobalBounds().height;
	m["Engine"].push_back(std::make_pair(sizeXForSprite, sizeYForSprite));
	window.setFramerateLimit(3);
	while (true) {
		sizeM = 0;
		sf::Event event;
		for (auto& c : m) {
			sizeM += c.second.size();
		}
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
				break;
			}

			
		}
		window.draw(sprBackground);
		
		window.draw(sprRightInter);

		window.draw(sprRAir);

		window.draw(sprREmpty);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sprRAir.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
			if (sizeM > 6) {
			
			}
			m["Air"].push_back(std::make_pair(sizeXForSprite, (sizeYForSprite - sizeM * sprAirRocket.getGlobalBounds().height)));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sprREmpty.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
			m["Empty"].push_back(std::make_pair(sizeXForSprite, (sizeYForSprite - sizeM * sprEmptyRocket.getGlobalBounds().height)));
		}

		for (auto& c : m) {
			if (c.first == "Engine") {
				for (auto& s : c.second) {
					sprEngineRocket.setPosition(s.first, s.second);
					window.draw(sprEngineRocket);
				}
			}
			if (c.first == "Air") {
				for (auto& s : c.second) {
					sprAirRocket.setPosition(s.first, s.second);
					window.draw(sprAirRocket);
				}
			}
			if (c.first == "Empty") {
				for (auto& s : c.second) {
					sprEmptyRocket.setPosition(s.first, s.second);
					window.draw(sprEmptyRocket);
				}
			}
			if (c.first == "Head") {
				for (auto& s : c.second) {
					sprHeadRocket.setPosition(s.first, s.second);
					window.draw(sprEmptyRocket);
				}
			}
		}
		
		window.display();

		window.clear();
	}
}
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

std::pair<std::string, std::vector<int>> buildRocket::drawBuildRocket(sf::RenderWindow& window) {
	sprBackground.setScale(window.getSize().x / sprBackground.getGlobalBounds().width, window.getSize().y / sprBackground.getGlobalBounds().height);
	sprRightInter.setScale(window.getSize().x * 0.7f / xRightInter, window.getSize().y / yRightInter);
	sprRightInter.setPosition(sf::Vector2f(window.getSize().x * 0.7f, 0));
	sprRAir.setScale(window.getSize().x * 0.12f / sprRAir.getGlobalBounds().width, window.getSize().y * 0.15f / sprRAir.getGlobalBounds().height);
	sprREmpty.setScale(window.getSize().x * 0.12f / sprREmpty.getGlobalBounds().width, window.getSize().y * 0.15f / sprREmpty.getGlobalBounds().height);
	sprRAir.setPosition(window.getSize().x * 0.78f, window.getSize().y * 0.25f - sprRAir.getGlobalBounds().height / 2);
	sprREmpty.setPosition(window.getSize().x * 0.79f, window.getSize().y * 0.75f - sprREmpty.getGlobalBounds().height / 2);
	sizeXForSprite = (window.getSize().x * 0.7f - sprEngineRocket.getGlobalBounds().width) / 2;
	sizeYForSprite = window.getSize().y * 0.9f - sprEngineRocket.getGlobalBounds().height;
	boundsAir = sprAirRocket.getGlobalBounds();
	boundsEmpty = sprEmptyRocket.getGlobalBounds();
	boundsEngine = sprEngineRocket.getGlobalBounds();
	boundsHead = sprHeadRocket.getGlobalBounds();
	spriteScale = sprAirRocket.getScale();
	std::vector<float> vHelp1 = { sizeXForSprite, sizeYForSprite, 0.f };
	m["Engine"].push_back(vHelp1);
	result.push_back(4);
	window.setFramerateLimit(3);
	while (true) {
		std::vector<float> vHelp2;
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
			vHelp2 = { sizeXForSprite, sizeYForSprite - sizeM * boundsAir.height, float(sizeM) };
			m["Air"].push_back(vHelp2);
			result.push_back(3);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sprREmpty.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
			vHelp2 = { sizeXForSprite,sizeYForSprite - sizeM * boundsEmpty.height , float(sizeM) };
			m["Empty"].push_back(vHelp2);
			result.push_back(2);
		}
		int numModule = 0;
		for (auto& c : m) {
			if (c.first == "Engine") {
				for (auto& s : c.second) {
					numModule++;
					if (sizeM > 6) {
						sprEngineRocket.setScale(spriteScale.x * 6 / (sizeM + 1), spriteScale.y * 6 / (sizeM + 1));
						sprEngineRocket.setPosition(s[0] + (1 - sprEngineRocket.getScale().x) * 0.5f * boundsEngine.width,
							s[1] + (1 + sprEngineRocket.getScale().y) * 0.5f * boundsEngine.height);
					}
					else {
						sprEngineRocket.setPosition(s[0], s[1]);
					}
					window.draw(sprEngineRocket);
				}
			}
			if (c.first == "Air") {
				for (auto& s : c.second) {
					numModule++;
					if (sizeM > 6) {
						sprAirRocket.setScale(spriteScale.x * 6 / (sizeM + 1), spriteScale.y * 6 / (sizeM + 1));
						sprAirRocket.setPosition(s[0] + (1 - sprAirRocket.getScale().x) * 0.5f * boundsAir.width,
							sprEngineRocket.getPosition().y - s[2] * sprAirRocket.getGlobalBounds().height);
					}
					else {
						sprAirRocket.setPosition(s[0], s[1]);
					}
					window.draw(sprAirRocket);
				}
			}
			if (c.first == "Empty") {
				for (auto& s : c.second) {
					numModule++;
					if (sizeM > 6) {
						sprEmptyRocket.setScale(spriteScale.x * 6 / (sizeM + 1), spriteScale.y * 6 / (sizeM + 1));
						sprEmptyRocket.setPosition(s[0] + (1 - sprEmptyRocket.getScale().x) * 0.5f * boundsEmpty.width,
							sprEngineRocket.getPosition().y - s[2] * sprEmptyRocket.getGlobalBounds().height);
					}
					else {
						sprEmptyRocket.setPosition(s[0], s[1]);
					}
					window.draw(sprEmptyRocket);
				}
			}
			if (c.first == "Head") {
				for (auto& s : c.second) {
					numModule++;
					if (sizeM > 6) {
						sprHeadRocket.setScale(spriteScale.x * 6 / (sizeM + 1), spriteScale.y * 6 / (sizeM + 1));
						sprHeadRocket.setPosition(s[0], s[1]);
					}
					else {
						sprHeadRocket.setPosition(s[0], s[1]);
					}
					window.draw(sprHeadRocket);
				}
			}
		}

		window.display();
		if (sizeM > 10)
			break;
		window.clear();
		
	}
	return std::make_pair("go", result);
}
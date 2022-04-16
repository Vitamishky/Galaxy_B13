#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
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
	m["Engine"].push_back(std::make_pair(window.getSize().x / 2, window.getSize().y / 2));

	while (true) {
		
		sf::Event event;

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

		for (auto& c : m) {
			if (c.first == "Engine") {
				for (auto& s : c.second) {
					sprEngineRocket.setPosition(s.first, s.second);
					window.draw(sprEngineRocket);
				}
			}
			if (c.first == "Air") {
				for (auto& s : c.second) {

				}
			}
			if (c.first == "Empty") {
				for (auto& s : c.second) {

				}
			}
			if (c.first == "Head") {
				for (auto& s : c.second) {

				}
			}
		}
		
		window.draw(sprHeadRocket);

		window.draw(sprAirRocket);

		window.draw(sprEngineRocket);

		window.draw(sprEmptyRocket);
		
		window.display();

		window.clear();
	}
}
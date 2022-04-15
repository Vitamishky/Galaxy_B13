#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "buildRocket.h"

buildRocket::buildRocket() {
	texBackground.loadFromFile("image/background");
	sprBackground.setTexture(texBackground);
}

std::string buildRocket::drawBuildRocket(sf::RenderWindow& window) {
	sprBackground.setScale(window.getSize().x / sprBackground.getGlobalBounds().width, window.getSize().y / sprBackground.getGlobalBounds().height);
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

		window.display();
	}
}
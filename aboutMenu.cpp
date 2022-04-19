#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "aboutMenu.h"

aboutMenu::aboutMenu() {
	drawAll draw;
}

string aboutMenu::drawAboutMenu(sf::RenderWindow& window) {
	text = draw.drawTextAbout(window);
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
		window.draw(draw.getSpriteMenuBackground(window));

		window.draw(text);

		window.display();
	}
	return "back";
}
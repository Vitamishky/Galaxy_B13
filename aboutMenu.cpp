#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "aboutMenu.h"

aboutMenu::aboutMenu() {
	drawAll draw;
}

string aboutMenu::drawAboutMenu(sf::RenderWindow& window, sf::Texture texBg) {
	text = draw.drawTextAbout(window);
	back = draw.getSpriteBack(window);
	backWithMouse = draw.getSpriteBackWithMouse(window);
	sprite.setTexture(texBg);
	sprite.setScale(window.getSize().x / sprite.getGlobalBounds().width, window.getSize().y / sprite.getGlobalBounds().height);
	if (sprite.getGlobalBounds().width < window.getSize().x * 0.8f || sprite.getGlobalBounds().width > window.getSize().x * 1.2f)
		sprite.setScale(window.getSize().x / sprite.getGlobalBounds().width, window.getSize().y / sprite.getGlobalBounds().height);

	while (true) {
		menuNum = 0;
		if (sf::IntRect(window.getSize().x * 0.05f - (draw.xAb / 10.0f), window.getSize().y * 0.88f - (draw.xAb / 10.0f), window.getSize().x / 13.0f, window.getSize().x / 13.0f).contains(sf::Mouse::getPosition(window))) {
			menuNum = 1;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (menuNum == 1) 
				break;
		}

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
		window.draw(sprite);

		window.draw(text);

		window.draw(back);

		if (menuNum == 1) {
			window.draw(backWithMouse);
		}

		window.display();
	}
	return "main";
}
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class buildRocket {
private:
	sf::Texture texBackground;
	sf::Sprite sprBackground;
public:
	buildRocket();
	std::string drawBuildRocket(sf::RenderWindow&);
};

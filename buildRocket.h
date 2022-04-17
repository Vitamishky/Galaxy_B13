#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>

class buildRocket {
private:
	sf::Texture texBackground, texHeadRocket, texAirRocket, texEmptyRocket, texEngineRocket, texRightInter;
	sf::Sprite sprBackground, sprHeadRocket, sprAirRocket, sprEmptyRocket, sprEngineRocket, sprRightInter;
	sf::Texture texREmpty, texRAir;
	sf::Sprite sprREmpty, sprRAir;
	float xRightInter, yRightInter;
	std::map<std::string, std::vector<std::vector<float>>> m;
	int sizeM;
	float sizeXForSprite, sizeYForSprite;
	sf::Vector2f spriteScale;
	sf::FloatRect boundsAir, boundsEmpty, boundsHead, boundsEngine; 
	std::vector<int> result;
public:
	buildRocket();
	std::pair < std::string, std::vector<int>> drawBuildRocket(sf::RenderWindow&);
};

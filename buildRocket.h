#pragma once
#ifndef buildRocket_hpp
#define buildRocket_hpp
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
	std::map<std::string, std::vector<std::pair<float, float>>> m;
	int sizeM;
	float sizeXForSprite, sizeYForSprite;
public:
	buildRocket();
	std::string drawBuildRocket(sf::RenderWindow&);
};
#endif
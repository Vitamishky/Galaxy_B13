#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include "drawAll.h"

class buildRocket {
private:
	sf::Texture texBackground, texHeadRocket, texAirRocket, texEmptyRocket, texEngineRocket, texRightInter;
	sf::Sprite sprBackground, sprHeadRocket, sprAirRocket, sprEmptyRocket, sprEngineRocket, sprRightInter;
	sf::Texture texREmpty, texRAir;
	sf::Sprite sprREmpty, sprRAir;
	float xRightInter, yRightInter;
	sf::Sprite play, playWithMouse, back, backWithMouse, built, builtWithMouse;
	std::map<std::string, std::vector<std::pair<float, float>>> m;
	int menuNum;
	drawAll draw;
public:
	buildRocket();
	std::string drawBuildRocket(sf::RenderWindow&);
};

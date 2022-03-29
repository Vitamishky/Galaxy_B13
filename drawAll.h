#ifndef drawAll_hpp
#define drawAll_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace std;

class drawAll {
private:
	sf::Texture texBg;
	float xBg;
	float yBg;
	sf::Sprite sprBg;
public:
	drawAll();
	void drawBg(sf::RenderWindow&);
	void drawIcon(sf::RenderWindow&);
	~drawAll();
};

#endif 
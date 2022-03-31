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
	sf::Sprite sprBg;
public:
	drawAll();
	void drawBg(sf::RenderWindow&, sf::View);
	void drawIcon(sf::RenderWindow&);
	~drawAll();
};

#endif 
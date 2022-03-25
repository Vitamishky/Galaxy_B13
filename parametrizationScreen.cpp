#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceObjects.h"
#include "parametrizationScreen.h"

using namespace std;

parametrizationScreen::parametrizationScreen() {
	width = sf::VideoMode::getFullscreenModes()[0].width;
	height = sf::VideoMode::getFullscreenModes()[0].height;
}

pair<unsigned int, unsigned int> parametrizationScreen::getParametrizationScreen() {
	return make_pair(width, height);
}

parametrizationScreen::~parametrizationScreen() {}
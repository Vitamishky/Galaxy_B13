#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "camera.h"

using namespace std;

camera::camera(sf::RenderWindow& window) {
	locked = false;
	view = window.getView();
}

void camera::lockedCamera(float x, float y) {
	position.x = x;
	position.y = y;
	locked = true;
}

void camera::unlockCamera() {
	locked = false;
}

void camera::moveCamera(float x, float y) {
	if (locked) {
		view.move(position.x - x, position.y - y);
		position.x = x;
		position.y = y;
	}
}

sf::View camera::getViewCamera() {
	return view;
}

sf::View camera::getCoordinatesForView(float x, float y) {
	view.setCenter(x + 100, y);
	return view;
}

void camera::resetView() {
	view.reset(sf::FloatRect(0, 0, 1900, 1050));
}

camera::~camera() {};
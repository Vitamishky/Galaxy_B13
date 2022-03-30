#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "camera.h"

using namespace std;

camera::camera(sf::RenderWindow& window) {
	locked = false;
	view = window.getView();
	scale = 2.0f;
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

void camera::resetView(sf::RenderWindow& window) {
	view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
}

void camera::zoomCamera(sf::Event scroll, sf::RenderWindow& window) {
	float ws = window.getSize().x / 2 + window.getPosition().x;
	float hs = window.getSize().y / 2 + window.getPosition().y;
	sf::Vector2f raznica = sf::Vector2f(sf::Mouse::getPosition().x - ws, sf::Mouse::getPosition().y - hs);

	if (scroll.mouseWheelScroll.delta < 0) {
		float addict = 0.1f * scale;
		view.move(raznica * -addict);
		scale += addict;
	}
	else if (scroll.mouseWheelScroll.delta > 0) {
		float addict = -0.1f * scale;
		view.move(raznica * -addict);
		scale += addict;
	}
	view.setSize(window.getSize().x * scale, window.getSize().y * scale);
}

camera::~camera() {};
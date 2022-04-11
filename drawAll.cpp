#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "drawAll.h"

drawAll::drawAll() {
	font.loadFromFile("image/Impact.ttf");
	text.setString("Speed");
	vLText.push_back(text);
	text.setString("Fuel consumption");
	vLText.push_back(text);
	text.setString("Mass");
	vLText.push_back(text);
	text.setString("Target distance");
	vLText.push_back(text);
	for (int i = 0; i < vLText.size(); i++) {
		vLText[i].setFont(font);
	}

    texBg.loadFromFile("image/bg.png");
    sprBg.setTexture(texBg);
	icon.loadFromFile("image/spaceShip.png");
	// Отрисовка интерфейса
	texCompasRadar.loadFromFile("image/accelerator_radar.png");
	shapeCompas.setTexture(&texCompasRadar);
	texArrow.loadFromFile("image/accelerator_arrow.png");
	sprArrow.setTexture(texArrow);
	texLeftInter.loadFromFile("image/left_panel.png");
	sprLeftInter.setTexture(texLeftInter);
	texRightInter.loadFromFile("image/right_panel.png");
	sprRightInter.setTexture(texRightInter);
	texFuel.loadFromFile("image/fuel_panel.png");
	sprFuel.setTexture(texFuel);
	//отрисовка главного меню
	buttonPlayFull.loadFromFile("image/spaceShip.png");
	buttonOptionsFull.loadFromFile("image/buttons.png");
	buttonExitFull.loadFromFile("image/buttons.png");
	aboutTextureFull.loadFromFile("image/buttons.png");
	menuBackground.loadFromFile("image/background.jpg");
	buttonPlay.setTexture(buttonPlayFull);
	buttonOptions.setTexture(buttonOptionsFull);
	buttonExit.setTexture(buttonExitFull);
	aboutTexture.setTexture(aboutTextureFull);
	menuBg.setTexture(menuBackground);
	buttonPlay.setTextureRect(sf::IntRect(34, 138, 50, 20));
	buttonOptions.setTextureRect(sf::IntRect(253, 138, 50, 20));
	buttonExit.setTextureRect(sf::IntRect(542, 138, 50, 20));
	aboutTexture.setTextureRect(sf::IntRect(0, 138, 50, 20));
	xBg = menuBackground.getSize().x;
	yBg = menuBackground.getSize().y;
	xPl = buttonPlay.getTextureRect().width;
	yPl = buttonPlay.getTextureRect().height;
	xOp = buttonOptions.getTextureRect().width;
	yOp = buttonOptions.getTextureRect().height;
	xEx = buttonExit.getTextureRect().width;
	yEx = buttonExit.getTextureRect().height;
	xAb = aboutTexture.getTextureRect().width;
	yAb = aboutTexture.getTextureRect().height;
}

void drawAll::drawBg(sf::RenderWindow& window, sf::View view) {
    float vSize_x = 1.5f * view.getSize().x;
    float vSize_y = 1.5f * view.getSize().y;
    float xBg = sprBg.getLocalBounds().width;
    float yBg = sprBg.getLocalBounds().height;
    sprBg.setScale(vSize_x / xBg, vSize_y / yBg);
    sprBg.setPosition(sf::Vector2f(view.getCenter().x - vSize_x / 2, view.getCenter().y - vSize_y / 2));
    window.draw(sprBg);
}

void drawAll::drawIcon(sf::RenderWindow& window) {
    //Отрисовка иконки около названия окна
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void drawAll::drawLeftInter(sf::RenderWindow& window, sf::View view) {
	float vSize_x = 0.15f * view.getSize().x;
	float vSize_y = 0.8f * view.getSize().y;
	float xLeftInter = sprLeftInter.getLocalBounds().width;
	float yLeftInter = sprLeftInter.getLocalBounds().height;
	sprLeftInter.setScale(vSize_x / xLeftInter, vSize_y / yLeftInter);
	sprLeftInter.setPosition(sf::Vector2f(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - vSize_y / 2));
	window.draw(sprLeftInter);
	for (int i = 0; i < vLText.size(); i++) {
		vLText[i].setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
		vLText[i].setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - vSize_y  / 2 + view.getCenter().y * (0.02f + i * 0.2f));
		window.draw(vLText[i]);
	}
}

void drawAll::drawRightInter(sf::RenderWindow& window, sf::View view) {
	float vSize_x = 0.15f * view.getSize().x;
	float vSize_y = 0.8f * view.getSize().y;
	float xRightInter = sprRightInter.getLocalBounds().width;
	float yRightInter = sprRightInter.getLocalBounds().height;
	sprRightInter.setScale(vSize_x / xRightInter, vSize_y / yRightInter);
	sprRightInter.setPosition(sf::Vector2f(view.getCenter().x + view.getSize().x / 2 - vSize_x, view.getCenter().y - vSize_y / 2));
	window.draw(sprRightInter);
}

void drawAll::drawFuel(sf::RenderWindow& window, sf::View view) {
	float vSize_x = 0.2f * view.getSize().x;
	float vSize_y = 0.07f * view.getSize().y;
	float xFuel = sprFuel.getLocalBounds().width;
	float yFuel = sprFuel.getLocalBounds().height;
	sprFuel.setScale(vSize_x / xFuel, vSize_y / yFuel);
	sprFuel.setPosition(sf::Vector2f(view.getCenter().x - vSize_x / 2, view.getCenter().y - view.getSize().y / 2));
	window.draw(sprFuel);
}

void drawAll::drawCompas(sf::RenderWindow& window, sf::View view) {
	float vSize_x = 0.1f * view.getSize().x;
	float xCompas = shapeCompas.getLocalBounds().width;
	shapeCompas.setRadius(vSize_x);
	//shapeCompas.setOrigin(view.getCenter().x, view.getCenter().y);
	shapeCompas.setPosition(view.getCenter().x - vSize_x, view.getCenter().y + view.getSize().y / 2 - vSize_x);
	//shapeCompas.rotate(-10);
	window.draw(shapeCompas);
}

void drawAll::drawArrow(sf::RenderWindow& window, sf::View view) {
	float vSize_x = 0.25f * view.getSize().x;
	float vSize_y = 0.3f * view.getSize().y;
	float xArrow = sprArrow.getLocalBounds().width;
	float yArrow = sprArrow.getLocalBounds().height;
	sprArrow.setScale(vSize_x / xArrow, vSize_y / yArrow);
	sprArrow.setPosition(sf::Vector2f(view.getCenter().x - vSize_x / 2, view.getCenter().y + view.getSize().y * 0.31f));
	window.draw(sprArrow);
}

sf::Sprite drawAll::getSpritePlay(sf::RenderWindow& window) {
	play = buttonPlay; 
	play.setPosition((window.getSize().x - xPl) / 2, window.getSize().y * 0.45f);
	return play;
}

sf::Sprite drawAll::getSpriteOptions(sf::RenderWindow& window) {
	options = buttonOptions;
	options.setPosition((window.getSize().x - xOp) / 2, window.getSize().y * 0.5f);
	return options;
}

sf::Sprite drawAll::getSpriteMenuBackground(sf::RenderWindow& window) {
	menuBg.setScale(window.getSize().x / xBg, window.getSize().y / yBg);
	return menuBg;
}

sf::Sprite drawAll::getSpriteAbout(sf::RenderWindow& window) {
	about = aboutTexture;
	about.setPosition(window.getSize().x * 0.8f, window.getSize().y * 0.8f);
	return about;
}

sf::Sprite drawAll::getSpriteExit(sf::RenderWindow& window) {
	exit = buttonExit;
	exit.setPosition((window.getSize().x - xEx) / 2, window.getSize().y * 0.55f);
	return exit;
}

void drawAll::moveMenu(sf::RenderWindow& window, vector<sf::Sprite> vS_out, vector<sf::Sprite> vS_cin) {
	float tick = 0.005;
	for (int j = 0; j < window.getSize().x; j++) {
		for (int i = 0; i < vS_out.size(); i++) {
			sf::Vector2f vout = vS_out[i].getPosition();
			vS_out[i].setPosition(sf::Vector2f(vout.x - tick, vout.y));
			window.draw(vS_out[i]);
		}
		for (int i = 0; i < vS_cin.size(); i++) {
			sf::Vector2f vcin = vS_cin[i].getPosition();
			vS_cin[i].setPosition(sf::Vector2f(vcin.x - tick, vcin.y));
			window.draw(vS_cin[i]);
		}
	}
}

drawAll::~drawAll() {}
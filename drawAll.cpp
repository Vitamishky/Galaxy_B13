#define _USE_MATH_DEFINES
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "drawAll.h"
#include "MODULE.h"
#include <cmath>
#include "spaceShip.h"

drawAll::drawAll() {
	font.loadFromFile("image/Impact.ttf");
	text.setString("Speed");
	vLText.push_back(text);
	text.setString("Fuel consumption");
	vLText.push_back(text);
	text.setString("Air consumption");
	vLText.push_back(text);
	text.setString("Mass");
	vLText.push_back(text);
	text.setString("Target distance");
	vLText.push_back(text);
	textMass.setString("4");
	textMass.setFont(font);
	textAbout.setString("Here’s the text we wanted to write to make the player better understand our game, \n\
feel it fully. We would have written a wonderful description of our work on the game. How we found \n\
mistakes, corrected them. this fleeting and inspiring feeling of creating something new. But no one \n\
                 told me what to write here, so I decided to write from myself)");
	textAbout.setFont(font);
	for (int i = 0; i < vLText.size(); i++) {
		vLText[i].setFont(font);
	}
	texBg.loadFromFile("image/bg.png");
	sprBg.setTexture(texBg);
	icon.loadFromFile("image/spaceShip.png");
	// Îòðèñîâêà èíòåðôåéñà
	texCompasRadar.loadFromFile("image/accelretor_radar.png");
	shapeCompas.setTexture(&texCompasRadar);
	texArrow.loadFromFile("image/accelerator_arrow.png");
	sprArrow.setTexture(texArrow);
	texLeftInter.loadFromFile("image/left_panel.png");
	sprLeftInter.setTexture(texLeftInter);
	texRightInter.loadFromFile("image/right_panel.png");
	sprRightInter.setTexture(texRightInter);
	texFuel.loadFromFile("image/fuel_panel.png");
	sprFuel.setTexture(texFuel);
	texFuelPanel.loadFromFile("image/fuel.png");
	sprFuelPanel.setTexture(texFuelPanel);
	texAirPanel.loadFromFile("image/air.png");
	sprAirPanel.setTexture(texAirPanel);
	//îòðèñîâêà ãëàâíîãî ìåíþ
	//отрисовка главного меню
	buttonStartFull.loadFromFile("image/start1.png");
	buttonOptionsFull.loadFromFile("image/options1.png");
	buttonExitFull.loadFromFile("image/exit1.png");
	aboutTextureFull.loadFromFile("image/about1.png");
	menuBackground.loadFromFile("image/background.jpg");

	buttonStartFull_1.loadFromFile("image/start2.png");
	buttonOptionsFull_1.loadFromFile("image/options2.png");
	buttonExitFull_1.loadFromFile("image/exit2.png");
	aboutTextureFull_1.loadFromFile("image/about2.png");

	buttonStartWithMouse.setTexture(buttonStartFull_1);
	buttonOptionsWithMouse.setTexture(buttonOptionsFull_1);
	buttonExitWithMouse.setTexture(buttonExitFull_1);
	aboutTextureWithMouse.setTexture(aboutTextureFull_1);

	buttonStart.setTexture(buttonStartFull);
	buttonOptions.setTexture(buttonOptionsFull);
	buttonExit.setTexture(buttonExitFull);
	aboutTexture.setTexture(aboutTextureFull);
	menuBg.setTexture(menuBackground);

	//отрисовка настроек
	buttonSettingsFull.loadFromFile("image/settings.png");
	buttonMusicFull.loadFromFile("image/music.png");
	buttonBackgroundFull.loadFromFile("image/buttonBackground.png");
	buttonBackFull.loadFromFile("image/back1.png");
	buttonBackFull_1.loadFromFile("image/back2.png");

	buttonSettings.setTexture(buttonSettingsFull);
	buttonMusic.setTexture(buttonMusicFull);
	buttonBack.setTexture(buttonBackFull);
	buttonBackWithMouse.setTexture(buttonBackFull_1);
	buttonBackground.setTexture(buttonBackgroundFull);

	xBg = menuBackground.getSize().x;
	yBg = menuBackground.getSize().y;
	xSt = buttonStart.getTextureRect().width;
	ySt = buttonStart.getTextureRect().height;
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
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void drawAll::drawLeftInter(sf::RenderWindow& window, sf::View view, spaceShip ship) {
	float vSize_x = 0.15f * view.getSize().x;
	float vSize_y = 0.8f * view.getSize().y;
	float xLeftInter = sprLeftInter.getLocalBounds().width;
	float yLeftInter = sprLeftInter.getLocalBounds().height;
	sprLeftInter.setScale(vSize_x / xLeftInter, vSize_y / yLeftInter);
	sprLeftInter.setPosition(sf::Vector2f(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - vSize_y / 2));
	window.draw(sprLeftInter);
	textSpeed.setString(to_string(ship.SPEED()));
	textSpeed.setFont(font);
	textSpeed.setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
	textSpeed.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * 0.21f);
	window.draw(textSpeed);
	textFuelConsumption.setFont(font);
	textFuelConsumption.setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
	textFuelConsumption.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * 0.33f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ship.FUEL() != 0)
		textFuelConsumption.setString("1");
	else
		textFuelConsumption.setString("0");
	window.draw(textFuelConsumption);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::X)) && ship.AIR() != 0)
		textAirConsumption.setString("1");
	else
		textAirConsumption.setString("0");
	textAirConsumption.setFont(font);
	textAirConsumption.setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
	textAirConsumption.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * 0.45f);
	window.draw(textAirConsumption);
	textMass.setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
	textMass.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * 0.57f);
	window.draw(textMass);
	for (int i = 0; i < vLText.size(); i++) {
		vLText[i].setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
		vLText[i].setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * (0.15f + i * 0.12f));
		window.draw(vLText[i]);
	}

}

void drawAll::drawTextAboutAll(sf::RenderWindow& window, sf::View view, spaceShip ship) {
	float vSize_x = 0.15f * view.getSize().x;
	float vSize_y = 0.8f * view.getSize().y;
	float xRightInter = sprRightInter.getLocalBounds().width;
	float yRightInter = sprRightInter.getLocalBounds().height;
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
	if (ship.getSprite()[0].getGlobalBounds().contains(pos.x, pos.y) ||
		ship.getSprite()[1].getGlobalBounds().contains(pos.x, pos.y) ||
		ship.getSprite()[2].getGlobalBounds().contains(pos.x, pos.y) ||
		ship.getSprite()[3].getGlobalBounds().contains(pos.x, pos.y)) {
		textSpace.setString(\
			"This is our ship, our home. We used to \n\
fly in weightlessness, eat from a tube \n\
and look at the stars from the porthole. \n\
Our captain, John, likes to cook, so \n\
we`re letting him in the fuel module. \n\
We`re a spaceship, not a missile. But \n\
we respect him, because no one but him \n\
could have built a rocket like that in \n\
a month from improvesed materials");
	}
	else {
		textSpace.setString(\
			"An open and violent space that`s been \n\
around me for months. It seems like \n\
just yesterday I was home, and now \n\
I`m rushing into the unknown. What`s \n\
next? Victory? Defeat? Now it`s \n\
up to you, my friend. Don`t let me down. \n\
People from Earth, from our ship, and I \n\
believe in you");
	}
	textSpace.setFont(font);
	textSpace.setScale(vSize_x * 1.88f / xRightInter, vSize_y * 2.f / yRightInter);
	textSpace.setPosition(view.getCenter().x + view.getSize().x * 0.355f, view.getCenter().y + view.getSize().y * 0.08f);
	window.draw(textSpace);
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

void drawAll::drawFuel(sf::RenderWindow& window, sf::View view, spaceShip ship) {
	float vSize_x = 0.2f * view.getSize().x;
	float vSize_y = 0.07f * view.getSize().y;
	float xFuel = sprFuel.getLocalBounds().width;
	float yFuel = sprFuel.getLocalBounds().height;
	float xFuelPanel = sprFuelPanel.getGlobalBounds().width;
	float yFuelPanel = sprFuelPanel.getGlobalBounds().height;
	sprFuel.setScale(vSize_x / xFuel, vSize_y / yFuel);
	sprFuel.setPosition(sf::Vector2f(view.getCenter().x - vSize_x / 2, view.getCenter().y - view.getSize().y / 2));
	window.draw(sprFuel);
	sprFuelPanel.setScale(vSize_x * ship.FUEL()/ (xFuel * 1000), vSize_y / yFuel);
	sprFuelPanel.setPosition(view.getCenter().x - view.getSize().x * 0.086f, view.getCenter().y - view.getSize().y * 0.481f);
	window.draw(sprFuelPanel);
	sprAirPanel.setScale(vSize_x * ship.AIR()/ (xFuel * 1000), vSize_y / yFuel);
	sprAirPanel.setPosition(view.getCenter().x + view.getSize().x * 0.0136f, view.getCenter().y - view.getSize().y * 0.481f);
	window.draw(sprAirPanel);
}

void drawAll::drawCompas(sf::RenderWindow& window, sf::View view, spaceShip ship) {
	float vSize_x = 0.1f * view.getSize().x;
	float xCompas = shapeCompas.getLocalBounds().width;
	shapeCompas.setRadius(vSize_x);
	shapeCompas.setPosition(view.getCenter().x, view.getCenter().y + view.getSize().y / 2);
	shapeCompas.setOrigin(vSize_x, vSize_x);
	shapeCompas.setRotation(-1.f * ship.ANGLE() * 180/M_PI + 180);
	window.draw(shapeCompas);

}

void drawAll::drawArrow(sf::RenderWindow& window, sf::View view) {
	float vSize_x = 0.25f * view.getSize().x;
	float vSize_y = 0.3f * view.getSize().y;
	float xArrow = sprArrow.getLocalBounds().width;
	float yArrow = sprArrow.getLocalBounds().height;
	sprArrow.setScale(vSize_x / xArrow, vSize_y / yArrow);
	sprArrow.setPosition(sf::Vector2f(view.getCenter().x - vSize_x / 2, view.getCenter().y + view.getSize().y * 0.33f));
	window.draw(sprArrow);
}

sf::Sprite drawAll::getSpriteStart(sf::RenderWindow& window) {
	buttonStart.setScale(window.getSize().x / (10.0f * xSt), window.getSize().y / (ySt * 13.0f));
	buttonStart.setPosition((window.getSize().x - (xSt / 5.0f)) / 2, window.getSize().y * 0.35f);
	return buttonStart;
}

sf::Sprite drawAll::getSpriteStartWithMouse(sf::RenderWindow& window) {
	buttonStartWithMouse.setScale(window.getSize().x / (10.0f * xSt), window.getSize().y / (ySt * 13.0f));
	buttonStartWithMouse.setPosition((window.getSize().x - (xSt / 5.0f)) / 2, window.getSize().y * 0.35f);
	return buttonStartWithMouse;
}

sf::Sprite drawAll::getSpriteOptions(sf::RenderWindow& window) {
	buttonOptions.setScale(window.getSize().x / (10.0f * xOp), window.getSize().y / (yOp * 13.0f));
	buttonOptions.setPosition((window.getSize().x - (xOp / 5.0f)) / 2, window.getSize().y * 0.45f);
	return buttonOptions;
}

sf::Sprite drawAll::getSpriteOptionsWithMouse(sf::RenderWindow& window) {
	buttonOptionsWithMouse.setScale(window.getSize().x / (10.0f * xOp), window.getSize().y / (yOp * 13.0f));
	buttonOptionsWithMouse.setPosition((window.getSize().x - (xOp / 5.0f)) / 2, window.getSize().y * 0.45f);
	return buttonOptionsWithMouse;
}
sf::Sprite drawAll::getSpriteExit(sf::RenderWindow& window) {
	buttonExit.setScale(window.getSize().x / (10.0f * xEx), window.getSize().y / (yEx * 13.0f));
	buttonExit.setPosition((window.getSize().x - (xOp / 5.0f)) / 2, window.getSize().y * 0.55f);
	return buttonExit;
}

sf::Sprite drawAll::getSpriteExitWithMouse(sf::RenderWindow& window) {
	buttonExitWithMouse.setScale(window.getSize().x / (10.0f * xEx), window.getSize().y / (yEx * 13.0f));
	buttonExitWithMouse.setPosition((window.getSize().x - (xOp / 5.0f)) / 2, window.getSize().y * 0.55f);
	return buttonExitWithMouse;
}

sf::Sprite drawAll::getSpriteMenuBackground(sf::RenderWindow& window) {
	menuBg.setScale(window.getSize().x / xBg, window.getSize().y / yBg);
	return menuBg;
}

sf::Sprite drawAll::getSpriteAbout(sf::RenderWindow& window) {
	aboutTexture.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	aboutTexture.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return aboutTexture;
}

sf::Sprite drawAll::getSpriteAboutWithMouse(sf::RenderWindow& window) {
	aboutTextureWithMouse.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	aboutTextureWithMouse.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return aboutTextureWithMouse;
}

//Спрайты для настроек
sf::Sprite drawAll::getSpriteBackWithMouse(sf::RenderWindow& window) {
	buttonBackWithMouse.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	buttonBackWithMouse.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return buttonBackWithMouse;
}

sf::Sprite drawAll::getSpriteBack(sf::RenderWindow& window) {
	buttonBack.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	buttonBack.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return buttonBack;
}

sf::Sprite drawAll::getSpriteSettings(sf::RenderWindow& window) {
	buttonSettings.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	buttonSettings.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return buttonSettings;
}

sf::Sprite drawAll::getSpriteMusic(sf::RenderWindow& window) {
	buttonMusic.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	buttonMusic.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return buttonMusic;
}

sf::Sprite drawAll::getSpriteBackground(sf::RenderWindow& window) {
	buttonBackground.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	buttonBackground.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return buttonBackground;
}

sf::Sprite drawAll::getSpriteLayout(sf::RenderWindow& window) {
	buttonLayout.setScale(window.getSize().x / (13.0f * xAb), window.getSize().x / (yAb * 13.0f));
	buttonLayout.setPosition(window.getSize().x * 0.95f - (xAb / 10.0f), window.getSize().y * 0.9f - (xAb / 10.0f));
	return buttonLayout;
}

sf::Text drawAll::drawTextAbout(sf::RenderWindow& window) {
	float xText = textAbout.getGlobalBounds().width;
	float yText = textAbout.getGlobalBounds().height;
	textAbout.setScale(window.getSize().x / xText * 0.5f, window.getSize().y / yText * 0.5f);
	//textAbout.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	return textAbout;
}
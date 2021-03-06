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
	textAbout.setString("Here is the text we wanted to write to make the player better understand our game, \n\
feel it fully. We would have written a wonderful description of our work on the game. How we found \n\
mistakes, corrected them. This fleeting and inspiring feeling of creating something new. But no one \n\
                 told me what to write here, so I decided to write from myself :-)");
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
	texShapeShip.loadFromFile("image/astronaut.png");
	texEmptyPlanet.loadFromFile("image/empty_planet.png");
	texNotEmptyPlanet.loadFromFile("image/kerbals.png");
	texSpace.loadFromFile("image/space_circle.png");
	shapeEmptyPlanet.setTexture(&texEmptyPlanet);
	shapeRocket.setTexture(&texShapeShip);
	shapeNotEmptyPlanet.setTexture(&texNotEmptyPlanet);
	shapeSpace.setTexture(&texSpace);
	//отрисовка главного меню
	buttonStartFull.loadFromFile("image/start1.png");
	buttonOptionsFull.loadFromFile("image/options1.png");
	buttonExitFull.loadFromFile("image/exit1.png");
	aboutTextureFull.loadFromFile("image/about1.png");
	menuBackgroundCat.loadFromFile("image/backgroundCat.jpg");
	menuBackgroundSpace.loadFromFile("image/backgroundSpace.jpg");
	menuBackgroundSpace2.loadFromFile("image/backgroundSpace2.jpg");
	menuBackground.loadFromFile("image/background.jpg");

	finalPicture.loadFromFile("image/final.jpg");
	texfinalDied.loadFromFile("image/1234.png");
	texfinalWin.loadFromFile("image/win.jpg");

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
	menuBgCat.setTexture(menuBackgroundCat);
	menuBgSpace.setTexture(menuBackgroundSpace);
	menuBgSpace2.setTexture(menuBackgroundSpace2);
	menuBgMain.setTexture(menuBackground);

	finalMeme.setTexture(finalPicture);
	finalDied.setTexture(texfinalDied);
	finalWin.setTexture(texfinalWin);

	//отрисовка настроек
	buttonLayoutFull.loadFromFile("image/layout.png");
	buttonMusicFull.loadFromFile("image/music.png");
	buttonBackgroundFull.loadFromFile("image/buttonBackground.png");
	buttonBackFull.loadFromFile("image/back1.png");
	buttonBackFull_1.loadFromFile("image/back2.png");
	buttonPlayFull.loadFromFile("image/play1.png");
	buttonPlayFull_1.loadFromFile("image/play2.png");
	buttonBuiltFull.loadFromFile("image/built1.png");
	buttonBuiltFull_1.loadFromFile("image/built2.png");

	buttonMusic.setTexture(buttonMusicFull);
	buttonBack.setTexture(buttonBackFull);
	buttonBackWithMouse.setTexture(buttonBackFull_1);
	buttonBackground.setTexture(buttonBackgroundFull);
	buttonLayout.setTexture(buttonLayoutFull);

	buttonPlay.setTexture(buttonPlayFull);
	buttonPlayWithMouse.setTexture(buttonPlayFull_1);
	buttonBuilt.setTexture(buttonBuiltFull);
	buttonBuiltWithMouse.setTexture(buttonBuiltFull_1);

	textMusic3.setFont(font);
	textMusic2.setFont(font);
	textMusic1.setFont(font);
	textLayout.setFont(font);

	textMusic1.setString("Interstellar main theme");
	textMusic2.setString("Green grass - Earthlings :-D");
	textMusic3.setString("We are the Champions - Queen");

	textLayout.setString("SPACE - acceleration \n\
B(pressed) - tracking \n\
B - move camera to rocket \n\
Z - clockwise rotation \n\
X - counterclockwise rotation \n\
mouse wheel - scrolling \n\
mouse 1 - move camera");

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

	xBgCat = menuBackgroundCat.getSize().x;
	yBgCat = menuBackgroundCat.getSize().y;
	xBgSpace = menuBackgroundSpace.getSize().x;
	yBgSpace = menuBackgroundSpace.getSize().y;
	xBgSpace2 = menuBackgroundSpace2.getSize().x;
	yBgSpace2 = menuBackgroundSpace2.getSize().y;

	xBag = buttonBackground.getTextureRect().width;
	yBag = buttonBackground.getTextureRect().height;
	xMu = buttonMusic.getTextureRect().width;
	yMu = buttonMusic.getTextureRect().height;
	xBack = buttonBack.getTextureRect().width;
	yBack = buttonBack.getTextureRect().height;
	xLa = buttonLayout.getTextureRect().width;
	yLa = buttonLayout.getTextureRect().height;

	texRAir.loadFromFile("image/module3.png");
	texREmpty.loadFromFile("image/module2.png");
	sprRAir.setTexture(texRAir);
	sprREmpty.setTexture(texREmpty);
	rAir = sprRAir.getTextureRect();
	rEmpty = sprREmpty.getTextureRect();
	butBuild = buttonBuilt.getTextureRect();
	finalBounds = finalMeme.getGlobalBounds();
	finalDiedBounds = finalDied.getGlobalBounds();
	finalWinBounds = finalWin.getGlobalBounds();
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

void drawAll::drawLeftInter(sf::RenderWindow& window, sf::View view, spaceShip ship, float distance) {
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
    textMass.setString(to_string(ship.getMass()));
    textMass.setFont(font);
	textMass.setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
	textMass.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * 0.57f);
	window.draw(textMass);
	for (int i = 0; i < vLText.size(); i++) {
		vLText[i].setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
		vLText[i].setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * (0.15f + i * 0.12f));
		window.draw(vLText[i]);
	}
	textDistance.setString(to_string(distance));
	textDistance.setFont(font);
	textDistance.setScale(vSize_x * 4.f / xLeftInter, vSize_y * 3.f / yLeftInter);
	textDistance.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + vSize_y * 0.7f);
	window.draw(textDistance);
}

void drawAll::drawTextAboutAll(sf::RenderWindow& window, sf::View view, spaceShip ship, vector<Planet> planets) {
	float vSize_x = 0.15f * view.getSize().x;
	float vSize_y = 0.8f * view.getSize().y;
	float xRightInter = sprRightInter.getLocalBounds().width;
	float yRightInter = sprRightInter.getLocalBounds().height;
	float shapeBounds = view.getSize().x * 0.06f;
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
	shapeEmptyPlanet.setRadius(shapeBounds);
	shapeEmptyPlanet.setPosition(view.getCenter().x + view.getSize().x * 0.36f, view.getCenter().y - view.getSize().y * 0.38f);
	shapeRocket.setRadius(shapeBounds);
	shapeRocket.setPosition(view.getCenter().x + view.getSize().x * 0.36f, view.getCenter().y - view.getSize().y * 0.38f);
	shapeNotEmptyPlanet.setRadius(shapeBounds);
	shapeNotEmptyPlanet.setPosition(view.getCenter().x + view.getSize().x * 0.36f, view.getCenter().y - view.getSize().y * 0.38f);
	shapeSpace.setRadius(shapeBounds);
	shapeSpace.setPosition(view.getCenter().x + view.getSize().x * 0.36f, view.getCenter().y - view.getSize().y * 0.38f);
	textSpace.setFont(font);
	textSpace.setScale(vSize_x * 1.88f / xRightInter, vSize_y * 2.f / yRightInter);
	textSpace.setPosition(view.getCenter().x + view.getSize().x * 0.355f, view.getCenter().y + view.getSize().y * 0.08f);
	int trig = 1;
	int trig2 = 1;
	for (auto& c : ship.getSprite()) {
		if (c.getGlobalBounds().contains(pos.x, pos.y)) {
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
			window.draw(shapeRocket);
			trig = 0;
		}
	}

	if (trig != 0) {
		for (auto& c : planets) {
			if (c.getSprite().getGlobalBounds().contains(pos.x, pos.y) && !planets[0].getSprite().getGlobalBounds().contains(pos.x, pos.y)) {
				textSpace.setString(\
					"And this is another planet. There is no \n\
life on it, nor is there a desire to \n\
approach it. Radiation, rocks, and sand. \n\
Well, better to stay on the ship. No, I`m \n\
serious, it`s gonna kill you. Of \n\
course, right now, dear player, you want \n\
to visit this planet. Why listen to the \n\
man who made this game? And don`t tell \n\
me I didn`t warn you.");
				window.draw(shapeEmptyPlanet);
				trig2 = 0;
			}
		}
		if (trig2 != 0) {
			if (planets[0].getSprite().getGlobalBounds().contains(pos.x, pos.y)) {
				textSpace.setString(\
					"And this is already a populated planet. \n\
According to our data, which is certainly \n\
confirmed, this race has spaceships. \n\
They also live in three-dimensional \n\
space. Our captain said we need to get \n\
to this planet. I don`t know why, maybe \n\
he wants to feed them cookies. Or can \n\
colonize, he likes to do it, not for \n\
nothing he targets for days instead of \n\
running the ship, playing civilization");
				textSpace.setPosition(view.getCenter().x + view.getSize().x * 0.355f, view.getCenter().y + view.getSize().y * 0.05f);
				window.draw(shapeNotEmptyPlanet);
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
				window.draw(shapeSpace);
			}
		}
		
	}
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
	sprFuelPanel.setScale(vSize_x * ship.FUEL()/ (xFuel * ship.getMaxFuel()), vSize_y / yFuel);
	sprFuelPanel.setPosition(view.getCenter().x - view.getSize().x * 0.086f, view.getCenter().y - view.getSize().y * 0.481f);
	window.draw(sprFuelPanel);
	sprAirPanel.setScale(vSize_x * ship.AIR()/ (xFuel * ship.getMaxAir()), vSize_y / yFuel);
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

sf::Sprite drawAll::getSpriteMenuBackground(sf::RenderWindow& window, sf::Texture texture) {
	menuBg.setTexture(texture);
	menuBg.setScale(window.getSize().x / xBg, window.getSize().y / yBg);
	return menuBg;
}

sf::Sprite drawAll::getSpriteBackgroundCat(sf::RenderWindow& window) {
	menuBgCat.setScale(window.getSize().x / (7.5f * xBgCat), window.getSize().y / (7.5f * yBgCat));
	menuBgCat.setPosition(window.getSize().x * 0.7f - (menuBgCat.getGlobalBounds().width / 5.0f), window.getSize().y * 0.4f);
	return menuBgCat;
}

sf::Sprite drawAll::getSpriteBackgroundSpace(sf::RenderWindow& window) {
	menuBgSpace.setScale(window.getSize().x / (7.5f * xBgSpace), window.getSize().y / (7.5f * yBgSpace));
	menuBgSpace.setPosition(window.getSize().x * 0.7f - (menuBgSpace.getGlobalBounds().width / 5.0f), window.getSize().y * 0.6f);
	return menuBgSpace;
}

sf::Sprite drawAll::getSpriteBackgroundSpace2(sf::RenderWindow& window) {
	menuBgSpace2.setScale(window.getSize().x / (7.50f * xBgSpace2), window.getSize().y / (7.50f * yBgSpace2));
	menuBgSpace2.setPosition(window.getSize().x * 0.85f - (menuBgSpace2.getGlobalBounds().width / 7.50f), window.getSize().y * 0.4f);
	return menuBgSpace2;
}

sf::Sprite drawAll::getSpriteBackgroundMain(sf::RenderWindow& window) {
	menuBgMain.setScale(window.getSize().x / (7.5f * xBg), window.getSize().y / (7.5f * yBg));
	menuBgMain.setPosition(window.getSize().x * 0.85f - (menuBgMain.getGlobalBounds().width / 7.50f), window.getSize().y * 0.6f);
	return menuBgMain;
}

sf::Sprite drawAll::getSpriteAbout(sf::RenderWindow& window) {
	aboutTexture.setScale(window.getSize().x / (18.0f * xAb), window.getSize().x / (yAb * 18.0f));
	aboutTexture.setPosition(window.getSize().x * 0.97f - (xAb / 10.0f), window.getSize().y * 0.92f - (xAb / 10.0f));
	return aboutTexture;
}

sf::Sprite drawAll::getSpriteAboutWithMouse(sf::RenderWindow& window) {
	aboutTextureWithMouse.setScale(window.getSize().x / (18.0f * xAb), window.getSize().x / (yAb * 18.0f));
	aboutTextureWithMouse.setPosition(window.getSize().x * 0.97f - (xAb / 10.0f), window.getSize().y * 0.92f - (xAb / 10.0f));
	return aboutTextureWithMouse;
}

//Спрайты для настроек
sf::Sprite drawAll::getSpriteBackWithMouse(sf::RenderWindow& window) {
	buttonBackWithMouse.setScale(window.getSize().x / (18.0f * xAb), window.getSize().x / (yAb * 18.0f));
	buttonBackWithMouse.setPosition(window.getSize().x * 0.05f - (xBack / 10.0f), window.getSize().y * 0.92f - (xBack / 10.0f));
	return buttonBackWithMouse;
}

sf::Sprite drawAll::getSpriteBack(sf::RenderWindow& window) {
	buttonBack.setScale(window.getSize().x / (18.0f * xAb), window.getSize().x / (yAb * 18.0f));
	buttonBack.setPosition(window.getSize().x * 0.05f - (xBack / 10.0f), window.getSize().y * 0.92f - (xBack / 10.0f));
	return buttonBack;
}


sf::Sprite drawAll::getSpriteMusic(sf::RenderWindow& window) {
	buttonMusic.setScale(window.getSize().x / (10.0f * xMu), window.getSize().y / (yMu * 13.0f));
	buttonMusic.setPosition(window.getSize().x * 0.2f - (xMu / 10.0f), window.getSize().y * 0.3f);
	return buttonMusic;
}

sf::Sprite drawAll::getSpriteBackground(sf::RenderWindow& window) {
	buttonBackground.setScale(window.getSize().x / (10.0f * xBag), window.getSize().y / (yBag * 13.0f));
	buttonBackground.setPosition(window.getSize().x * 0.8f - (xBag / 10.0f), window.getSize().y * 0.3f);
	return buttonBackground;
}

sf::Sprite drawAll::getSpriteLayout(sf::RenderWindow& window) {
	buttonLayout.setScale(window.getSize().x / (10.0f * xLa), window.getSize().y / (yLa * 13.0f));
	buttonLayout.setPosition(window.getSize().x * 0.5f - (xLa / 10.0f), window.getSize().y * 0.3f);
	return buttonLayout;
}



sf::Text drawAll::drawTextAbout(sf::RenderWindow& window) {
	float xText = textAbout.getGlobalBounds().width;
	float yText = textAbout.getGlobalBounds().height;
	textAbout.setPosition((window.getSize().x - xText) / 2, (window.getSize().y - yText) / 2.f);
	return textAbout;
}

sf::Text drawAll::drawTextMusic1(sf::RenderWindow& window) {
	textMusic1.setFont(font);
	textMusic1.setPosition(window.getSize().x * 0.1f, window.getSize().y * 0.4f);
	return textMusic1;
}

sf::Text drawAll::drawTextMusic2(sf::RenderWindow& window) {
	textMusic2.setFont(font);
	textMusic2.setPosition(window.getSize().x * 0.1f, window.getSize().y * 0.5f);
	return textMusic2;
}

sf::Text drawAll::drawTextMusic3(sf::RenderWindow& window) {
	textMusic3.setFont(font);
	textMusic3.setPosition(window.getSize().x * 0.1f, window.getSize().y * 0.6f);
	return textMusic3;
}

sf::Text drawAll::drawTextLayout(sf::RenderWindow& window) {
	float xText = textLayout.getGlobalBounds().width;
	float yText = textLayout.getGlobalBounds().height;
	textLayout.setFont(font);
	textLayout.setPosition(window.getSize().x * 0.4f, window.getSize().y * 0.4f);
	return textLayout;
}

//Спрайт для BuildRocket
sf::Sprite drawAll::getSpritePlay(sf::RenderWindow& window) {
	buttonPlay.setScale(window.getSize().x / (18.0f * xAb), window.getSize().x / (yAb * 18.0f));
	buttonPlay.setPosition(window.getSize().x * 0.97f - (xAb / 10.0f), window.getSize().y * 0.92f - (xAb / 10.0f));
	return buttonPlay;
}

sf::Sprite drawAll::getSpritePlayWithMouse(sf::RenderWindow& window) {
	buttonPlayWithMouse.setScale(window.getSize().x / (18.0f * xAb), window.getSize().x / (yAb * 18.0f));
	buttonPlayWithMouse.setPosition(window.getSize().x * 0.97f - (xAb / 10.0f), window.getSize().y * 0.92f - (xAb / 10.0f));
	return buttonPlayWithMouse;
}

sf::Sprite drawAll::getSpriteBuilt(sf::RenderWindow& window) {
	buttonBuilt.setScale(window.getSize().x / (12.0f * butBuild.width), window.getSize().x / (butBuild.height * 18.0f));
	buttonBuilt.setPosition(0.75f * window.getSize().x, window.getSize().y * 0.92f - (xAb / 10.0f));
	return buttonBuilt;
}

sf::Sprite drawAll::getSpriteBuiltWithMouse(sf::RenderWindow& window) {
	buttonBuiltWithMouse.setScale(window.getSize().x / (12.0f * butBuild.width), window.getSize().x / (butBuild.height * 18.0f));
	buttonBuiltWithMouse.setPosition(0.75f * window.getSize().x, window.getSize().y * 0.92f - (xAb / 10.0f));
	return buttonBuiltWithMouse;
}

void drawAll::getSpriteFinal(sf::RenderWindow& window, sf::View view) {
	finalMeme.setScale(view.getSize().x / finalBounds.width, view.getSize().y / finalBounds.height);
	finalMeme.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
	window.draw(finalMeme);
}

sf::Sprite drawAll::getSpriteRAir(sf::RenderWindow& window) {
	sprRAir.setScale(window.getSize().x * 0.12f / rAir.width, window.getSize().y * 0.15f / rAir.height);
	sprRAir.setPosition(window.getSize().x * 0.78f, window.getSize().y * 0.25f - rAir.height / 2);
	return sprRAir;
}

sf::Sprite drawAll::getSpriteREmpty(sf::RenderWindow& window) {
	sprREmpty.setScale(window.getSize().x * 0.12f / rEmpty.width, window.getSize().y * 0.15f / rEmpty.height);
	sprREmpty.setPosition(window.getSize().x * 0.79f, window.getSize().y * 0.75f - rEmpty.height / 2);
	return sprREmpty;
}

void drawAll::getSpriteFinalDied(sf::RenderWindow& window, sf::View view) {
	finalDied.setScale(view.getSize().x / finalDiedBounds.width, view.getSize().y / finalDiedBounds.height * 0.2f);
	finalDied.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y * 0.9f);
	window.draw(finalDied);
}

void drawAll::getSpriteFinalWin(sf::RenderWindow& window, sf::View view) {
	finalWin.setScale(view.getSize().x / finalWinBounds.width, view.getSize().y / finalWinBounds.height);
	finalWin.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
	window.draw(finalWin);
}
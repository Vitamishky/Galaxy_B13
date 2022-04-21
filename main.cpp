#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "cmath"
#include "startMenu.h"
#include "optionsMenu.h"
#include "buildRocket.h"
#include "sounds.h"
#include "aboutMenu.h"
void runUdpClient(unsigned short port);

int main()
{
    std::cout << "Press enter to exit..." << std::endl;
    parametrizationScreen* screen = new parametrizationScreen;

    //РћС‚СЂРёСЃРѕРІРєР° РѕРєРЅР°
    sf::RenderWindow window(sf::VideoMode(screen->getParametrizationScreen().first,
        screen->getParametrizationScreen().second), "Galaxy B13", sf::Style::Close);

    camera* Camera = new camera(window);
    //Работа с музыкой
    sounds bgMusic {"sounds/bgMusic1.wav", 80, 15};
    sounds engineSound {"sounds/soundOfEngine.wav", 0};
    sounds turnerSound {"sounds/soundOfTurner.wav", 0};
    bgMusic.play(true);
    engineSound.play(true);
    turnerSound.play(true);

    startMenu menu;
    optionsMenu options;
    aboutMenu* about = new aboutMenu;
    drawAll* drawObjects = new drawAll;
    buildRocket buildrocket;

    window.setFramerateLimit(30);

    window.setVerticalSyncEnabled(true);

    //Отрисовка иконки
    drawObjects->drawIcon(window);

    //Создание планет на карте
    vector<Planet> planets;
    srand(time(nullptr));
    std::string str = "image/planet1.png";
    for (int i = 0; i < 8; ++i) {
        float tempX;
        float tempY;
        float r;
        bool b = true;
        while (b) {
            int temp = 0;
            tempX = (float) ((rand() % 800000) * pow(-1, rand() / 23));
            tempY = (float) ((rand() % 800000) * pow(-1, rand() / 23));
            r = rand() % 6000 + 2000;
            for (int j = 0; j < i; j++) {
                if (sqrtf((planets[j].getCoordinates().first - tempX) * (planets[j].getCoordinates().first - tempX)
                + (planets[j].getCoordinates().second - tempY) * (planets[j].getCoordinates().second - tempY))
                > 3 * (planets[j].getRadius() + r))
                    temp++;
            }
            if (temp == i)
                b = false;
        }
        Planet planet1{tempX, tempY, (float) (rand() % 255 * 10000), r, str};
        planets.push_back(planet1);
    }
    //РЎРѕР·РґР°РЅРёРµ РєРѕСЃРјРёС‡РµСЃРєРѕРіРѕ РєРѕСЂР°Р±Р»СЏ
    MODULE m1("image/cabine.png", 5, 120, 120, true);
    MODULE m2("image/module2.png",10, 120, 130);
    MODULE m3("image/module3.png",5, 120, 130, false, true, 1000, 1000);
    MODULE m4("image/module4.png",10, 130, 120, false, false, 0, 0, true, 10000, 1000);
    vector<MODULE> masivMODULE = { m2, m4, m2, m2, m3, m1 };
    spaceShip spaceship = spaceShip(masivMODULE, 800, 150);

    //Р Р°Р±РѕС‚Р° СЃ РєР°РјРµСЂРѕР№ СЃР»РµР¶РµРЅРёСЏ

    Camera->resetView(window);

    sf::Clock sf_clock;

    string nameMenu = "main";

    while (nameMenu != "go" && nameMenu != "exit") {
        if (nameMenu == "main") {
            nameMenu = menu.drawStartMenu(window);
            window.clear();
        }
        if (nameMenu == "start") {
            nameMenu = buildrocket.drawBuildRocket(window);
            //if (nameMenu == "back") {
                //menu.drawStartMenu(window);
            //}
            //else
                //nameMenu = "go";
        }
        if (nameMenu == "options") {
            nameMenu = options.drawOptionsMenu(window);
        }
        if (nameMenu == "about") {
            window.clear();
            nameMenu = about->drawAboutMenu(window);
        }
    }
    if (nameMenu != "exit") {
        while (window.isOpen()) {

            sf::Event event{};

            float dt = sf_clock.restart().asSeconds();

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed ||
                    event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }

                if (event.type == sf::Event::MouseMoved) {
                    Camera->moveCamera(float(event.mouseMove.x), float(event.mouseMove.y));
                }

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    Camera->lockedCamera(float(event.mouseButton.x), float(event.mouseButton.y));
                }

                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                    Camera->unlockCamera();
                }

                if (event.type == sf::Event::KeyReleased || spaceship.FUEL() == 0) {
                    if (event.key.code == sf::Keyboard::Space) {
                        engineSound.setVolume(0);
                    }
                }

                if (event.type == sf::Event::KeyReleased || spaceship.AIR() == 0) {
                    if (event.key.code == sf::Keyboard::Z) {
                        turnerSound.setVolume(0);
                    }
                }
                if (event.type == sf::Event::KeyReleased || spaceship.AIR() == 0) {
                    if (event.key.code == sf::Keyboard::X) {
                        turnerSound.setVolume(0);
                    }
                }

                if (event.type == sf::Event::MouseWheelScrolled) {
                    Camera->zoomCamera(event, window);
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                    Camera->backFromShip(window, spaceship);
                }
            }

            drawObjects->drawBg(window, Camera->getViewCamera());
            window.setView(Camera->getViewCamera());

            spaceship.draw(window);
            //Отрисовка планет
            spaceship.draw(window);
            for (auto& i : planets)
                i.drawSprite(window);

            spaceship.control(engineSound, turnerSound);
            spaceship.move(dt, planets);

            drawObjects->drawLeftInter(window, Camera->getViewCamera(), spaceship);
            drawObjects->drawRightInter(window, Camera->getViewCamera());
            drawObjects->drawFuel(window, Camera->getViewCamera(), spaceship);
            drawObjects->drawCompas(window, Camera->getViewCamera(), spaceship);
            drawObjects->drawArrow(window, Camera->getViewCamera());
            drawObjects->drawTextAboutAll(window, Camera->getViewCamera(), spaceship);

            window.display();

            window.clear();
        }
    }

    delete drawObjects;
    delete Camera;
    delete screen;
    delete about;

    return EXIT_SUCCESS;
}
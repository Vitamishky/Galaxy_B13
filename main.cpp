#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "cmath"
#include "startMenu.h"
#include "optionsMenu.h"
#include "buildRocket.h"
#include "aboutMenu.h"

int main()
{
    //Работа с музыкой
    sf::Music* bgMusic = new sf::Music;
    bgMusic->openFromFile("sounds/bgMusic.wav");
    bgMusic->setPlayingOffset(sf::seconds(10));
    bgMusic->setVolume(25);
    bgMusic->play();
    bgMusic->setLoop(true);
    sf::Music* engineSound = new sf::Music;
    engineSound->openFromFile("sounds/soundOfEngine.wav");
    engineSound->setVolume(0);
    engineSound->play();
    engineSound->setLoop(true);
    sf::Music* turnerSound = new sf::Music;
    turnerSound->openFromFile("sounds/soundOfTurner.wav");
    turnerSound->setVolume(0);
    turnerSound->play();
    turnerSound->setLoop(true);


    parametrizationScreen* screen = new parametrizationScreen;
    //Отрисовка окна
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(screen->getParametrizationScreen().first,
        screen->getParametrizationScreen().second), "Galaxy B13", sf::Style::Close);

    camera* Camera = new camera(*window);

    startMenu menu;
    optionsMenu options;
    aboutMenu* about = new aboutMenu;
    drawAll* drawObjects = new drawAll;
    buildRocket buildrocket;

    window->setFramerateLimit(100);

    window->setVerticalSyncEnabled(true);

    //Отрисовка иконки
    drawObjects->drawIcon(*window);

    //Создание космического корабля
    MODULE m1("image/cabine.png", 5, 120, 120, true);
    MODULE m2("image/module2.png",10, 120, 130);
    MODULE m3("image/module3.png",5, 120, 130, false, true, 1000, 1000);
    MODULE m4("image/module4.png",10, 130, 120, false, false, 0, 0, true, 1000, 1000);
    vector<MODULE> masivMODULE;

    //Создание планет на карте
    vector<Planet> planets;
    for (int i = 0; i < 8; ++i) {
        Planet planet1 {(float)((rand() % 80000) * pow(-1, rand() / 23)), (float)((rand() % 80000) * pow(-1, rand() / 23)),
                              (float)(rand() % 255 * 10000), 3000.f};
        planets.push_back(planet1);
    }
    //Работа с камерой слежения

    Camera->resetView(*window);

    sf::Clock sf_clock;

    string nameMenu = "main";
    std::pair<string, std::vector<int>> para;

    while (nameMenu != "go" && nameMenu != "exit") {
        if (nameMenu == "main") {
            nameMenu = menu.drawStartMenu(*window);
            window->clear();
        }
        if (nameMenu == "start") {
            para = buildrocket.drawBuildRocket(*window);
            nameMenu = para.first;
            //if (nameMenu == "back") {
                //menu.drawStartMenu(window);
            //}
            //else
                //nameMenu = "go";
        }
        if (nameMenu == "options") {
            nameMenu = options.drawOptionsMenu(*window);
        }
        if (nameMenu == "about") {
            window->clear();
            nameMenu = about->drawAboutMenu(*window);
        }
    }

    for (auto& c : para.second) {
        if (c == 2) {
            masivMODULE.push_back(m2);
        }
        if (c == 3) {
            masivMODULE.push_back(m3);
        }
        if (c == 4) {
            masivMODULE.push_back(m4);
        }
    }
    masivMODULE.push_back(m1);
    spaceShip spaceship = spaceShip(masivMODULE, 800, 150);

    if (nameMenu != "exit") {
        while (window->isOpen()) {

            sf::Event event{};

            float dt = sf_clock.restart().asSeconds();

            while (window->pollEvent(event)) {

                if (event.type == sf::Event::Closed ||
                    event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    window->close();
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

            if (event.type == sf::Event::MouseWheelScrolled) {
                Camera->zoomCamera(event, *window);
            }
            if (event.type == sf::Event::KeyReleased || spaceship.FUEL() == 0) {
                if (event.key.code == sf::Keyboard::Space) {
                    engineSound->setVolume(0);
                 }
            }

            if (event.type == sf::Event::KeyReleased || spaceship.AIR() == 0) {
                if (event.key.code == sf::Keyboard::Z) {
                    turnerSound->setVolume(0);
                }
            }
            if (event.type == sf::Event::KeyReleased || spaceship.AIR() == 0) {
                if (event.key.code == sf::Keyboard::X) {
                    turnerSound->setVolume(0);
                }
            }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                    Camera->backFromShip(*window, spaceship);
                }
            }

        drawObjects->drawBg(*window, Camera->getViewCamera());
        window->setView(Camera->getViewCamera());
        //Отрисовка планет
        spaceship.draw(*window);
        for (auto& i : planets)
            i.drawSprite(*window);

        drawObjects->drawLeftInter(*window, Camera->getViewCamera(), spaceship);
        drawObjects->drawRightInter(*window, Camera->getViewCamera());
        drawObjects->drawFuel(*window, Camera->getViewCamera(), spaceship);
        drawObjects->drawCompas(*window, Camera->getViewCamera(), spaceship);
        drawObjects->drawArrow(*window, Camera->getViewCamera());
        drawObjects->drawTextAboutAll(*window, Camera->getViewCamera(), spaceship);
        spaceship.control(engineSound, turnerSound);
        spaceship.move(dt, planets);

        window->display();

        window->clear();
        }
    }

    delete drawObjects;
    delete Camera;
    delete screen;
    delete about;
    delete bgMusic;
    delete engineSound;
    delete turnerSound;
    delete window;

    return EXIT_SUCCESS;
}
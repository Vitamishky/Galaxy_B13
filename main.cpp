﻿#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "drawAll.h"
#include "startMenu.h"
#include "optionsMenu.h"
#include "buildRocket.h"
#include "aboutMenu.h"
#include "functions.h"

void runUdpClient(unsigned short port);

int main()
{
    sf::IpAddress server;
    std::cout << "Enter server IP: ";
    std::cin >> server;

    std::string client_name;
    std::cout << std::endl << "Enter you name: ";
    std::cin >> client_name;
    parametrizationScreen* screen = new parametrizationScreen;

    //Отрисовка окна
    sf::RenderWindow window(sf::VideoMode(screen->getParametrizationScreen().first,
        screen->getParametrizationScreen().second), "Galaxy B13", sf::Style::Close);

    camera* Camera = new camera(window);

    startMenu menu;
    optionsMenu options;
    aboutMenu* about = new aboutMenu;
    drawAll* drawObjects = new drawAll;

    window.setFramerateLimit(30);

    window.setVerticalSyncEnabled(true);

    //Отрисовка иконки
    drawObjects->drawIcon(window);

    //Создание космического корабля
    MODULE m1("image/cabine.png", 5, 120, 120, true);
    MODULE m2("image/module2.png",10, 120, 130);
    MODULE m3("image/module3.png",5, 120, 130, false, true, 1000, 1000);
    MODULE m4("image/module4.png",10, 130, 120, false, false, 0, 0, true, 10000, 1000);
    vector<MODULE> masivMODULE = { m2, m4, m2, m2, m3, m1 };
    spaceShip spaceship = spaceShip(masivMODULE, 800, 150);

    //Работа с камерой слежения

    Camera->resetView(window);

    sf::Clock sf_clock;

    string nameMenu = "main";

    while (nameMenu != "go" && nameMenu != "exit") {
        if (nameMenu == "main") {
            nameMenu = menu.drawStartMenu(window);
            window.clear();
        }
        if (nameMenu == "start") {
            //nameMenu = buildrocket.drawBuildRocket(window);
            if (nameMenu == "back") {
                //menu.drawStartMenu(window);
            }
            //else
                //nameMenu = "go";
        }
        if (nameMenu == "options") {
            //nameMenu = options.drawOptionsMenu(window);
        }
        if (nameMenu == "about") {
            window.clear();
            nameMenu = about->drawAboutMenu(window);
        }
    }
    if (nameMenu != "exit") {
        for(int q = 1;window.isOpen(); ++q) {

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

            spaceship.control();
            spaceship.move(dt);
            if(q == 20) {
                functions::runUdpClient(window, server, client_name, spaceship);
                q = 0;
            }
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
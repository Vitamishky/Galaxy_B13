#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "drawAll.h"
#include "startMenu.h"
#include "optionsMenu.h"
#include "buildRocket.h"
#include "aboutMenu.h"
void runUdpClient(unsigned short port);

int main()
{
    std::cout << "Press enter to exit..." << std::endl;
    parametrizationScreen* screen = new parametrizationScreen;

    //Отрисовка окна
    sf::RenderWindow window(sf::VideoMode(screen->getParametrizationScreen().first,
        screen->getParametrizationScreen().second), "Galaxy B13", sf::Style::Close);

    camera* Camera = new camera(window);

    startMenu menu;
    optionsMenu options;
    aboutMenu* about = new aboutMenu;
    drawAll* drawObjects = new drawAll;
    buildRocket buildrocket;

    window.setFramerateLimit(30);

    window.setVerticalSyncEnabled(true);

    //Отрисовка иконки
    drawObjects->drawIcon(window);

    //Создание космического корабля
    MODULE m1("image/cabine.png", 5, 120, 120, true);
    MODULE m2("image/module2.png",10, 120, 130);
    MODULE m3("image/module3.png",5, 120, 130, false, true, 1000, 1000);
    MODULE m4("image/module4.png",10, 130, 120, false, false, 0, 0, true, 10000, 1000);
    vector<MODULE> masivMODULE;

    //Работа с камерой слежения

    Camera->resetView(window);

    sf::Clock sf_clock;

    string nameMenu = "main";
    std::pair<string, std::vector<int>> para;

    while (nameMenu != "go" && nameMenu != "exit") {
        if (nameMenu == "main") {
            nameMenu = menu.drawStartMenu(window);
            window.clear();
        }
        if (nameMenu == "start") {
            para = buildrocket.drawBuildRocket(window);
            nameMenu = para.first;
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

    for (auto& c : para.second) {
        if (c == 1) {
            masivMODULE.push_back(m1);
        }
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

    spaceShip spaceship = spaceShip(masivMODULE, 800, 150);

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
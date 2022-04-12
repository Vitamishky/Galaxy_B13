#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "drawAll.h"
#include "startMenu.h"

int main()
{
    parametrizationScreen *screen = new parametrizationScreen;
    
    //Отрисовка окна
    sf::RenderWindow window(sf::VideoMode(screen->getParametrizationScreen().first, 
                                          screen->getParametrizationScreen().second), "Galaxy B13", sf::Style::Close);
    
    camera *Camera = new camera(window);

    startMenu *menu = new startMenu();
    drawAll *drawObjects = new drawAll;
    
    window.setFramerateLimit(30);

    window.setVerticalSyncEnabled(true);

    //Отрисовка иконки
    drawObjects->drawIcon(window);

    //Создание космического корабля
    MODULE m1(20, 120, 120, true);
    MODULE m2(1, 120, 130, false, true, 1000, 1000);
    MODULE m3(10, 130, 120, false, false, 0, 0, true, 1000, 1000);
    MODULE m4(100, 120, 130);
    vector<MODULE> masivMODULE = {m1, m2, m3, m4};
    spaceShip spaceship = spaceShip(masivMODULE);

    //Работа с камерой слежения
    
    Camera->resetView(window);

    sf::Clock sf_clock;

    //menu->drawStartMenu(window);

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

        }

        drawObjects->drawBg(window, Camera->getViewCamera());
        window.setView(Camera->getViewCamera());

        spaceship.draw(window);

        spaceship.control();
        spaceship.move(dt);

        //spaceship->drawSprite(window);

        drawObjects->drawLeftInter(window, Camera->getViewCamera(), spaceship);
        drawObjects->drawRightInter(window, Camera->getViewCamera());
        drawObjects->drawFuel(window, Camera->getViewCamera(), spaceship);
        drawObjects->drawCompas(window, Camera->getViewCamera());
        drawObjects->drawArrow(window, Camera->getViewCamera());

        window.display();

        window.clear();
    }

    delete drawObjects;
    delete Camera;
    delete menu;

    return EXIT_SUCCESS;
}
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
    spaceShip *spaceship = new spaceShip;

    //Работа с камерой слежения
    
    Camera->resetView(window);

    sf::Clock sf_clock;

    //menu->drawStartMenu(window);

    while (window.isOpen()) {

        sf::Event event;

        float dt = sf_clock.restart().asSeconds();

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                spaceship->move(dt, 'l');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                spaceship->move(dt, 'r');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                spaceship->move(dt, 'u');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                spaceship->move(dt, 'd');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (event.type == sf::Event::MouseMoved) {
                Camera->moveCamera(event.mouseMove.x, event.mouseMove.y);
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                Camera->lockedCamera(event.mouseButton.x, event.mouseButton.y);
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

        spaceship->drawSprite(window);

        drawObjects->drawLeftInter(window, Camera->getViewCamera());
        drawObjects->drawRightInter(window, Camera->getViewCamera());
        drawObjects->drawFuel(window, Camera->getViewCamera());
        drawObjects->drawCompas(window, Camera->getViewCamera());
        drawObjects->drawArrow(window, Camera->getViewCamera());

        window.display();

        window.clear();
    }

    delete spaceship;
    delete drawObjects;
    delete Camera;
    delete menu;

    return EXIT_SUCCESS;
}
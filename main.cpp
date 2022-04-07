#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "drawAll.h"
#include "startMenu.h"

int main()
{
    drawAll drawObjects;
    parametrizationScreen screen;
    //Отрисовка окна
    sf::RenderWindow window(sf::VideoMode(screen.getParametrizationScreen().first, 
                                          screen.getParametrizationScreen().second), "Galaxy-B03", sf::Style::Close);
    
    startMenu menu;

    window.setFramerateLimit(30);

    window.setVerticalSyncEnabled(true);

    //Отрисовка иконки
    drawObjects.drawIcon(window);

    //Создание космического корабля
    spaceShip spaceship;

    //Работа с камерой слежения
    camera camera(window);
    camera.resetView(window);

    sf::Clock sf_clock;

    menu.drawStartMenu(window);

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
                spaceship.move(dt, 'l');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                spaceship.move(dt, 'r');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                spaceship.move(dt, 'u');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                spaceship.move(dt, 'd');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (event.type == sf::Event::MouseMoved) {
                camera.moveCamera(event.mouseMove.x, event.mouseMove.y);
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                camera.lockedCamera(event.mouseButton.x, event.mouseButton.y);
            }
            
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                camera.unlockCamera();
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                camera.zoomCamera(event, window);
            }
        }

        drawObjects.drawBg(window, camera.getViewCamera());

        window.setView(camera.getViewCamera());

        spaceship.drawSprite(window);

        drawObjects.drawLeftInter(window, camera.getViewCamera());
        drawObjects.drawRightInter(window, camera.getViewCamera());
        drawObjects.drawFuel(window, camera.getViewCamera());
        drawObjects.drawCompas(window, camera.getViewCamera());

        window.display();

        window.clear();
    }

    return EXIT_SUCCESS;
}
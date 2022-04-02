#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"

int main()
{
    parametrizationScreen screen;
    //Отрисовка окна
    sf::RenderWindow window(sf::VideoMode(screen.getParametrizationScreen().first, 
                                          screen.getParametrizationScreen().second), "Galaxy-B03", sf::Style::Close);
    
    window.setFramerateLimit(30);
    window.setVerticalSyncEnabled(true);

    //Отрисовка иконки около названия окна
    sf::Image icon;
    if (!icon.loadFromFile("image/spaceShip.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Отрисовка заднего фона
    sf::Texture textureBg;
    if (!textureBg.loadFromFile("image/bg.png")) {
        return EXIT_FAILURE;
    }
    float xBg = float(textureBg.getSize().x);
    float yBg = float(textureBg.getSize().y);
    sf::Sprite backWall(textureBg); 
    backWall.setScale(float(window.getSize().x) / xBg, float(window.getSize().y) / yBg);
    //Создание космического корабля
    MODULE m1, m2, m3, m4;
    vector<MODULE> masivMODULE = {m1,m2,m3,m4};
    spaceShip spaceship(masivMODULE);

    //Работа с камерой слежения
    camera camera(window);
    camera.resetView(window);

    sf::Clock sf_clock;

    while (window.isOpen()) {

        sf::Event event{};

        float dt = sf_clock.restart().asSeconds();

        while (window.pollEvent(event)) {
            spaceship.move(dt);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved) {
                camera.moveCamera(float(event.mouseMove.x), float(event.mouseMove.y));
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                camera.lockedCamera(float(event.mouseButton.x), float(event.mouseButton.y));
            }
            
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                camera.unlockCamera();
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                camera.zoomCamera(event, window);
            }

            spaceship.move(dt);
            spaceship.draw(window);
        }

        window.draw(backWall);

        window.setView(camera.getViewCamera());

        window.display();

        window.clear();
    }

    return EXIT_SUCCESS;
}
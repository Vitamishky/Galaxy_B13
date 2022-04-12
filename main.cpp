#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "cmath"
#include "startMenu.h"
#include "drawAll.h"
#include "spaceObjects.h"

int main()
{
    parametrizationScreen screen;
    //Отрисовка окна
    sf::RenderWindow window(sf::VideoMode(screen.getParametrizationScreen().first, 
                                          screen.getParametrizationScreen().second), "Galaxy-B03", sf::Style::Close);

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

    //Отрисовка заднего фона
    sf::Texture textureBg;
    if (!textureBg.loadFromFile("image/bg.png")) {
        return EXIT_FAILURE;
    }
    float xBg = float(textureBg.getSize().x);
    float yBg = float(textureBg.getSize().y);
    sf::Sprite backWall(textureBg);
    backWall.setScale(float(window.getSize().x) / xBg, float(window.getSize().y) / yBg);
    //Создание планет на карте
    vector<Planet> planets;
    for (int i = 0; i < 8; ++i) {
        Planet planet1 {(float)((rand() % 80000) * pow(-1, rand() / 23)), (float)((rand() % 80000) * pow(-1, rand() / 23)),
                              (float)(rand() % 255 * 10000), 3000.f};
        planets.push_back(planet1);
    }
    //Работа с камерой слежения
    Camera->resetView(window);

    sf::Clock sf_clock;

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

        window.draw(backWall);
        //Отрисовка планет
        spaceship.draw(window);
        for (auto& i : planets)
            i.drawSprite(window);

        spaceship.control();
        spaceship.move(dt, planets);

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
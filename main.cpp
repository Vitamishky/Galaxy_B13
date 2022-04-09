#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "drawAll.h"

int main()
{
    drawAll drawObjects;
    parametrizationScreen screen;
    //��������� ����
    sf::RenderWindow window(sf::VideoMode(screen.getParametrizationScreen().first, 
                                          screen.getParametrizationScreen().second), "Galaxy-B03", sf::Style::Close);
    
    window.setFramerateLimit(30);
    window.setVerticalSyncEnabled(true);

    //��������� ������
    drawObjects.drawIcon(window);

    //�������� ������������ �������
    vector<MODULE> masivMODULE;
    spaceShip spaceship(masivMODULE);

    //������ � ������� ��������
    camera camera(window);
    camera.resetView(window);

    sf::Clock sf_clock;

    while (window.isOpen()) {

        sf::Event event;

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

        drawObjects.drawBg(window);

        window.setView(camera.getViewCamera());

        spaceship.drawSprite(window);

        window.display();

        window.clear();
    }

    return EXIT_SUCCESS;
}
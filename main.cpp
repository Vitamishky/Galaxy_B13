#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "camera.h"
#include "cmath"
#include "startMenu.h"
#include "optionsMenu.h"
#include "buildRocket.h"
#include "aboutMenu.h"
#include "sounds.h"

int main()
{
    sf::Texture tex4, tex1, tex2, tex3;
    vector<sf::Texture> texV;
    tex4.loadFromFile("image/background.jpg");
    texV.push_back(tex4);
    tex1.loadFromFile("image/backgroundSpace.jpg");
    texV.push_back(tex1);
    tex2.loadFromFile("image/backgroundSpace2.jpg");
    texV.push_back(tex2);
    tex3.loadFromFile("image/backgroundCat.jpg");
    texV.push_back(tex3);
    float targetDistance;
    bool reved = true;
    //Работа с музыкой
    sounds bgMusic {"sounds/bgMusic1.wav", 80, 15};
    sounds engineSound {"sounds/soundOfEngine.wav", 0};
    sounds turnerSound {"sounds/soundOfTurner.wav", 0};
    bgMusic.play(true);
    engineSound.play(true);
    turnerSound.play(true);


    parametrizationScreen* screen = new parametrizationScreen;
    //Отрисовка окна
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(screen->getParametrizationScreen().first,
        screen->getParametrizationScreen().second), "Galaxy B13", sf::Style::Close);

    camera* Camera = new camera(*window);

    startMenu* menu = new startMenu;
    optionsMenu* options = new optionsMenu;
    aboutMenu* about = new aboutMenu;
    drawAll* drawObjects = new drawAll;
    buildRocket* buildrocket = new buildRocket;

    window->setFramerateLimit(30);

    window->setVerticalSyncEnabled(true);

    //Отрисовка иконки
    drawObjects->drawIcon(*window);

    //Создание космического корабля
    MODULE m1("image/cabine.png", 2, 120, 120, true);
    MODULE m2("image/module2.png", 10, 120, 130);
    MODULE m3("image/module3.png", 2, 120, 130, false, true, 1000, 1000);
    MODULE m4("image/module4.png", 4, 130, 120, false, false, 0, 0, true, 1000, 1000);
    vector<MODULE> masivMODULE;

    //Создание планет на карте
    vector<Planet> *planets = new vector<Planet>;
    vector<sf::CircleShape> sprPlanet;
    srand(time(nullptr));
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
                if (sqrtf(((*planets)[j].getCenter().first - tempX) * ((*planets)[j].getCenter().first - tempX)
                          + ((*planets)[j].getCenter().second - tempY) * ((*planets)[j].getCenter().second - tempY))
                    > 3 * ((*planets)[j].getRadius() + r))
                    temp++;
            }
            if (temp == i)
                b = false;
        }
        Planet* planet1 = new Planet{tempX, tempY, (float) (rand() % 255 * 10000), r, rand() % 10};
        sprPlanet.push_back(planet1->getSprite());
        planets->push_back(*planet1);
    }
    float max = 0;
    int maxInd = -1;
    for (int i = 0; i < (*planets).size(); i++) {
        if (sqrtf((*planets)[i].getCenter().first * (*planets)[i].getCenter().first
        + (*planets)[i].getCenter().second * (*planets)[i].getCenter().second) > max) {
            max = sqrtf((*planets)[i].getCenter().first * (*planets)[i].getCenter().first
                        + (*planets)[i].getCenter().second * (*planets)[i].getCenter().second);
            maxInd = i;
        }
    }
    std::swap((*planets)[maxInd], (*planets)[0]);
    //Работа с камерой слежения

    Camera->resetView(*window);

    sf::Clock sf_clock;
    //Переключение меню
    string nameMenu = "main";
    std::pair<string, std::vector<int>> para;
    std::pair<string, vector<int>> para1 = { "back", {0, 0, 5} };
    while (nameMenu != "go" && nameMenu != "exit") {
        if (nameMenu == "main") {
            nameMenu = menu->drawStartMenu(*window, texV[para1.second[0]]);
            window->clear();
        }
        if (nameMenu == "start") {
            para = buildrocket->drawBuildRocket(*window);
            window->setFramerateLimit(30);
            nameMenu = para.first;
            window->clear();
        }
        if (nameMenu == "options") {
            para1 = options->drawOptionsMenu(*window, texV[para1.second[0]]);
            nameMenu = para1.first;
            //
            window->clear();
        }
        if (nameMenu == "about") {
            nameMenu = about->drawAboutMenu(*window, texV[para1.second[0]]);
            window->clear();
        }
    }
//
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
    spaceShip* spaceship = new spaceShip(masivMODULE, 800, 150);

    if (nameMenu != "exit") {
        while (window->isOpen()) {
            sf::Event event{};

            float dt = sf_clock.restart().asSeconds();

            while (window->pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
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
                if (event.type == sf::Event::KeyReleased || spaceship->FUEL() == 0) {
                    if (event.key.code == sf::Keyboard::Space) {
                        engineSound.setVolume(0);
                    }
                }
                if (event.type == sf::Event::KeyReleased || spaceship->AIR() == 0) {
                    if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::X) {
                        turnerSound.setVolume(0);
                    }
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                    Camera->backFromShip(*window, *spaceship);
                }
            }
            targetDistance = sqrt((spaceship->getCoordinates().first - planets[0][0].getCenter().first) * (spaceship->getCoordinates().first - planets[0][0].getCenter().first) + 
                (spaceship->getCoordinates().second - planets[0][0].getCenter().second) * (spaceship->getCoordinates().second - planets[0][0].getCenter().second));
            drawObjects->drawBg(*window, Camera->getViewCamera());
            window->setView(Camera->getViewCamera());
            //Отрисовка планет
            for (auto& i : *planets) {
                i.drawSprite(*window);
            }
            for (int i = 0; i < spaceship->getSprite().size(); i++) {
                for (int j = 0; j < sprPlanet.size(); j++) {
                    if (spaceship->getSprite()[i].getGlobalBounds().intersects(sprPlanet[j].getGlobalBounds())) {
                        reved = false;
                    }
                }
            }
            if (reved) {
                spaceship->draw(*window);
                spaceship->control(engineSound, turnerSound);
                spaceship->move(dt, *planets);
            }
            else {
                for (int i = 0; i < 100; i++) {
                    drawObjects->getSpriteFinal(*window, Camera->getViewCamera());
                    drawObjects->getSpriteFinalDied(*window, Camera->getViewCamera());
                    window->display();
                    window->clear();
                }
                window->close();
            }
            if (targetDistance < planets[0][0].getRadius() * 1.4f) {
                for (int i = 0; i < 100; i++) {
                    drawObjects->getSpriteFinalWin(*window, Camera->getViewCamera());
                    window->display();
                    window->clear();
                }
                window->close();
            }
            drawObjects->drawLeftInter(*window, Camera->getViewCamera(), *spaceship, targetDistance);
            drawObjects->drawRightInter(*window, Camera->getViewCamera());
            drawObjects->drawFuel(*window, Camera->getViewCamera(), *spaceship);
            drawObjects->drawCompas(*window, Camera->getViewCamera(), *spaceship);
            drawObjects->drawArrow(*window, Camera->getViewCamera());
            drawObjects->drawTextAboutAll(*window, Camera->getViewCamera(), *spaceship, *planets);

            window->display();

            window->clear();
        }

    }
    delete drawObjects;
    delete Camera;
    delete screen;
    delete about;
    delete window;
    delete options;
    delete menu;
    return EXIT_SUCCESS;
}
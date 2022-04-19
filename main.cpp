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
    sf::Texture tex, tex1, tex2, tex3;
    vector<sf::Texture> texV;
    tex.loadFromFile("image/background.jpg");
    texV.push_back(tex);
    tex1.loadFromFile("image/backgroundSpace.jpg");
    texV.push_back(tex1);
    tex2.loadFromFile("image/backgroundSpace2.jpg");
    texV.push_back(tex2);
    tex3.loadFromFile("image/backgroundCat.jpg");
    texV.push_back(tex3);

    bool reved = true;
    //Работа с музыкой
    sf::Music* bgMusic = new sf::Music;
    bgMusic->openFromFile("sounds/bgMusic.wav");
    bgMusic->setPlayingOffset(sf::seconds(10));
    bgMusic->setVolume(100);
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
    MODULE m1("image/cabine.png", 5, 120, 120, true);
    MODULE m2("image/module2.png",10, 120, 130);
    MODULE m3("image/module3.png",5, 120, 130, false, true, 1000, 1000);
    MODULE m4("image/module4.png",10, 130, 120, false, false, 0, 0, true, 10000, 10000);
    vector<MODULE> masivMODULE;

    //Создание планет на карте
    vector<Planet> *planets = new vector<Planet>;
    vector<sf::CircleShape> sprPlanet;
    for (int i = 0; i < 8; ++i) {
        Planet* planet1 = new Planet{(float)((rand() % 80000) * pow(-1, rand() / 23)), (float)((rand() % 80000) * pow(-1, rand() / 23)),
                              (float)(rand() % 255 * 10000), 3000.f};
        sprPlanet.push_back(planet1->getSprite());
        planets->push_back(*planet1);
    }
    //Работа с камерой слежения

    Camera->resetView(*window);

    sf::Clock sf_clock;

    string nameMenu = "main";
    std::pair<string, std::vector<int>> para;

    std::pair<string, vector<int>> para1 = { "back", {0, 0, 5} };

    while (nameMenu != "go" && nameMenu != "exit") {

        //para1 = menu.drawStartMenu(window, texV[para1.second[0]]);


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
            window->clear();
        }
        if (nameMenu == "about") {
            nameMenu = about->drawAboutMenu(*window, texV[para1.second[0]]);
            window->clear();
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
            nameMenu = about->drawAboutMenu(*window, texV[para1.second[0]]);
            window->clear();
        }
    }
    masivMODULE.push_back(m1);
    spaceShip* spaceship = new spaceShip(masivMODULE, 800, 150);

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
            if (event.type == sf::Event::KeyReleased || spaceship->FUEL() == 0) {
                if (event.key.code == sf::Keyboard::Space) {
                    engineSound->setVolume(0);
                 }
            }

            if (event.type == sf::Event::KeyReleased || spaceship->AIR() == 0) {
                if (event.key.code == sf::Keyboard::Z) {
                    turnerSound->setVolume(0);
                }
            }
            if (event.type == sf::Event::KeyReleased || spaceship->AIR() == 0) {
                if (event.key.code == sf::Keyboard::X) {
                    turnerSound->setVolume(0);
                }
            }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                    Camera->backFromShip(*window, *spaceship);
                }
            }
        
            
        drawObjects->drawBg(*window, Camera->getViewCamera());
        window->setView(Camera->getViewCamera());
        //Отрисовка планет
        
        for (auto& i : *planets)
            i.drawSprite(*window);
        spaceship->getSprite();
        
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
        drawObjects->drawLeftInter(*window, Camera->getViewCamera(), *spaceship);
        drawObjects->drawRightInter(*window, Camera->getViewCamera());
        drawObjects->drawFuel(*window, Camera->getViewCamera(), *spaceship);
        drawObjects->drawCompas(*window, Camera->getViewCamera(), *spaceship);
        drawObjects->drawArrow(*window, Camera->getViewCamera());
        drawObjects->drawTextAboutAll(*window, Camera->getViewCamera(), *spaceship);
        

        window->display();

        window->clear();
        }
        delete drawObjects;
        delete Camera;
        delete screen;
        delete about;
        delete bgMusic;
        delete engineSound;
        delete turnerSound;
        delete window;
        delete options;
        delete menu;
        delete planets;
    }
    return EXIT_SUCCESS;
}
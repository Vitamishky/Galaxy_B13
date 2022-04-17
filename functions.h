#ifndef GALAXY_B03_FUNCTIONS_H
#define GALAXY_B03_FUNCTIONS_H
#include <iostream>
#include "spaceObjects.h"
#include "spaceShip.h"
#include <SFML/Network.hpp>

using namespace std;

struct ServerModule {
    string image;
    float forward_potForce,side_potForce, Masse, fuel, air;
    bool IsController, IsTurner, IsEngine;
    __int16 width, hight;
};

struct ServerPlayer{
    float x, y, angel;
    unsigned short senderPort;
    std::string client_name;
    std::vector<ServerModule> modules;
};

struct ClientModule {
    string image;
    __int16 width, hight;
};

struct ClientPlayer{
    float x, y, angel;
    std::string client_name;
    std::vector<ClientModule> modules;
//    float Masse, fuel, air; Надо добавить
};

class functions {
public:
    static pair<unsigned int, unsigned int> attraction(const spaceObjects& Slave, const spaceObjects& Master) ;
    static void mainUdpClient(sf::IpAddress server, std::string, spaceShip,
                             vector<ClientPlayer>&, unsigned short port = 50001);
    static void loopUdpClient(sf::RenderWindow& window, sf::IpAddress server, std::string, spaceShip,
                              vector<ClientPlayer>&, unsigned short port = 50001);
    void runUdpServer(unsigned short port);
};

#endif //GALAXY_B03_FUNCTIONS_H
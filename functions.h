#ifndef GALAXY_B03_FUNCTIONS_H
#define GALAXY_B03_FUNCTIONS_H
#include <iostream>
#include "spaceObjects.h"
#include "spaceShip.h"
#include <SFML/Network.hpp>

using namespace std;

struct ServerPlayer{
    std::string client_name;
    spaceShip* ship;
    unsigned short senderPort;
};

class functions {
public:
    static pair<unsigned int, unsigned int> attraction(const spaceObjects& Slave, const spaceObjects& Master) ;
    static void mainUdpClient(sf::IpAddress server, std::string, spaceShip,
                              std::map<string, spaceShip*> ClientBase, unsigned short port = 50001);
    static void loopUdpClient(sf::RenderWindow& window, sf::IpAddress server,
                              std::map <string, spaceShip*>, unsigned short port = 50001);
    static void mainUdpServer(int, unsigned short port, std::string client_name, spaceShip ship, std::map <sf::IpAddress, ServerPlayer> ServerBase);
    static void loopUdpServer(unsigned short port, std::map <sf::IpAddress, ServerPlayer>& ServerBase);
};

#endif //GALAXY_B03_FUNCTIONS_H
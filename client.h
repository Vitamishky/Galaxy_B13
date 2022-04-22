//
// Created by user on 19.04.2022.
//

#ifndef GALAXY_B13_CLIENT_H
#define GALAXY_B13_CLIENT_H
#include <iostream>
#include "spaceShip.h"
#include <SFML/Network.hpp>
struct ClientModule {
    std::string image;
    sf::Uint8 width, hight;
};

struct ClientPlayer{
    float x, y, angle;
    std::vector<ClientModule> modules;
    pair<float, float> velocity;
    float Masse, fuel, air;
};


class client {
public:
    static void initializeClient(sf::UdpSocket &socket, sf::IpAddress server, const std::string& name, spaceShip &ship,
                                 std::map <string, ClientPlayer> &ClientBase, unsigned short port = 50001);

    static void loopClient(sf::UdpSocket &socket, sf::RenderWindow &window, sf::IpAddress server, spaceShip &ship, const string& client_name,
                           std::map <string, ClientPlayer> &ClientBase, unsigned short port=50001);

};


#endif //GALAXY_B13_CLIENT_H
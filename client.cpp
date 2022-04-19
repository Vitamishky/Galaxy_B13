//
// Created by user on 19.04.2022.
//

#include "client.h"
sf::UdpSocket socket;


void client::initializeClient(sf::IpAddress server, const string& client_name, spaceShip ship,
                              std::map <string, ClientPlayer> &ClientBase, unsigned short port){
    sf::Packet packet;
    packet << 'i';
    packet << client_name << ship.getCoordinates().first << ship.getCoordinates().second
           << ship.ANGLE() << ship.getAmountOfModules();
    for (auto &module: ship.rocket) {
        packet << module.getPlaceOfImage() << module.getParametrization().first <<
        module.getParametrization().second <<module.getMasse() << module.IsController
        << module.IsTurner << module.Side_PotForce() << module.getAir() << module.IsEngine <<
        module.Forward_PotForce() << module.getFuel();
    }
    socket.send(packet, server, port);

    packet.clear();
    spaceObjects s;
    sf::Uint8 n, n1;
    string name;
    if (socket.receive(packet, server, port) == sf::Socket::Done) {
        packet >> n;
        for (int j = 0; j < n; j++) {
            packet >> name >> ClientBase[name].x >> ClientBase[name].y
            >> ClientBase[name].angle >> n1;
            vector<ClientModule> modules;
            for (int i = 0; i < n1; ++i) {
                ClientModule M;
                packet >> M.image >> M.width >> M.hight;
                modules.push_back(M);
            }
            ClientBase[name].modules = modules;
        }
    }
}
void client::loopClient(sf::RenderWindow &window, sf::IpAddress server,
                        map <string, ClientPlayer>& ClientBase, unsigned short port) {
    sf::Packet packet;

    packet << 'd';
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::X),
            right = sf::Keyboard::isKeyPressed(sf::Keyboard::Z),
            forward = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    packet << left << right << forward;
    socket.send(packet, server, port);

    packet.clear();
    float x, y, angle;
    std::string client_name;
    if (socket.receive(packet, server, port) == sf::Socket::Done) {
        packet >> client_name >> ClientBase[client_name].x >> ClientBase[client_name].y
               >> ClientBase[client_name].angle;
    }

    for (auto &player: ClientBase) {
        vector<MODULE> modules;
        for (auto &module: player.second.modules) {
            MODULE m(module.image, module.hight, module.width);
            modules.push_back(m);
        }
        spaceShip ship(modules, player.second.x, player.second.y, player.second.angle);
        ship.draw(window);
    }
}
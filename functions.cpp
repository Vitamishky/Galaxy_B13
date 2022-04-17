#include "functions.h"
#include <cmath>
#include "spaceObjects.h"


const float G = 1;

pair<unsigned int, unsigned int> functions::attraction(const spaceObjects& Slave, const spaceObjects& Master)
/**
 * @param Slave:  То что получает ускорение
 * @param Master:  То к чеу притягивается тело
 * @return ускорение по x и по y
 */
{
    pair<unsigned int, unsigned int> length = make_pair(abs(Slave.getCoordinates().first - Master.getCoordinates().first), abs(Slave.getCoordinates().second - Master.getCoordinates().second));
    float distances = sqrtf(length.first * length.first + length.second * length.second);
    float a = float(G * Master.getMasse() / (distances * distances));
    return make_pair(a * length.first / distances,a * length.second / distances);
}

void functions::mainUdpClient(sf::IpAddress server, std::string client_name, spaceShip ship,
                              std::map<string, spaceShip*> ClientBase, unsigned short port) {
    sf::UdpSocket socket;
    sf::Packet packet;

    packet << client_name << ship.getCoordinates().first << ship.getCoordinates().second
           << ship.ANGLE() << ship.getAmountOfModules();
    for (int i = 0; i < ship.getAmountOfModules(); ++i) {
        packet << ship.rocket[i].getPlaceOfImage() << ship.rocket[i].Forward_PotForce() <<
               ship.rocket[i].Side_PotForce() << ship.rocket[i].getMasse() << ship.rocket[i].getFuel()
               << ship.rocket[i].getAir();
    }
    socket.send(packet, server, port);

    packet.clear();
    std::string name;
    float n;
    float x, y, angel;
    string image;
    float width, hight;
    spaceObjects s;
    if (socket.receive(packet, server, port) == sf::Socket::Done) {

        packet >> n;
        for (int j = 0; j < n; j++) {
            float n1;
            packet >> name >> x >> y >> angel >> n1;
            vector<MODULE> modules;
            for (int i = 0; i < n1; ++i) {
                packet >> image >> width >> hight;
                MODULE M(image, width, hight);
                modules.push_back(M);
            }

            spaceShip ship1(modules, x, y, angel);
            ClientBase[name] = &ship1;
        }
    }
}
void functions::loopUdpClient(sf::RenderWindow &window, sf::IpAddress server,
                              std::map <string, spaceShip*> ClientBase, unsigned short port) {
    sf::UdpSocket socket;
    sf::Packet packet;

    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::X),
            right = sf::Keyboard::isKeyPressed(sf::Keyboard::Z),
            forward = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    packet << left << right << forward;
    socket.send(packet, server, port);

    packet.clear();
    float x, y, angle;
    std::string client_name;
    if(socket.receive(packet, server, port) == sf::Socket::Done) {
        for(int i = 0; i < ClientBase.size(); ++i) {
            packet >> client_name >> x >> y >> angle;

            ClientBase[client_name]->newCoordinate(x, y, angle);
        }

    }

}

void functions::mainUdpServer(unsigned short port, std::map <sf::IpAddress, ServerPlayer> ServerBase) {
    sf::UdpSocket socket;
    std::string client_name;
    // Listen to messages on the specified port
    if (socket.bind(port) != sf::Socket::Done)
        return;
    std::cout << "Server is listening to port " << port << ", waiting for a message... " << std::endl;

    float angel, x, y;

    sf::IpAddress sender;
    unsigned short senderPort;
    sf::Packet response;
    std::string image;
    float forward_potForce, side_potForce, Masse, fuel, air;
    bool IsController, IsTurner, IsEngine;
    float width, hight, n;

    if (socket.receive(response, sender, senderPort) == sf::Socket::Done) {
        response >> client_name >> x >> y >> angel >> n;
        std::vector <MODULE> modules;
        for (int i = 0; i < n; ++i) {
            response >> image >> forward_potForce >> side_potForce >> Masse >> fuel >> air;
            MODULE module(image, int(width), int(hight), Masse, IsController, IsTurner, side_potForce,
                          air, IsEngine, forward_potForce, fuel);
            modules.push_back(module);
        }
        spaceShip ship(modules, x, y, angel);
        ServerBase[sender] = {client_name, &ship, senderPort};

    }
    n = ServerBase.size();
    sf::Packet allPackets;
    allPackets << n;
    for (auto &p: ServerBase) {
        float n1 = p.second.ship->rocket.size();
        allPackets << p.second.client_name << p.second.ship->getCoordinates().first << p.second.ship->getCoordinates().second << p.second.ship->ANGLE() <<
                   n1;
        for (auto &m : p.second.ship->rocket) {
            allPackets << m.getPlaceOfImage() << m.getParametrization().first << m.getParametrization().second;
        }
    }
    for (auto &g: ServerBase) {
        if (socket.send(allPackets, g.first, g.second.senderPort) == sf::Socket::Done) {

        }
    }
}

void functions::loopUdpServer(unsigned short port, std::map <sf::IpAddress, ServerPlayer>& ServerBase){
    sf::UdpSocket socket;
    sf::IpAddress sender;
    unsigned short senderPort;
    sf::Packet packet;
    bool left, right, forward;
    for(int i = 0; i < ServerBase.size(); ++i) {
        if (socket.receive(packet, sender, senderPort) == sf::Socket::Done) {
            packet >> left >> right >> forward;
            bool crutch = false;
            float dfuel = 100000;
            float dair = 1000;
            for (auto &module: ServerBase[sender].ship->rocket) {
                if (module.IsController) crutch = true;
            }
            if (crutch) {
                for (auto &module: ServerBase[sender].ship->rocket) {
                    if (forward && module.IsEngine &&
                        ServerBase[sender].ship->Use_Fuel(module.Forward_PotForce() / dfuel)) {
                        module.EditAcceleration(make_pair(
                                module.Forward_PotForce() * sin(ServerBase[sender].ship->ANGLE()) / module.getMasse(),
                                module.Forward_PotForce() * cos(ServerBase[sender].ship->ANGLE()) / module.getMasse()));
                    }
                    if (left && module.IsTurner && ServerBase[sender].ship->Use_Air(module.Side_PotForce() / dair)) {
                        module.EditAcceleration(make_pair(
                                module.Side_PotForce() * cos(ServerBase[sender].ship->ANGLE()) / module.getMasse(),
                                -module.Side_PotForce() * sin(ServerBase[sender].ship->ANGLE()) / module.getMasse()));
                    }
                    if (right && module.IsTurner && ServerBase[sender].ship->Use_Air(module.Side_PotForce() / dair)) {
                        module.EditAcceleration(make_pair(
                                -module.Side_PotForce() * cos(ServerBase[sender].ship->ANGLE()) / module.getMasse(),
                                module.Side_PotForce() * sin(ServerBase[sender].ship->ANGLE()) / module.getMasse()));
                    }
                }
            }


        }

    }
    float dt = 0.0005;
    for(auto & k : ServerBase) {
        k.second.ship->move(dt);
    }
    packet.clear();
    packet << ServerBase[sender].client_name << ServerBase[sender].ship->getCoordinates().first <<
    ServerBase[sender].ship->getCoordinates().second << ServerBase[sender].ship->ANGLE();
    for(int i = 0; i < ServerBase.size(); ++i) {
        if (socket.send(packet, sender, senderPort) == sf::Socket::Done) {

        }
    }
}

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

void functions::mainUdpClient(sf::IpAddress server, std::string client_name, spaceShip ship, vector<ClientPlayer>& base, unsigned short port) {
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
            vector<ClientModule> modules;
            for (int i = 0; i < n1; ++i) {
                packet >> image >> width >> hight;
                modules.push_back({image, width, hight});
            }
            base.push_back({x, y, angel, name, modules});
        }
    }
    for(auto& b : base) {
    }
}
void functions::loopUdpClient(sf::RenderWindow &window, sf::IpAddress server, std::string, spaceShip,
                              vector<ClientPlayer> & base, unsigned short port) {
    sf::UdpSocket socket;
    sf::Packet packet;

    packet.clear();
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::X),
            right = sf::Keyboard::isKeyPressed(sf::Keyboard::Z),
            forward = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    packet << left << right << forward;
    socket.send(packet, server, port);



}

bool functions::collision(spaceShip ship, Planet planet) {
    if((ship.getCoordinates().first-planet.getCoordinates().first)*(ship.getCoordinates().first-planet.getCoordinates().first)+
            (ship.getCoordinates().second-planet.getCoordinates().second)*(ship.getCoordinates().second-planet.getCoordinates().second)
            <= planet.getParametrization().first*planet.getParametrization().first/4)
    return false;
}
/*
void functions::runUdpServer(unsigned short port) {
    std::map <sf::IpAddress, Player> base;
    sf::UdpSocket socket;
    std::string client_name;
    // Listen to messages on the specified port
    if (socket.bind(port) != sf::Socket::Done)
        return;
    std::cout << "Server is listening to port " << port << ", waiting for a message... " << std::endl;
    socket.setBlocking(false);


    float cordCentreMass, angel, x, y;
    std::vector<Module> modules;


    for (float i = 0;; i += 0.05) {
        sf::IpAddress sender;
        unsigned short senderPort;
        sf::Packet response;

        base["123.34.23.345"] = {123 + i, 234, 45, 50002, "AZA", {{"photo_2022-03-09 01.42.06.jpeg", 30, 40}}, 15};
        if (socket.receive(response, sender, senderPort) == sf::Socket::Done) {
            response >> client_name >> x >> y >> angel >> cordCentreMass >> modules[0].image >> modules[0].width >> modules[0].hight;
            base[sender] = {x, y, angel, senderPort, client_name,  {{modules[0].image, modules[0].width, modules[0].hight}}, cordCentreMass};
        }
        float n = base.size();
        sf::Packet allPackets;
        for (auto &p: base) {
            allPackets << n << p.second.client_name << p.second.x << p.second.y << p.second.angel <<
                       p.second.cordCentreMass << p.second.modules[0].image << p.second.modules[0].width << p.second.modules[0].hight;
            std::cout << "Message received from client " << p.first << ": " << p.second.client_name << " " << p.second.x << " " << p.second.y
                      << std::endl;
        }
        std::cout << std::endl;
        for (auto &g: base) {
            if (socket.send(allPackets, g.first, g.second.senderPort) == sf::Socket::Done) {

            }
        }
    }
}*/
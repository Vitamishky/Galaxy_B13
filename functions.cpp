#include "functions.h"
#include <cmath>
#include <SFML/Network.hpp>
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

[[noreturn]] void runUdpClient(sf::RenderWindow& window, spaceShip ship, unsigned short port) {
    std::string client_name;
    sf::IpAddress server;

    std::cout << "Enter server IP: ";
    std::cin >> server;
    std::cout << std::endl << "Enter you name: ";
    std::cin >> client_name;


    sf::UdpSocket socket;


    sf::Packet packet1;
    packet1 << client_name << ship.getCoordinates().first << ship.getCoordinates().second
            << ship.ANGLE();
    socket.send(packet1, server, port);

    sf::Packet packet2;

    socket.receive(packet2, server, port);

    int n;
    packet2 >> n;

    for (int i = 0; i != n; ++i) {
        sf::Packet packet3;
        socket.receive(packet3, server, port);

        std::string name;
        float x, y, angel;

        packet2 >> name >> x >> y >> angel;

        spaceObjects s(x, y, angel);
        s.drawSprite(window);
    }
}
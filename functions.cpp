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

void functions::runUdpClient(sf::RenderWindow &window, sf::IpAddress server, std::string client_name, spaceShip ship, unsigned short port) {

    sf::UdpSocket socket;

    sf::Packet packet1;
    packet1 << client_name << ship.getCoordinates().first << ship.getCoordinates().second
            << ship.ANGLE();
    socket.send(packet1, server, port);

    sf::Packet packet2;

    socket.receive(packet2, server, port);

    int n;
    std::string name;
    float x, y, angel;
    sf::Packet packet3;
    for (int i = 0;; ++i) {
        socket.receive(packet3, server, port);

        packet3 >> n >> x >> y >> angel >> name;
        packet3.clear();

        if(name != client_name){
            spaceObjects s;
            s.setPosition(x,y,angel);
            s.drawSprite(window);
        }

        if(n <= i){
            break;
        }
    }
}
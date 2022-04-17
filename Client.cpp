#include <SFML/Network.hpp>
#include <iomanip>
#include <iostream>

void runUdpClient(unsigned short port)
{
    // Ask for the server address
    sf::IpAddress server;
    do
    {
        std::cout << "Address";
        std::cin  >> server;
    }
    while (server == sf::IpAddress::None);

    // Создадим сокет для связи с сервером
    sf::UdpSocket socket;

    // Отправим сообщение на сервер
    const char out[] = "Hi, I'm a client";
    if (socket.send(out, sizeof(out), server, port) != sf::Socket::Done)
        return;
    std::cout << "Message sent to the server: " << std::quoted(out) << std::endl;

    // Получить ответ от кого угодно (но скорее всего от сервера)
    char in[128];
    std::size_t received;
    sf::IpAddress sender;
    unsigned short senderPort;
    if (socket.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
        return;
    std::cout << "Message received from " << sender << ": " << std::quoted(in) << std::endl;
}
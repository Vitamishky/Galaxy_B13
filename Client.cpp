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

    // �������� ����� ��� ����� � ��������
    sf::UdpSocket socket;

    // �������� ��������� �� ������
    const char out[] = "Hi, I'm a client";
    if (socket.send(out, sizeof(out), server, port) != sf::Socket::Done)
        return;
    std::cout << "Message sent to the server: " << std::quoted(out) << std::endl;

    // �������� ����� �� ���� ������ (�� ������ ����� �� �������)
    char in[128];
    std::size_t received;
    sf::IpAddress sender;
    unsigned short senderPort;
    if (socket.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
        return;
    std::cout << "Message received from " << sender << ": " << std::quoted(in) << std::endl;
}
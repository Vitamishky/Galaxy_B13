//
// Created by user on 19.04.2022.
//

#include "client.h"

const sf::Uint8 typeInitCS = 1, typeTransferCS = 2, typeInitSC = 3, typeTransferSC = 4;

void client::initializeClient(sf::UdpSocket &socket, sf::IpAddress server, const string& client_name, spaceShip &ship,
                              std::map <string, ClientPlayer> &ClientBase, unsigned short port){
    sf::Packet packet;

    socket.bind(50002);
    packet << typeInitCS;
    sf::Uint8 AmountOfModules = ship.getAmountOfModules();
    packet << client_name << ship.getCoordinates().first << ship.getCoordinates().second
           << ship.ANGLE() << AmountOfModules;
    for (auto &module: ship.rocket) {
        sf::Uint8 width = module.getParametrization().first, height = module.getParametrization().second;
        packet << module.getPlaceOfImage() << width << height <<module.getMasse() << module.IsController
        << module.IsTurner << module.Side_PotForce() << module.getAir() << module.IsEngine <<
        module.Forward_PotForce() << module.getFuel();
    }
    if(socket.send(packet, server, port) != sf::Socket::Done){
        cout << "error_5"<< endl;
    }
}
void client::loopClient(sf::UdpSocket &socket, sf::RenderWindow &window, sf::IpAddress server, spaceShip &ourRocket, const string& OurName,
                        map <string, ClientPlayer>& ClientBase, unsigned short port) {

    socket.setBlocking(false);
    sf::Packet packet;

    std::string client_name;
    if (socket.receive(packet, server, port) == sf::Socket::Done) {
        cout << "<<" << endl;
        sf::Uint8 typeOfTransfer, SizeOfServerBase, n1;
        string name;
        packet >> typeOfTransfer;
        switch (typeOfTransfer) {
            case typeTransferSC:
                cout << "Prineal 1" << endl;
                packet >> SizeOfServerBase;
                for(int i=0; i < SizeOfServerBase; i++) {
                    packet >> client_name >> ClientBase[client_name].x >> ClientBase[client_name].y
                           >> ClientBase[client_name].angle >> ClientBase[client_name].velocity.first >> ClientBase[client_name].velocity.second;

                    for (auto &player: ClientBase) {
                        vector<MODULE> modules;
                        for (auto &module: player.second.modules) {
                            MODULE m(module.image, module.width, module.hight);
                            modules.push_back(m);
                        }
                        spaceShip ship(modules, player.second.x, player.second.y, player.second.angle);

                        if(client_name == OurName){
                            ourRocket.newRocket(ship);
                        }
                        ship.draw(window);
                    }
                }
                break;
            case typeInitSC: {
                cout << "Prineal 2";
                packet >> SizeOfServerBase;
                for (int j = 0; j < SizeOfServerBase; j++) {
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
                break;
            }
            default:
                cout << "Ne prineal";
                break;
        }

        packet.clear();

        bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::X),
                right = sf::Keyboard::isKeyPressed(sf::Keyboard::Z),
                forward = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        packet << typeTransferCS << left << right << forward;
        socket.send(packet, server, port);
    }
}
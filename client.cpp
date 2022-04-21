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
                        map <string, ClientPlayer>& ClientBase, sf::Event event, unsigned short port) {

    socket.setBlocking(false);
    sf::Packet packet;

    std::string client_name;
    if (socket.receive(packet, server, port) == sf::Socket::Done) {
        sf::Uint8 typeOfTransfer, SizeOfServerBase, n1;
        string name;
        packet >> typeOfTransfer;
        switch (typeOfTransfer) {
            case typeTransferSC:
                cout << "Prineal 1" << endl;
                packet >> SizeOfServerBase;
                for (int i = 0; i < int(SizeOfServerBase); i++) {
                    packet >> client_name >> ClientBase[client_name].x >> ClientBase[client_name].y
                           >> ClientBase[client_name].angle >> ClientBase[client_name].velocity.first
                           >> ClientBase[client_name].velocity.second >> ClientBase[client_name].angularVelocity
                           >> ClientBase[client_name].Masse >> ClientBase[client_name].fuel >> ClientBase[client_name].air;

                    for (auto &player: ClientBase) {
                        if(player.first != OurName)
                        {
                            vector<MODULE> modules;
                            for (auto &module: player.second.modules) {
                                MODULE m(module.image, module.width, module.hight, ClientBase[client_name].Masse/player.second.modules.size(),
                                         0,0,0,ClientBase[client_name].air/player.second.modules.size(),0,0,ClientBase[client_name].fuel/player.second.modules.size());
                                modules.push_back(m);
                            }
                            spaceShip ship(modules, player.second.x, player.second.y, player.second.angle);

                            if (client_name == OurName) {
                                ourRocket.newRocket(ship);
                            }
                            ship.draw(window);
                        }
                    }
                }
                break;
            case typeInitSC: {
                cout << "Prineal 2";
                packet >> SizeOfServerBase;
                cout << int(SizeOfServerBase);
                for (int j = 0; j < int(SizeOfServerBase); j++) {
                    packet >> name >> ClientBase[name].x >> ClientBase[name].y
                           >> ClientBase[name].angle >> n1;
                    vector<ClientModule> modules;
                    cout << n1;
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
        bool left = false, right = false, forward = false;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::X)
                left = true;
            if(event.type == sf::Event::KeyPressed &&
                     event.key.code == sf::Keyboard::Z)
                right = true;
            if (event.type == sf::Event::KeyPressed &&
                       event.key.code == sf::Keyboard::Space){
                forward = true;
            }
        }



        packet << typeTransferCS << left << right << forward;
        socket.send(packet, server, port);
    } else {
        for (auto &player: ClientBase) {
            if(player.first != OurName) {
                vector<MODULE> modules;
                for (auto &module: player.second.modules) {
                    MODULE m(module.image, module.width, module.hight);
                    modules.push_back(m);
                }
                spaceShip ship(modules, player.second.x, player.second.y, player.second.angle);

                ship.draw(window);
            }
        }
    }
}
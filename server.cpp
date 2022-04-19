#include <iostream>
#include "spaceShip.h"
#include <SFML/Network.hpp>
#include "cmath"

using namespace std;
struct ServerModule {
    string image;
    float forward_potForce,side_potForce, Masse, fuel, air;
    bool IsController, IsTurner, IsEngine;
    sf::Uint8 width, hight;
};
struct ServerPlayer{
    float x, y, angel;
    unsigned short senderPort;
    std::string client_name;
    std::vector<ServerModule> modules;
    // float Masse, fuel, air;
};
std::map <sf::IpAddress, ServerPlayer> ServerBase;

int main() {
    cout <<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    sf::UdpSocket socket;
    socket.setBlocking(false);
    for (;;) {
        std::string client_name;
        unsigned short port = 50001;
        // Listen to messages on the specified port
        if (socket.bind(port) != sf::Socket::Done) { return 0; }
        std::cout << "Server is listening to port: " << port << endl;

        sf::IpAddress sender;
        unsigned short senderPort;
        sf::Packet packet, allPackets;

        if (socket.receive(packet, sender, senderPort) == sf::Socket::Done) {

            //Ќећного объ€влений дл€ дольнейшей работы
            sf::Uint8 n, typeOfTransfer;

            packet >> typeOfTransfer;

            if (typeOfTransfer == 'i') { //»нициализаци€ игрока
                ServerBase[sender].senderPort = senderPort;
                packet >> ServerBase[sender].client_name >> ServerBase[sender].x >> ServerBase[sender].y >>
                       ServerBase[sender].angel >> n;
                vector<ServerModule> modules;
                for (int i = 0; i < n; ++i) {
                    ServerModule module;
                    packet >> module.image >> module.width >> module.hight >> module.Masse >>
                           module.IsController >> module.IsTurner >> module.side_potForce >> module.air >>
                           module.IsEngine >> module.forward_potForce >> module.fuel;
                    modules.push_back(module);
                }
                ServerBase[sender].modules = modules;

                allPackets << ServerBase.size();
                for (auto &p: ServerBase) { //передача данных о внешнем виде всех игроков всем игрокам
                    n = p.second.modules.size();
                    allPackets << p.second.client_name << p.second.x << p.second.y << p.second.angel <<
                               n;
                    for (auto &module: p.second.modules) {
                        allPackets << module.image << module.width << module.hight;
                    }
                }
            }
            if (typeOfTransfer == 'd') { //перемещение игрока
                bool left, right, forward;
                packet >> left >> right >> forward;
                bool crutch = false;
                float dfuel = 100000;
                float dair = 1000;

                for (auto &module: ServerBase[sender].modules) {
                    if (module.IsController) crutch = true;
                }

                vector<MODULE> modules;
                for (auto &module: ServerBase[sender].modules) {
                    MODULE m(module.image, module.hight, module.width, module.Masse, module.IsController,
                             module.IsTurner, module.side_potForce, module.air, module.IsEngine,
                             module.forward_potForce,
                             module.fuel);
                    modules.push_back(m);
                }
                spaceShip ship(modules, ServerBase[sender].x, ServerBase[sender].y, ServerBase[sender].angel);

                if (crutch) {
                    for (auto &module: ship.rocket) {
                        if (forward && module.IsEngine &&
                            ship.Use_Fuel(module.Forward_PotForce() / dfuel)) {
                            module.EditAcceleration(make_pair(
                                    module.Forward_PotForce() * sin(ship.ANGLE()) / module.getMasse(),
                                    module.Forward_PotForce() * cos(ship.ANGLE()) / module.getMasse()));
                        }
                        if (left && module.IsTurner && ship.Use_Air(module.Side_PotForce() / dair)) {
                            module.EditAcceleration(make_pair(
                                    module.Side_PotForce() * cos(ship.ANGLE()) / module.getMasse(),
                                    -module.Side_PotForce() * sin(ship.ANGLE()) / module.getMasse()));
                        }
                        if (right && module.IsTurner && ship.Use_Air(module.Side_PotForce() / dair)) {
                            module.EditAcceleration(make_pair(
                                    -module.Side_PotForce() * cos(ship.ANGLE()) / module.getMasse(),
                                    module.Side_PotForce() * sin(ship.ANGLE()) / module.getMasse()));
                        }
                    }

                }
                float dt = 0.0005;
                ship.move(dt);

                allPackets << ServerBase[sender].client_name << ServerBase[sender].x <<
                ServerBase[sender].y << ServerBase[sender].angel;
            }

            for (auto &g: ServerBase) {
                if (socket.send(allPackets, g.first, g.second.senderPort) != sf::Socket::Done) {
                    cout << "error";
                }
            }
        }
    }
}
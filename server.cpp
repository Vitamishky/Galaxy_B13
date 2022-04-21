#include <iostream>
#include "spaceShip.h"
#include <SFML/Network.hpp>
#include "cmath"

using namespace std;
struct ServerModule {
    string image = " ";
    float forward_potForce = 0,side_potForce = 0, Masse = 0, fuel = 0, air = 0;
    bool IsController = false, IsTurner= false, IsEngine = false;
    sf::Uint8 width = 0, hight = 0;
};
struct ServerPlayer{
    float x= 0, y = 0, angel = 0;
    std::string client_name = " ";
    std::vector<ServerModule> modules;
    pair<float, float> velocity = make_pair(0, 0);
    float angularVelocity = 0;
    float Masse, fuel, air;
};
std::map <sf::IpAddress, ServerPlayer> ServerBase;
unsigned short port = 50002;
unsigned short serverPort = 50001;
const float dt = 0.005;

int main() {
    sf::UdpSocket socket;
    socket.setBlocking(false);
    std::string client_name;
    cout << "Start" << endl;

    const sf::Uint8 typeInitCS = 1, typeTransferCS = 2, typeInitSC = 3, typeTransferSC = 4;
    // Listen to messages on the specified port
    if (socket.bind(serverPort) != sf::Socket::Done) { return 0; }
    for (;;) {
        sf::IpAddress sender;
        sf::Packet packet, allPackets;

        if (socket.receive(packet, sender, port) == sf::Socket::Done) {
            cout << "Prineal: ";
            //Ќећного объ€влений дл€ дальнейшей работы
            sf::Uint8 n, typeOfTransfer;

            packet >> typeOfTransfer;

            switch (typeOfTransfer) {
                case typeInitCS: { //»нициализаци€ игрока
                    cout << "initalizating";
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

                    allPackets << typeInitSC;
                    sf::Uint8 ServerSize = ServerBase.size();
                    allPackets << ServerSize;
                    for (auto &p: ServerBase) { //передача данных о внешнем виде всех игроков всем игрокам
                        n = p.second.modules.size();
                        allPackets << p.second.client_name << p.second.x << p.second.y << p.second.angel << n;
                        for (auto &module: p.second.modules) {
                            allPackets << module.image << module.width << module.hight;
                        }
                    }
                    break;
                }
                case typeTransferCS: { //перемещение игрока
                    cout << "move" << endl;
                    bool left, right, forward;
                    packet >> left >> right >> forward;
                    cout << left << right << forward << endl;
                    bool crutch = false;
                    float dfuel = 100000;
                    float dair = 1000;

                    for (auto &module: ServerBase[sender].modules) {
                        if (module.IsController) crutch = true;
                    }

                    for (auto &player: ServerBase) {
                        vector<MODULE> modules;
                        for (auto &module: ServerBase[sender].modules) {
                            MODULE m(module.image, module.width, module.hight, module.Masse, module.IsController,
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
                        ship.move(dt);
                        player.second.velocity = ship.getVelocity();
                        player.second.angularVelocity = ship.getAngularVelocity();
                        player.second.Masse = ship.getMass();
                        player.second.fuel = ship.FUEL();
                        player.second.air = ship.AIR();
                    }
                    sf::Uint8 SizeOfServerBase = ServerBase.size();
                    allPackets << typeTransferSC << SizeOfServerBase;
                    for (auto &player: ServerBase) {
                        allPackets << player.second.client_name << player.second.x << player.second.y
                                   << player.second.angel << player.second.velocity.first
                                   << player.second.velocity.second;
                    }
                    break;
                }
                default:
                    for (auto &player: ServerBase) {
                        vector<MODULE> modules;
                        for (auto &module: ServerBase[sender].modules) {
                            MODULE m(module.image, module.width, module.hight, module.Masse, module.IsController,
                                     module.IsTurner, module.side_potForce, module.air, module.IsEngine,
                                     module.forward_potForce,
                                     module.fuel);
                            modules.push_back(m);
                        }
                        spaceShip ship(modules, ServerBase[sender].x, ServerBase[sender].y, ServerBase[sender].angel);

                        ship.move(dt);
                        player.second.velocity = ship.getVelocity();
                        player.second.angularVelocity = ship.getAngularVelocity();
                        player.second.Masse = ship.getMass();
                        player.second.fuel = ship.FUEL();
                        player.second.air = ship.AIR();
                    }
                    sf::Uint8 SizeOfServerBase = ServerBase.size();
                    allPackets << typeTransferSC << SizeOfServerBase;
                    for (auto &player: ServerBase) {
                        allPackets << player.second.client_name << player.second.x << player.second.y
                                   << player.second.angel << player.second.velocity.first
                                   << player.second.velocity.second;
                    }
                    break;
            }
            sf::Uint8 SizeOfServerBase = ServerBase.size();
            allPackets << typeTransferSC << SizeOfServerBase;
            for (auto &player: ServerBase) {
                allPackets << player.second.client_name << player.second.x << player.second.y
                           << player.second.angel << player.second.velocity.first << player.second.velocity.second;
            }
            for (auto &g: ServerBase) {
                if (socket.send(allPackets, g.first, port) != sf::Socket::Done) {
                    cout << "error";
                }
            }
        }
    }
}
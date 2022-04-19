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
    unsigned short senderPort = 0;
    std::string client_name = " ";
    std::vector<ServerModule> modules;
    // float Masse, fuel, air;
};
std::map <sf::IpAddress, ServerPlayer> ServerBase;

int main() {
    sf::UdpSocket socket;
    socket.setBlocking(false);
    std::string client_name;
    unsigned short port = 50001;
    unsigned short senderPort;
    for (;;) {
        // Listen to messages on the specified port
        if (socket.bind(port) != sf::Socket::Done) { return 0; }

        sf::IpAddress sender;
        sf::Packet packet, allPackets;

        if (socket.receive(packet, sender, senderPort) == sf::Socket::Done) {

            //������� ���������� ��� ���������� ������
            sf::Uint8 n, typeOfTransfer;

            packet >> typeOfTransfer;

            if (typeOfTransfer == 'i') { //������������� ������
                ServerBase[sender].senderPort = senderPort;
                cout << "i";
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
                for (auto &p: ServerBase) { //�������� ������ � ������� ���� ���� ������� ���� �������
                    n = p.second.modules.size();
                    allPackets << p.second.client_name << p.second.x << p.second.y << p.second.angel <<
                               n;
                    for (auto &module: p.second.modules) {
                        allPackets << module.image << module.width << module.hight;
                    }
                }
                for (auto &g: ServerBase) {
                    if (socket.send(allPackets, g.first, g.second.senderPort) != sf::Socket::Done) {
                        cout << "error";
                    }
                }
            }
            if (typeOfTransfer == 'd') { //����������� ������
                cout << "d";
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
                float dt = 0.0005;
                ship.move(dt);

                allPackets << ServerBase[sender].client_name << ServerBase[sender].x <<
                ServerBase[sender].y << ServerBase[sender].angel;
                for (auto &g: ServerBase) {
                    if (socket.send(allPackets, g.first, g.second.senderPort) != sf::Socket::Done) {
                        cout << "error";
                    }
                }
            }

        }
    }
}
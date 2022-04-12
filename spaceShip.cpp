#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "cmath"


spaceShip::spaceShip(const vector<MODULE>& rocket):rocket(rocket) {
    float length = 0;
    for (const auto &i: rocket) {
        Mass += i.getMasse();
        cordCentreMass += i.getMasse() * (i.getParametrization().second / 2 + length);
        length += i.getParametrization().second;
    }
    length = 0;
    cordCentreMass /= Mass;
    for (const auto &i: rocket) {
        MomentOfInertia += (i.getMasse() * (i.getParametrization().second / 2 + length - cordCentreMass) *
                           (i.getParametrization().second / 2 + length - cordCentreMass))/3;
        length += i.getParametrization().second;


        x = y = 0.5f;
    }
}

void spaceShip::move(float dt) {
    float F_x = 0, F_y = 0;
    float dAngularVelocity = 0;
    for (const auto &modul: rocket) {
        F_x += modul.Acceleration().first * modul.getMasse();
        F_y += modul.Acceleration().second * modul.getMasse();


        float a_bokovoie = modul.Acceleration().first*cos(angle)-modul.Acceleration().second*sin(angle);

        float length = 0;
        dAngularVelocity += modul.getMasse() * a_bokovoie *
                (modul.getParametrization().second / 2 + length - cordCentreMass)*dt
                / MomentOfInertia;
        length += modul.getParametrization().second;
    }

    x += velocity.first * dt + F_x * dt * dt / (2 * Mass);
    y += velocity.second * dt + F_y * dt * dt / (2 * Mass);

    velocity.first += F_x * dt / Mass;
    velocity.second += F_y * dt / Mass;


    angularVelocity += dAngularVelocity;

    angle += angularVelocity * dt;

    float length = 0;
    //????????? ???? ???????
    for (auto &i: rocket) {
        i.newAngle(angle);
        i.NewCord(x + sin(angle) * (i.getParametrization().first / 2 + length - cordCentreMass),
                  y + cos(angle) * (i.getParametrization().first / 2 + length - cordCentreMass));
        length += i.getParametrization().first;
    }

    for (auto &modul: rocket) {
        modul.NewAcceleration(make_pair(0,0));

    }
}
//&& module.Use_Fuel(module.Forward_PotAcceleration() / dfuel
void spaceShip::control() {
    bool crutch = false;
    float dfuel = 100;
    float dair = 10000;
    for(auto & module : rocket) {
        if(module.IsController) crutch = true;
    }
    if (crutch) {
        for (auto &module: rocket) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && module.IsEngine && module.Use_Fuel(module.Forward_PotAcceleration() / dfuel)) {
                module.EditAcceleration(make_pair(module.Forward_PotAcceleration() * sin(angle), module.Forward_PotAcceleration() * cos(angle)));
                cout << module.getFuel() << endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && module.IsTurner && module.Use_Air(module.Side_PotAcceleration() / dair)) {
                module.EditAcceleration(make_pair(module.Side_PotAcceleration() * cos(angle), -module.Side_PotAcceleration() * sin(angle)));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && module.IsTurner && module.Use_Air(module.Side_PotAcceleration() / dair)) {
                module.EditAcceleration(make_pair(-module.Side_PotAcceleration() * cos(angle), module.Side_PotAcceleration() * sin(angle)));
            }
        }
    }
}

float spaceShip::FUEL() {
    float sum_fuel = 0;
    for (auto &module : rocket) {
        sum_fuel += module.getFuel();
    }
}

float spaceShip::AIR() {
    float sum_air = 0;
    for(auto  &module : rocket) {
        sum_air += module.getAir();
    }
}

float spaceShip::SPEED() const {
    return sqrtf(velocity.first*velocity.first + velocity.second*velocity.first);
}

void spaceShip::draw(sf::RenderWindow &window) {
    for(auto & i : rocket){
        i.drawSprite(window);
    }
}

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "cmath"


spaceShip::spaceShip(const vector<MODULE>& rocket, float x, float y, float angle) :rocket(rocket) {
    float length = 0;
    this->x = x;
    this->y = y;
    this->angle = angle;
    for (const auto& module : rocket) {
        cordCentreMass += module.getMasse() * (module.getParametrization().second / 2 + length);
        length += module.getParametrization().second;
        maxFuel += module.getFuel();
        maxAir += module.getAir();
    }
    length = 0;
    cordCentreMass /= getMass();
    for (const auto& module : rocket) {
        MomentOfInertia += (module.getMasse() * (module.getParametrization().second / 2 + length - cordCentreMass) *
            (module.getParametrization().second / 2 + length - cordCentreMass)) / 3;
        length += module.getParametrization().second;


        x = y = 0.5f;
    }
}

void spaceShip::move(float dt) {
    float F_x = 0, F_y = 0;
    float dAngularVelocity = 0;
    for (const auto& modul : rocket) {
        F_x += modul.Acceleration().first * modul.getMasse();
        F_y += modul.Acceleration().second * modul.getMasse();


        float a_bokovoie = modul.Acceleration().first * cos(angle) - modul.Acceleration().second * sin(angle);

        float length = 0;
        dAngularVelocity += modul.getMasse() * a_bokovoie *
            (modul.getParametrization().second / 2 + length - cordCentreMass) * dt
            / MomentOfInertia;
        length += modul.getParametrization().second;
    }

    x += velocity.first * dt + F_x * dt * dt / (2 * getMass());
    y += velocity.second * dt + F_y * dt * dt / (2 * getMass());

    velocity.first += F_x * dt / getMass();
    velocity.second += F_y * dt / getMass();


    angularVelocity += dAngularVelocity;

    angle += angularVelocity * dt;

    for (auto& i : rocket) {
        i.NewAcceleration(make_pair(0, 0));
    }
}
//&& module.Use_Fuel(module.Forward_PotAcceleration() / dfuel
void spaceShip::control() {

    bool crutch = false;
    float dfuel = 100000;
    float dair = 1000;

    cout << rocket[0].getMasse();
    for(int i = 0; i < this->rocket.size(); ++i){
        if (this->rocket[i].IsController) {crutch = true;}
    }
    if (crutch) {
        for (auto& module : rocket) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && module.IsEngine && this->Use_Fuel(module.Forward_PotForce()/ dfuel)) {
                module.EditAcceleration(make_pair(module.Forward_PotForce() * sin(angle)/ module.getMasse()
                                                  , module.Forward_PotForce() * cos(angle)/ module.getMasse()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && module.IsTurner && this->Use_Air(module.Side_PotForce() / dair)) {
                module.EditAcceleration(make_pair(module.Side_PotForce() * cos(angle) / module.getMasse(),
                                                  -module.Side_PotForce() * sin(angle)/ module.getMasse()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && module.IsTurner && this->Use_Air(module.Side_PotForce() / dair)) {
                module.EditAcceleration(make_pair(-module.Side_PotForce() * cos(angle)/ module.getMasse()
                                                  , module.Side_PotForce() * sin(angle)/ module.getMasse()));
            }
        }
    }
}

float spaceShip::FUEL() {
    float sum_fuel = 0;
    for (auto& module : rocket) {
        sum_fuel += module.getFuel();
    }
    return sum_fuel;
}

float spaceShip::AIR() {
    float sum_air = 0;
    for (auto& module : rocket) {
        sum_air += module.getAir();
    }
    return sum_air;
}

float spaceShip::ANGLE() {
    return angle;
}

vector<sf::Sprite> spaceShip::getSprite() const{
    vector<sf::Sprite> v;
    for (auto& module : rocket) {
        v.push_back(module.getSprite());
    }
    return v;
}

pair<float, float> spaceShip::getCoordinates() const{
    return make_pair(x, y);
}

float spaceShip::SPEED() const {
    return sqrtf(velocity.first * velocity.first + velocity.second * velocity.second);
}

void spaceShip::draw(sf::RenderWindow& window) {float length = 0;
    //????????? ???? ???????
    for (auto& i : rocket) {
        i.newAngle(angle);
        i.NewCord(x + sin(angle) * (i.getParametrization().first / 2 + length - cordCentreMass),
                  y + cos(angle) * (i.getParametrization().first / 2 + length - cordCentreMass));
        length += i.getParametrization().first;

        i.drawSprite(window);
    }
}

bool spaceShip::Use_Air(float dAir) {
    for (auto & i : rocket) {
        if (i.Use_Air(dAir)) {
            return true;
        }
    }
    return false;
}

bool spaceShip::Use_Fuel(float dFuel) {
    for (auto & i : rocket) {
        if (i.Use_Fuel(dFuel)) {
            return true;
        }
    }
    return false;
}

float spaceShip::getMass() const{
    float Mass = 0;
    for (auto & i : rocket) {
        Mass += i.getMasse() + 0.5 *  i.getFuel() + 0.1 * i.getAir();
    }
    return Mass;
}

float spaceShip::getMaxFuel() const{
    return this->maxFuel;
}

float spaceShip::getMaxAir() const {
    return this->maxAir;
}

void spaceShip::newCoordinate(float X, float Y, float A) {
    this->x = X;
    this->y = Y;
    this->angle = A;
}

int spaceShip::getAmountOfModules() const{
    return rocket.size();
}

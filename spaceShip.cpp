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
        MomentOfInertia += i.getMasse() * (i.getParametrization().second / 2 + length - cordCentreMass) *
                           (i.getParametrization().second / 2 + length - cordCentreMass);
        length += i.getParametrization().second;


        x = y = 0.5f;
    }
}

void spaceShip::move(float dt) {
    float F_x =0,F_y =0;
    float dAngularVelocity = 0;
    for(const auto & modul : rocket){
        F_x = modul.Acceleration().first*modul.getMasse();
        F_y = modul.Acceleration().second*modul.getMasse();

        pair<float,float> pravo = make_pair(cos(angle), -sin(angle));

        float a_bokovoie = pravo.second * modul.Acceleration().second/ sqrtf(pravo.second*pravo.second +pravo.first*pravo.first);

        float length=0;
        dAngularVelocity += modul.getMasse()*a_bokovoie*(modul.getParametrization().second/2+length-cordCentreMass);
        length += modul.getParametrization().second;
    }

    x+=velocity.first*dt + F_x*dt*dt/(2*Mass);
    y+=velocity.second*dt + F_y*dt*dt/(2*Mass);

    velocity.first += F_x*dt/Mass;
    velocity.second += F_y*dt/Mass;

    dAngularVelocity *= dt * MomentOfInertia/3;

    angularVelocity += dAngularVelocity;

    angle += angularVelocity*dt;

    float length=0;
    //????????? ???? ???????
    for(auto & i : rocket){
        i.newAngle(angle);
        i.NewCord(x + sin(angle)*(i.getParametrization().first/2+length-cordCentreMass),
                  y + cos(angle)*(i.getParametrization().first/2+length-cordCentreMass));
        length +=i.getParametrization().first;
    }
    cout << endl;
}

void spaceShip::control() {
    bool crutch = false;
    float dfuel = 1;
    float dair = 1;
    for(auto & module : rocket) {
        if(module.IsController) crutch = true;
    }
    if (crutch) {
        for (auto &module: rocket) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && module.IsEngine && module.Use_Fuel(module.Forward_PotAcceleration()/dfuel)) {
                module.EditAcceleration(make_pair(module.Forward_PotAcceleration() * sin(angle),
                                                      module.Forward_PotAcceleration() * cos(angle)));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && module.IsTurner && module.Use_Air(module.Side_PotAcceleration()/dair)) {
                module.EditAcceleration(make_pair(module.Side_PotAcceleration()*cos(angle), -module.Side_PotAcceleration()*sin(angle)));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && module.IsTurner && module.Use_Air(module.Side_PotAcceleration()/dair)) {
                module.EditAcceleration(make_pair(-module.Side_PotAcceleration()*cos(angle), module.Side_PotAcceleration()*sin(angle)));
            }
        }
    }
}


void spaceShip::draw(sf::RenderWindow &window) {
    for(auto & i : rocket){
        i.drawSprite(window);
    }
}

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include <cmath>

float cordCentreMass = 0;
spaceShip::spaceShip(const vector<MODULE>& rocket):rocket(rocket) {
    for(const auto & i : rocket){
        Mass += i.getMasse();
        cordCentreMass += i.getMasse() * (i.getParametrization().second/ 2 + length) ;
        length += i.getParametrization().second;
    }
    length=0;
    cordCentreMass /= Mass;
    for(const auto & i : rocket){
        MomentOfInertia += i.getMasse()*(i.getParametrization().second/2+length-cordCentreMass)*
                (i.getParametrization().second/2+length-cordCentreMass);
        length += i.getParametrization().second;
    }
}

void spaceShip::move(float dt) {
    float F_x =0,F_y =0;
    for(const auto & i : rocket){
        F_x = i.Acceleration().first*i.getMasse();
        F_y = i.Acceleration().second*i.getMasse();

        pair<float,float> pravo = make_pair(route.second, -route.first);
        float a_bokovoie = pravo.second * i.Acceleration().second/ sqrtf(pravo.second*pravo.second +pravo.first*pravo.first);

        length=0;
        angularVelocity += i.getMasse()*a_bokovoie*(i.getParametrization().second/2+length-cordCentreMass);
        length += i.getParametrization().second;
    }

    x+=velocity.first*dt + F_x*dt*dt/(2*Mass);
    y+=velocity.second*dt + F_y*dt*dt/(2*Mass);

    velocity.first += F_x*dt/Mass;
    velocity.second += F_y*dt/Mass;

    angularVelocity *= dt * MomentOfInertia/3;

    route.first *= cos(angularVelocity*dt);
    route.second *= sin(angularVelocity*dt);
}
void spaceShip::control() {
    for(auto & i : rocket) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && i.IsEngine) {
            i.EditAcceleration(make_pair(0,0));
        }
    }
}

void spaceShip::draw(sf::RenderWindow window) {
    for(auto & i : rocket){
        i.drawSprite(window);
    }
}

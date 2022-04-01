#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include <SFML/Graphics.hpp>
#include "math.h"

sf::Clock sf_clock;

float cordCentreMass = 0;
spaceShip::spaceShip(const vector<MODULE>& rocket) {
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

void spaceShip::move(vector<MODULE> &rocket) {
    float dt;
    for(const auto & i : rocket){
        dt = sf_clock.restart().asSeconds();
        x+=velocity.first*dt + i.Acceleration().first*dt*dt/2;
        y+=velocity.second*dt + i.Acceleration().second*dt*dt/2;

        pair<float,float> pravo = make_pair(route.second, -route.first);
        float a_bokovoie = pravo.second * i.Acceleration().second/ sqrtf(pravo.second*pravo.second +pravo.first*pravo.first);

        length=0;
        angularVelocity += i.getMasse()*a_bokovoie*(i.getParametrization().second/2+length-cordCentreMass);
        length += i.getParametrization().second;
    }
    angularVelocity *= dt * MomentOfInertia/3;

    route.first *= cos(angularVelocity*dt);
    route.second *= sin(angularVelocity*dt);
}

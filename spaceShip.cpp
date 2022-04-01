#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include <SFML/Graphics.hpp>

float dt = sf_clock.restart().asSeconds();

spaceShip::spaceShip(const vector<MODULE>& rocket) {
    float cordCentreMass = 0;
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
    for(const auto & i : rocket){

        x+=velocity.first + i.Acceleration().first*dt*dt/2;
    }

}

#include "MODULE.h"


pair<float,float> MODULE::Acceleration() const{
    return acceleration;
}

void MODULE::editAcceleration(pair<float, float> dopA) {
    acceleration.first += dopA.first;
    acceleration.second += dopA.second;
}

void MODULE::draw(float x, float y, pair<float, float> direction) {

}

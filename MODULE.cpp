#include "MODULE.h"


pair<float,float> MODULE::Acceleration() const{
    return acceleration;
}

void MODULE::EditAcceleration(pair<float, float> dop) {
    acceleration.first += dop.first;
    acceleration.second += dop.second;
}

float MODULE::PotAcceleration() const {
    return potAcceleration;
}

void MODULE::NewCord(float x, float y){
this->x = x;
this->y = y;
}


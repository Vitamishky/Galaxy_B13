#include "MODULE.h"


pair<float,float> MODULE::Acceleration() const{
    return acceleration;
}

void MODULE::editAcceleration(float ax, float ay) {
    acceleration.first += ax;
    acceleration.second += ay;
}

void MODULE::draw(float x, float y, pair<float, float> direction) {

}

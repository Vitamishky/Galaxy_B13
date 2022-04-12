#include "MODULE.h"

MODULE::MODULE(float potentialAceleration, bool IsEngine, bool IsController, bool IsTurner) : forward_potAcceleration(potentialAceleration), IsTurner(IsTurner), IsController(IsController), IsEngine(IsEngine) {
    Width = 128;
    Height = 128;
    texture.loadFromFile("image/chert.jpg");
    Sprite.setTexture(texture);
    fuel = 1000.f;
}

pair<float, float> MODULE::Acceleration() const {
    return acceleration;
}

void MODULE::EditAcceleration(pair<float, float> dop) {
    acceleration.first += dop.first;
    acceleration.second += dop.second;
}

float MODULE::Forward_PotAcceleration() const {
    return forward_potAcceleration;
}

bool MODULE::Use_Fuel(float dFuel) {
    if (fuel > 0) {
        fuel -= dFuel;
        if (fuel < 0) fuel = 0;
        return true;
    }
    return false;
}

bool MODULE::Use_Air(float dAir) {
    if (air > 0) {
        air -= dAir;
        if (air < 0) air = 0;
        return true;
    }
    return false;
}

float MODULE::getAir() {
    return air;
}

float MODULE::getFuel() {
    return fuel;
}

float MODULE::getAcceleration() {
    return sqrt(pow(acceleration.first, 2) + pow(acceleration.second, 2));
}

float MODULE::Side_PotAcceleration() const {
    return side_potAcceleration;
}

void MODULE::NewCord(float x, float y) {
    this->x = x;
    this->y = y;
}

void MODULE::NewAcceleration(pair<float, float> Na) {
    acceleration.first = Na.first;
    acceleration.second = Na.second;

}
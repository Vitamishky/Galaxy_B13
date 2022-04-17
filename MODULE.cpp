#include "MODULE.h"
#include "cmath"

MODULE::MODULE(float Masse, int Width, int Height, bool IsController,
    bool IsTurner, float Side_PotAcceleration, float Air, bool IsEngine,
    float Forward_PotAcceleration, float fuel) : forward_potAcceleration(Forward_PotAcceleration),
    side_potAcceleration(Side_PotAcceleration), air(Air), IsTurner(IsTurner),
    IsController(IsController), IsEngine(IsEngine), fuel(fuel) {
    this->Masse = Masse;
    this->Width = Width;
    this->Height = Height;
    texture.loadFromFile("image/chert.jpg");
    Sprite.setTexture(texture);
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

sf::Sprite MODULE::getSprite() {
    return Sprite;
}
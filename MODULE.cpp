#include "MODULE.h"
#include "functions.h"
#include "cmath"

MODULE::MODULE(string image,
               float Masse,
               int Width,
               int Height,
               bool IsController,
               bool IsTurner,
               float Side_PotForce,
               float Air,
               bool IsEngine,
               float Forward_PotForce,
               float fuel
               ): forward_potForce(Forward_PotForce),
               side_potForce(Side_PotForce),
               air(Air),
               IsTurner(IsTurner),
               IsController(IsController),
               IsEngine(IsEngine),
               fuel(fuel){
    this->Masse = Masse;
    this->Width = Width;
    this->Height = Height;
    texture.loadFromFile(image);
    Sprite.setTexture(texture);
}


pair<float,float> MODULE::Acceleration() const{
    return acceleration;
}

void MODULE::EditAcceleration(pair<float, float> dop) {
    acceleration.first += dop.first;
    acceleration.second += dop.second;
}

float MODULE::Forward_PotForce() const {
    return forward_potForce;
}

bool MODULE::Use_Fuel(float dFuel){
    if(fuel > 0) {
        fuel -= dFuel;
        if(fuel < 0) fuel = 0;
        return true;
    }
    return false;
}

bool MODULE::Use_Air(float dAir) {
    if(air > 0) {
        air -= dAir;
        if(air < 0) air = 0;
        return true;
    }
    return false;
}

float MODULE::getAir() const{
    return this->air;
}

float MODULE::getFuel() const{
    return this->fuel;
}

float MODULE::Side_PotForce() const {
    return side_potForce;
}

void MODULE::NewCord(float x, float y){
    this->x = x;
    this->y = y;
}

void MODULE::NewAcceleration(pair<float, float> Na) {
    acceleration.first=Na.first;
    acceleration.second=Na.second;

}

void MODULE::planetAttraction(vector<Planet>& planets) {
    for (auto& i : planets) {
        acceleration.first += functions::planetAttraction(*this, i).first;
        acceleration.second += functions::planetAttraction(*this, i).second;
    }
}

sf::Sprite MODULE::getSprite() const{
    return Sprite;
}
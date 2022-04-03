#include "MODULE.h"

MODULE::MODULE(float potentialAceleration, bool IsEngine, bool IsController, bool IsTurner): potAcceleration(potentialAceleration), IsTurner(IsTurner), IsController(IsController), IsEngine(IsEngine) {
    Width = 128;
    Height = 128;
    texture.loadFromFile("image/chert.jpg");
    Sprite.setTexture(texture);
}

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


#ifndef GALAXY_B13_MODULE_H
#define GALAXY_B13_MODULE_H
#include "spaceObjects.h"

class MODULE : public spaceObjects {
private:
    float forward_potForce;
    pair<float, float> acceleration = make_pair(0, 0);
    float side_potForce;
    float fuel;
    float air;
    string image;
public:
    MODULE(string image = "image/chert.jpg",
            int Width = 10,
            int Height = 10,
           float Masse = 100,
            bool IsController = false,
            bool IsTurner = false,
            float Side_PotForce = 0,
            float Air = 0,
            bool IsEngine = false,
            float Forward_PotForce = 0,
            float fuel = 0
    );
    bool IsController;
    bool IsEngine;
    bool IsTurner;
    pair<float, float> Acceleration() const;
    float Forward_PotForce() const;
    void EditAcceleration(pair<float, float> dop);
    float Side_PotForce() const;
    bool Use_Fuel(float);
    bool Use_Air(float);
    float getAir() const;
    float getFuel() const;
    float getMasse() const;
    string getPlaceOfImage() const;
    void NewCord(float, float);
    void NewAcceleration(pair<float, float>);
    sf::Sprite getSprite() const;
};

#endif //GALAXY_B13_MODULE_H
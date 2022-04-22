#ifndef UNTITLED11_SOUNDS_H
#define UNTITLED11_SOUNDS_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class sounds {
private:
    sf::Music* mus;
public:
    sounds(int);
    void changeMusic(int);
    sounds(std::string, float);
    void play(bool);
    void setVolume(float);
    ~sounds();
};


#endif //UNTITLED11_SOUNDS_H

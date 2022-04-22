#include "sounds.h"

sounds::sounds(std::string str, float initialVolume, float setPlayingOffset) {
    mus = new sf::Music;
    mus->openFromFile(str);
    mus->setPlayingOffset(sf::seconds(setPlayingOffset));
    mus->setVolume(initialVolume);
    mus->setLoop(true);
}

sounds::sounds(std::string str, float initialVolume) {
    mus = new sf::Music;
    mus->openFromFile(str);
    mus->setVolume(initialVolume);
    mus->setLoop(true);
}

void sounds::setVolume(float vol) {
    mus->setVolume(vol);
}

void sounds::play(bool b) {
    b ? mus->play(): mus->pause();
}


sounds::~sounds() {}

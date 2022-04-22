#include "sounds.h"

sounds::sounds(int num) {
    mus = new sf::Music;
    if (num == 0) {
        mus->openFromFile("sounds/Interstellar.wav");
        mus->setPlayingOffset(sf::seconds(20));
        mus->setVolume(23);
    }
    if (num == 1) {
        mus->openFromFile("sounds/trava.wav");
        mus->setVolume(4);
    }
    if (num == 2) {
        mus->openFromFile("sounds/champs.wav");
        mus->setVolume(5);
    }
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

void sounds::changeMusic(int num) {
    mus->stop();
    if (num == 0) {
        mus->openFromFile("sounds/Interstellar.wav");
        mus->setPlayingOffset(sf::seconds(20));
        mus->setVolume(20);
    }
    if (num == 1) {
        mus->openFromFile("sounds/trava.wav");
        mus->setVolume(5);
    }
    if (num == 2) {
        mus->openFromFile("sounds/champs.wav");
        mus->setVolume(7);
    }
    mus->play();
    mus->setLoop(true);
}

sounds::~sounds() {}

#ifndef camera_hpp
#define camera_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class camera {
private:
    sf::View view;
    sf::Vector2i position;
    bool locked;
    float scale;
public:
    camera(sf::RenderWindow&);
    ~camera();
    void resetView(sf::RenderWindow&);
    void lockedCamera(int x, int y);
    void unlockCamera();
    void moveCamera(int x, int y);
    void zoomCamera(sf::Event, sf::RenderWindow&);
    sf::View getViewCamera();
    //sf::View getCoordinatesForView(float x, float y);
};

#endif 
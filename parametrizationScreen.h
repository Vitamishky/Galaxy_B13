#ifndef parametrizationScreen_hpp
#define parametrizationScreen_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
//возвращает ширину и высоту экрана пользователя
class parametrizationScreen {
private:
	unsigned int width;
	unsigned int height;
public:
	parametrizationScreen();
	~parametrizationScreen();
	pair<unsigned int, unsigned int> getParametrizationScreen();
};

#endif
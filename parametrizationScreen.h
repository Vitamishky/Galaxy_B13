#ifndef parametrizationScreen_hpp
#define parametrizationScreen_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
//���������� ������ � ������ ������ ������������
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
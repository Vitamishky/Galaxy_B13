#include "functions.h"
#include <cmath>
#include "spaceObjects.h"


const float G = 1000;

pair<float, float> functions::planetAttraction(const spaceObjects& Slave, const Planet& Master)
/**
 * @param Slave:  То что получает ускорение
 * @param Master:  То к чеу притягивается тело
 * @return ускорение по x и по y
 */
{
    pair<float, float> length = make_pair(Master.getCoordinates().first - Slave.getCoordinates().first, Master.getCoordinates().second - Slave.getCoordinates().second);
    float distances = sqrtf(length.first * length.first + length.second * length.second);
    auto a = float(G * Master.getMasse() / (distances * distances));
    if (distances > Master.getRadius())
        return make_pair(a * length.first / distances,a * length.second / distances);
    else
        return make_pair(G * Master.getMasse() * length.first / fabs(length.first) / Master.getRadius() / Master.getRadius(),
                         G * Master.getMasse() * length.first / fabs(length.first) / Master.getRadius() / Master.getRadius());
}

//
// Created by user on 22.03.2022.
//

#include "functions.h"
#include <cmath>

const float G = 1;

pair<unsigned int, unsigned int> functions::attraction(const spaceShip& Slave, const spaceObjects& Master)
/**
 * @param Slave:  То что получает ускорение
 * @param Master:  То к чеу притягивается тело
 * @return ускорение по x и по y
 */
{
    pair length = make_pair(abs(Slave.getCoordinates().first - Master.getCoordinates().first), abs(Slave.getCoordinates().second - Master.getCoordinates().second));
    float distances = sqrtf(length.first * length.first + length.second * length.second);
    float a = float(G * Master.getMasse() / (distances * distances));
    return make_pair(a * length.first / distances,a * length.second / distances);
}
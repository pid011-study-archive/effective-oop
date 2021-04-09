#include "RaceCar.h"
#include <random>

std::random_device rd;
std::mt19937 randomGen(rd());
std::uniform_int_distribution<int> dist(1, 3);

void RaceCar::MoveFront()
{
    _pos += dist(randomGen);
    if (_pos >= _mapSize) _pos = static_cast<int>(_mapSize) - 1;
}

int RaceCar::IsFinished() const
{
    return _pos == _mapSize - 1;
}

#pragma once
#include <vector>
#include "RaceCar.h"

class RaceMap
{
public:
    const size_t Distance = 34;
    const size_t MaxLine = 4;
    const size_t Width = MaxLine + 2;

    RaceMap();
    ~RaceMap();

    bool Register(RaceCar* car);
    void Update();
    void Print() const;

private:
    const char Wall = '*';
    const char Empty = ' ';
    const char StartLine = '[';
    const char GoalLine = ']';

    char** map;
    std::vector<RaceCar*> _raceCars;
};

#include "RaceMap.h"
#include <iostream>

RaceMap::RaceMap()
{
    map = new char*[Width];

    for (size_t i = 0; i < Width; i++)
    {
        map[i] = new char[Distance];
        for (size_t j = 0; j < Distance; j++)
        {
            if (i == 0 || i == Width - 1)
            {
                map[i][j] = Wall;
                continue;
            }

            if (j == 0)
            {
                map[i][j] = StartLine;
                continue;
            }

            if (j == Distance - 1)
            {
                map[i][j] = GoalLine;
                continue;
            }

            map[i][j] = Empty;
        }
    }
}

RaceMap::~RaceMap()
{
    if (map)
    {
        for (size_t i = 0; i < MaxLine; i++)
        {
            delete[] map[i];
            map[i] = nullptr;
        }
        delete[] map;
        map = nullptr;
    }
}

bool RaceMap::Register(RaceCar* car)
{
    if (_raceCars.size() == MaxLine) // 맵의 라인이 꽉 참
    {
        return false;
    }

    // 라인넘버 부여
    int line = static_cast<int>(_raceCars.size()) + 1;
    car->SetLineNumber(line);
    _raceCars.push_back(car);

    map[car->LineNumber()][car->Position()] = car->Logo();

    return true;
}

void RaceMap::Update()
{
    for (const auto* car: _raceCars)
    {
        map[car->LineNumber()][0] = StartLine;
        for (size_t i = 1; i < Distance - 1; i++)
        {
            map[car->LineNumber()][i] = Empty;
        }
        map[car->LineNumber()][Distance - 1] = GoalLine;

        map[car->LineNumber()][car->Position()] = car->Logo();
        if (car->IsFinished())
        {
            // FINISH
            size_t pos = Distance / 2 - 3;
            map[car->LineNumber()][pos + 0] = 'F';
            map[car->LineNumber()][pos + 1] = 'I';
            map[car->LineNumber()][pos + 2] = 'N';
            map[car->LineNumber()][pos + 3] = 'I';
            map[car->LineNumber()][pos + 4] = 'S';
            map[car->LineNumber()][pos + 5] = 'H';
        }
    }
}

void RaceMap::Print() const
{
    for (size_t i = 0; i < Width; i++)
    {
        for (size_t j = 0; j < Distance; j++)
        {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

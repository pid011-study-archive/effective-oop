#include <iostream>
#include <vector>
#include <Windows.h>
#include <tuple>
#include <string>

#include "RaceMap.h"
#include "RaceCar.h"

void Race();

int main()
{
    bool retry = true;
    while (retry)
    {
        std::cout << "Say 'start' to start the race." << std::endl;
        std::string say;
        std::getline(std::cin, say);

        if (say == "start")
        {
            Race();
            continue;
        }

        retry = false;
    }
}

void Race()
{
    system("cls");

    using std::get;
    using std::tuple;
    using std::vector;

    RaceMap map;
    map.Print();

    vector<RaceCar*> cars = {
        new RaceCar('R', "Red", map.Distance),
        new RaceCar('B', "Blue", map.Distance),
        new RaceCar('Y', "Yellow", map.Distance),
        new RaceCar('G', "Green", map.Distance)
    };

    for (auto* car: cars)
    {
        map.Register(car);
    }

    vector<tuple<int, RaceCar*>> finished;

    int rank = 1;
    while (finished.size() < cars.size())
    {
        system("cls");
        int finishedCount = 0;
        for (auto& car: cars)
        {
            if (car->IsFinished()) continue;

            car->MoveFront();

            if (car->IsFinished())
            {
                finished.push_back(tuple<int, RaceCar*>(rank, car));
                finishedCount++;
            }
        }
        rank += finishedCount;

        map.Update();
        map.Print();
        Sleep(500);
    }

    std::cout << "\n=========================================" << std::endl;
    for (const auto& item: finished)
    {
        std::cout << "::" << get<0>(item) << ":: " << get<1>(item)->Name() << std::endl;
    }
    std::cout << "=========================================" << std::endl;

    for (auto& car: cars)
    {
        delete car;
        car = nullptr;
    }
}

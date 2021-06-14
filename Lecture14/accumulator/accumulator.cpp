#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

bool checkNumber(int number)
{
    return number > 3;
}

int calcNumber(int a, int b)
{
    return a * b;
}

int main()
{
    std::vector<int> numVector { 9, 5, 3 };

    {
        auto begin = std::cbegin(numVector);
        auto end = std::cend(numVector);

        int sum = std::accumulate(begin, end, 0);
        std::cout << "plus number: " << sum << std::endl;
    }

    {
        auto begin = std::cbegin(numVector);
        auto end = std::cend(numVector);

        int multi = std::accumulate(begin, end, 1, calcNumber);
        std::cout << "multi number: " << multi << std::endl;
    }
}

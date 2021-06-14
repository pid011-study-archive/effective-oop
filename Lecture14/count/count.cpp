#include <algorithm>
#include <vector>
#include <iostream>

bool checkNumber(int number)
{
    return number % 2 != 0;
}

int main()
{
    std::vector<int> numVector;
    for (int i = 1; i <= 100; ++i)
    {
        numVector.push_back(i);
    }

    auto begin = std::cbegin(numVector);
    auto end = std::cend(numVector);

    int count = std::count_if(begin, end, checkNumber);
    std::cout << "count_if: " << count << std::endl;
}

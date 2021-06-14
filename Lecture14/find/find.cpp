#include <algorithm>
#include <vector>
#include <iostream>

bool checkNumber(int number)
{
    return number > 3;
}

int main()
{
    std::vector<int> numVector { 9, 5, 3 };

    {
        auto begin = std::cbegin(numVector);
        auto end = std::cend(numVector);

        auto target = 12;
        auto findIterator = std::find(begin, end, target);

        if (findIterator == end)
        {
            std::cout << "not founded number" << std::endl;
        }
        else
        {
            std::cout << "found number: " << *findIterator << std::endl;
        }
    }

    {
        auto begin = std::cbegin(numVector);
        auto end = std::cend(numVector);

        auto target = 12;
        auto findIterator = std::find_if(begin, end, checkNumber);

        if (findIterator == end)
        {
            std::cout << "not founded number" << std::endl;
        }
        else
        {
            std::cout << "found number: " << *findIterator << std::endl;
        }
    }
}

#include <algorithm>
#include <vector>
#include <iostream>

int fillNumber()
{
    static int num = 100;
    return num += 2;
}

int main()
{
    std::vector<int> numVector(5);

    std::generate_n(numVector.begin(), 5, fillNumber);
    for (const auto& number: numVector)
    {
        std::cout << "num: " << number << std::endl;
    }
}

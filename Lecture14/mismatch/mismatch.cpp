#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    const std::vector<int> compareVector { 80, 5, 3 };
    const std::vector<int> compareList { 80, 13, 3 };

    const auto result = std::mismatch(
        compareVector.cbegin(), compareVector.cend(),
        compareList.cbegin(), compareList.cend());

    if (result.first == compareVector.end())
    {
        std::cout << "equal" << std::endl;
    }
    else
    {
        std::cout << result.first - compareVector.cbegin() << std::endl;
    }
}

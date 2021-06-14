#include <algorithm>
#include <iostream>
#include <vector>

bool checkEven(int data)
{
    return data % 2 == 0;
}

int main()
{
    std::vector<int> partitionVec { 4, 8, 3, 14, 5, 3, 20, 7 };
    ;
    std::vector<int> partitionOddVec(partitionVec.size());
    std::vector<int> partitionEvenVec(partitionVec.size());

    auto partitionEntity = std::partition_copy(
        partitionVec.begin(), partitionVec.end(),
        partitionEvenVec.begin(), partitionOddVec.begin(), checkEven);

    partitionEvenVec.erase(partitionEntity.first, partitionEvenVec.end());
    partitionOddVec.erase(partitionEntity.second, partitionOddVec.end());

    for (const auto& iter: partitionOddVec)
    {
        std::cout << iter << std::endl;
    }
    std::cout << std::endl;

    for (const auto& iter: partitionEvenVec)
    {
        std::cout << iter << std::endl;
    }
}

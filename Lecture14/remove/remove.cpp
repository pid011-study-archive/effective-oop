#include <iostream>
#include <vector>

bool checkRemove(int data)
{
    return data > 5;
}

int main()
{
    std::vector<int> removeVec { 3, 10, 3, 4 };

    auto removeEntity = std::remove_if(removeVec.begin(), removeVec.end(), checkRemove);
    std::cout << "cur size: " << removeVec.size() << std::endl;
    for (const auto& iter: removeVec)
    {
        std::cout << iter << std::endl;
    }

    removeVec.erase(removeEntity, removeVec.end());
    std::cout << "cur size: " << removeVec.size() << std::endl;
    for (const auto& iter: removeVec)
    {
        std::cout << iter << std::endl;
    }
}

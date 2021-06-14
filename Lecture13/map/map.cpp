#include <iostream>
#include <map>
#include <vector>

int main()
{
    std::map<std::string, int> intMapData = {
        { "KOR", 2 },
        { "FRANCE", 3 }
    };

    std::map<std::string, std::vector<int>> intMapDataExt = {
        { "KOR", { 2, 3, 4, 2, 4 } },
        { "FRANCE", { 2, 3, 4, 3, 3 } }
    };

    // first: iterator, second: insert result boolean
    auto pariValue = intMapData.insert({ "SWEDEN", 5 });
    if (pariValue.second)
    {
        std::cout << pariValue.first->first << std::endl;
        std::cout << pariValue.first->second << std::endl;
    }

    auto spainValue = intMapData.insert(std::make_pair("Spain", 3));
    if (spainValue.second)
    {
        std::cout << spainValue.first->first << std::endl;
        std::cout << spainValue.first->second << std::endl;
    }

    if (auto denmarkValue = intMapData.insert({ "Denmark", 4 }); denmarkValue.second)
    {
        std::cout << denmarkValue.first->first << std::endl;
        std::cout << denmarkValue.first->second << std::endl;
    }

    if (auto [iterator, result] = intMapData.insert({ "Turkey", 2 }); result)
    {
        std::cout << iterator->first << std::endl;
        std::cout << iterator->second << std::endl;
    }

    std::cout << std::endl;

    // C++ 17
    for (const auto& [key, value]: intMapData)
    {
        std::cout << key << ' ' << value << std::endl;
    }

    if (const auto findResult = intMapData.find("FRANCE"); findResult != std::end(intMapData))
    {
        findResult->second = 102;
    }

    std::cout << std::endl;

    std::map<std::string, int> delMapData = {
        { "KOR", 2 },
        { "FRANCE", 3 },
        { "Sweden", 10 },
        { "Turkey", 30 },
        { "Austrailia", 90 }
    };
    delMapData.erase("KOR");
    auto deleter = delMapData.find("Sweden");

    // map은 데이터가 추가될 때 키 값으로 정렬
    delMapData.erase(deleter, delMapData.end());
    for (const auto& [key, value]: delMapData)
    {
        std::cout << key << ' ' << value << std::endl;
    }
}

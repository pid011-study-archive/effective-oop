#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

struct General
{
    std::string Country;
    std::string Name;
    int AttackPower = 0;

    bool operator<(const General& compare) const
    {
        return AttackPower < compare.AttackPower;
    }

    bool operator>(const General& compare) const
    {
        return *this < compare;
    }
};

bool CheckCountry(const General& general)
{
    static std::map<std::string, int> check;
    const auto num = ++check[general.Name];
    return num > 1;
}

bool CompareAP(const General& a, const General& b)
{
    return a.AttackPower > b.AttackPower;
}

int main()
{
    int length;
    std::cin >> length;

    std::vector<General> inputs;
    for (int i = 0; i < length; ++i)
    {
        General general;
        std::cin >> general.Country >> general.Name >> general.AttackPower;
        inputs.push_back(general);
    }

    const auto filter = std::find_if(inputs.begin(), inputs.end(), CheckCountry);
    const auto remove = std::remove_if(inputs.begin(), inputs.end(), [&](const General& g) {
        return g.Name == filter->Name;
    });
    inputs.erase(remove, inputs.end());

    std::unordered_map<std::string, std::vector<General>> group;

    for (auto& general: inputs)
    {
        group[general.Country].push_back(general);
    }

    std::cout << std::endl;
    for (auto& [country, generals]: group)
    {
        std::cout << country << std::endl;
        std::sort(generals.begin(), generals.end(), CompareAP);
        for (const auto& general: generals)
        {
            std::cout << general.Name << ' ' << general.AttackPower << std::endl;
        }
    }
}

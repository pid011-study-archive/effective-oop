#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector, std::string, std::cout, std::endl;

int main()
{
    vector<string> countries;

    for (size_t i = 0; i < 10; ++i)
    {
        string country;
        std::getline(std::cin, country);

       countries.push_back(country);
    }

    cout << endl;

    std::sort(
        countries.begin(), 
        countries.end(), 
        [](const string& a, const string& b) { return a.length() > b.length(); });

    for (const auto& country: countries)
    {
        cout << country << endl;
    }
}

/*
Montenegro
Morocco
Mozambique
Myanmar, {Burma}
Namibia
Nauru**
Nepal
Netherlands
New Zealand
Nicaragua

Myanmar, {Burma}
Netherlands
New Zealand
Montenegro
Mozambique
Nicaragua
Morocco
Namibia
Nauru**
Nepal
 */

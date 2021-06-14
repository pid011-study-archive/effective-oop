#include <algorithm>
#include <iostream>
#include <vector>

std::vector<char> CopyUniqueArray(const std::vector<char>& sources)
{
    std::vector<char> dest(sources);

    auto isUnique = [](char ch) {
        static char previous = '\0';

        const auto result = previous != ch;
        previous = ch;
        return result;
    };

    const auto result = std::copy_if(sources.begin(), sources.end(), dest.begin(), isUnique);
    dest.resize(std::distance(dest.begin(), result));

    return dest;
}

int main()
{
    std::vector<char> inputs;
    int length;
    std::cin >> length;
    for (int i = 0; i < length; ++i)
    {
        char ch;
        std::cin >> ch;
        inputs.push_back(ch);
    }
    auto dest = CopyUniqueArray(inputs);
    for (const auto& i: dest)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

#include <vector>
#include <sstream>

inline std::vector<std::string> split(std::string input, char delimiter)
{
    std::vector<std::string> splited;
    std::stringstream ss(input);
    std::string temp;

    while (getline(ss, temp, delimiter)) splited.push_back(temp);
    return splited;
}
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> stringArray;
    stringArray.push_back("korea");
    stringArray.push_back("sweden");
    stringArray.push_back("france");

    //for (auto item = stringArray.begin(); item != stringArray.end(); ++item)
    //{
    //    std::cout << *item << std::endl;
    //}

    for (auto item = stringArray.cbegin(); item != stringArray.end(); ++item)
    {
        std::cout << *item << std::endl;
    }
}

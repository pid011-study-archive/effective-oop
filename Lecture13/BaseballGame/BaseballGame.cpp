#include <map>
#include <iostream>

int main()
{
    int inputLength;
    std::string filter;

    std::cin >> inputLength >> filter;

    std::multimap<std::string, std::string> inputs;
    for (int i = 0; i < inputLength; ++i)
    {
        std::string name, team;
        std::cin >> name >> team;
        inputs.insert({ team, name });
    }
    std::cout << std::endl;
    auto [biter, eiter] = inputs.equal_range(filter);

    std::cout << biter->first << std::endl;
    for (auto iter = biter; iter != eiter; ++iter)
    {
        std::cout << iter->second << std::endl;
    }
}

/*
8 두산
강백호 KT
양의지 NC
이정후 키움
강민호 삼성
피렐라 삼성
페르난데스 두산
박건우 두산
최원준 KIA

두산
페르난데스
박건우
 */

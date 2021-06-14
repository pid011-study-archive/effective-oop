#include <iostream>
#include <list>
#include <utility>
#include <vector>

class Player
{
public:
    explicit Player(std::string& name, int id)
        : _name(name), _id(id)
    {
    }

private:
    std::string _name;
    int _id;
};

bool confirmFunc(const std::string str)
{
    std::cout << "str size: " << str.size() << std::endl;
    return str.size() > 5;
}

bool sortFunc(const std::string lhs, const std::string rhs)
{
    return lhs.size() < rhs.size();
}

int main()
{
    std::list<std::string> listData;
    listData.push_back("가나0");
    listData.push_front("가나01");
    listData.push_front("가나02");
    listData.push_back("가나03");

    auto frontData = listData.front();
    auto backData = listData.back();

    listData.pop_back();
    listData.push_front("가나04");
    listData.pop_front();

    listData.insert(listData.begin(), "가나S1");

    auto emplaceRefData = listData.emplace_back("가나05");
    auto emplaceData = listData.emplace(listData.end(), "가나06");

    for (const auto item: listData)
    {
        std::cout << item << std::endl;
    }

    listData.erase(listData.begin());
    listData.remove("가나S1");
    listData.insert(listData.begin(), "가나10");
    listData.insert(listData.begin(), "가나10");
    listData.insert(listData.begin(), "가나10");
    listData.unique();
    listData.sort(sortFunc);
    listData.sort();
    listData.reverse();

    std::list<std::string> listDataExt;
    listDataExt.push_back("CK1");
    listDataExt.push_back("CK2");
    listDataExt.splice(listDataExt.end(), listData);
    listDataExt.remove_if(confirmFunc);
    listDataExt.clear();

    std::list<Player> players;
    players.emplace_back("player1", 138593);
}

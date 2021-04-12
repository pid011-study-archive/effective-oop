#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;

class Player
{
public:
    std::string Name;
    std::string Team;
    std::string Position;
    int Stats;

    Player(std::string name, std::string team, std::string position, int stat)
        : Name(name), Team(team), Position(position), Stats(stat) { }

    void printPlayer() const
    {
        cout << "team       : " << Team << endl
             << "position   : " << Position << endl
             << "name       : " << Name << endl
             << "statistics : " << Stats << endl;
    }

    bool operator<(const Player& other) const { return Stats < other.Stats; }
    bool operator>(const Player& other) const { return !(*this < other); }
    bool operator==(const Player& other) const { return Stats == other.Stats; }
    bool operator!=(const Player& other) const { return !(*this == other); }
};

int main()
{
    using std::unique_ptr;

    unique_ptr<Player> p1 = std::make_unique<Player>("ÀüÁØ¿ì", "·Ôµ¥", "³»¾ß¼ö", 48);
    p1->printPlayer();

    cout << endl;

    unique_ptr<Player> p2 = std::make_unique<Player>("±è¼±ºó", "KIA", "³»¾ß¼ö", 53);
    p2->printPlayer();

    cout << endl;

    unique_ptr<Player> acePlayer = *p1 > *p2 ? std::move(p1) : std::move(p2);

    cout << acePlayer->Name << ' ' << acePlayer->Stats << endl;

    acePlayer.reset();
}
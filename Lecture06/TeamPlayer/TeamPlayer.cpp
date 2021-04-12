#include <iostream>
#include <memory>
#include <string>

using namespace std;

class FPSPlayer
{
public:
    FPSPlayer(const string& name) : mLv(1), mName(name)
    {
        cout << "FPSPlayer 플레이어 : " << mName << " 생성자 호출"
             << endl;
    }
    ~FPSPlayer()
    {
        cout << "FPSPlayer 플레이어 : " << mName << " 소멸자 호출"
             << endl;
    }
    void setTeamPlayer(shared_ptr<FPSPlayer>& player)
    {
        if (player == nullptr)
        {
            return;
        }

        weak_ptr<FPSPlayer> connectPlayer(player);
        // weak_ptr을 만들어서 저장하면 reference count 변경 안됨

        mTeamPlayer = connectPlayer;

        cout << "TeamPlayer Name : " << player->mName << endl;
    }

    void showTeamPlayer() const
    {
        auto player = mTeamPlayer.lock();
        cout << "TeamPlayer: " << player->mName << endl;
    }

private:
    int mLv;
    string mName;
    weak_ptr<FPSPlayer> mTeamPlayer;
};

int main()
{
    auto pRedPlayer = make_shared<FPSPlayer>("RedPlayer");
    auto pOrangePlayer = make_shared<FPSPlayer>("OrangePlayer");

    pRedPlayer->setTeamPlayer(pOrangePlayer);
    pOrangePlayer->setTeamPlayer(pRedPlayer);

    pRedPlayer->showTeamPlayer();
}
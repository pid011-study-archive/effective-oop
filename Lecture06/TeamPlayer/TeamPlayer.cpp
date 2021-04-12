#include <iostream>
#include <memory>
#include <string>

using namespace std;

class FPSPlayer
{
public:
    FPSPlayer(const string& name) : mLv(1), mName(name)
    {
        cout << "FPSPlayer �÷��̾� : " << mName << " ������ ȣ��"
             << endl;
    }
    ~FPSPlayer()
    {
        cout << "FPSPlayer �÷��̾� : " << mName << " �Ҹ��� ȣ��"
             << endl;
    }
    void setTeamPlayer(shared_ptr<FPSPlayer>& player)
    {
        if (player == nullptr)
        {
            return;
        }

        weak_ptr<FPSPlayer> connectPlayer(player);
        // weak_ptr�� ���� �����ϸ� reference count ���� �ȵ�

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
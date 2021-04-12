#include <iostream>
#include <memory>

using namespace std;

class Player
{
public:
    Player() : id(10)
    {
        pHaveWeaponID = new int[10];
        cout << "플레이어 무기 할당" << endl;
    }

    ~Player()
    {
        cout << "플레이어 무기 해제" << endl;
        delete[] pHaveWeaponID;
        pHaveWeaponID = nullptr;
    }

    void printHaveWeapon()
    {
        cout << "플레이어 무기 장착 ID: " << id << endl;
    }

private:
    int id;
    int* pHaveWeaponID;
};

void runFunction()
{
    unique_ptr<Player> RedPlayer(new Player());
    RedPlayer->printHaveWeapon();

    // 인스턴스 자체를 옮겨서 생성자 호출 안됨
    unique_ptr<Player> BluePlayer = move(RedPlayer);
    BluePlayer->printHaveWeapon();
}

void runBasicResetFunction()
{
    unique_ptr<Player> RedPlayer(new Player());
    RedPlayer.reset();
    cout << "reset 호출 후 : " << RedPlayer.get();
}

void runBasicResetNewFunction()
{
    unique_ptr<Player> RedPlayer(new Player());
    cout << "reset 호출 전 : " << RedPlayer.get() << endl;
    RedPlayer.reset(new Player());
    cout << "reset 호출 후 : " << RedPlayer.get() << endl;
}

void runSharedPtrFunction()
{
    shared_ptr<Player> RedPlayerShared(new Player);
    shared_ptr<Player> BluePlayerShared(new Player);
    shared_ptr<Player> BlackPlayerShared(new Player);

    cout << "Red: " << RedPlayerShared.use_count() << endl;
    cout << "Blue: " << BluePlayerShared.use_count() << endl;
    cout << "Black: " << BlackPlayerShared.use_count() << endl;

    BlackPlayerShared = BluePlayerShared;
    // shared_ptr이 기존 객체를 소멸시키고 새로 할당함. black은 소멸되어서 black은 blue를 가리킴
    // reference count도 증가함

    cout << "Red: " << RedPlayerShared.use_count() << ' ' << RedPlayerShared.get() << endl;
    cout << "Blue: " << BluePlayerShared.use_count() << ' ' << BluePlayerShared.get() << endl;
    cout << "Black: " << BlackPlayerShared.use_count() << ' ' << BlackPlayerShared.get() << endl;
}

int main()
{
    runSharedPtrFunction();
    return 1;
}
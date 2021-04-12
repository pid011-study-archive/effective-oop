#include <iostream>
#include <memory>

using namespace std;

class Player
{
public:
    Player() : id(10)
    {
        pHaveWeaponID = new int[10];
        cout << "�÷��̾� ���� �Ҵ�" << endl;
    }

    ~Player()
    {
        cout << "�÷��̾� ���� ����" << endl;
        delete[] pHaveWeaponID;
        pHaveWeaponID = nullptr;
    }

    void printHaveWeapon()
    {
        cout << "�÷��̾� ���� ���� ID: " << id << endl;
    }

private:
    int id;
    int* pHaveWeaponID;
};

void runFunction()
{
    unique_ptr<Player> RedPlayer(new Player());
    RedPlayer->printHaveWeapon();

    // �ν��Ͻ� ��ü�� �Űܼ� ������ ȣ�� �ȵ�
    unique_ptr<Player> BluePlayer = move(RedPlayer);
    BluePlayer->printHaveWeapon();
}

void runBasicResetFunction()
{
    unique_ptr<Player> RedPlayer(new Player());
    RedPlayer.reset();
    cout << "reset ȣ�� �� : " << RedPlayer.get();
}

void runBasicResetNewFunction()
{
    unique_ptr<Player> RedPlayer(new Player());
    cout << "reset ȣ�� �� : " << RedPlayer.get() << endl;
    RedPlayer.reset(new Player());
    cout << "reset ȣ�� �� : " << RedPlayer.get() << endl;
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
    // shared_ptr�� ���� ��ü�� �Ҹ��Ű�� ���� �Ҵ���. black�� �Ҹ�Ǿ black�� blue�� ����Ŵ
    // reference count�� ������

    cout << "Red: " << RedPlayerShared.use_count() << ' ' << RedPlayerShared.get() << endl;
    cout << "Blue: " << BluePlayerShared.use_count() << ' ' << BluePlayerShared.get() << endl;
    cout << "Black: " << BlackPlayerShared.use_count() << ' ' << BlackPlayerShared.get() << endl;
}

int main()
{
    runSharedPtrFunction();
    return 1;
}
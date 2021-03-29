#include <iostream>

class Item
{
public:
    int number;
};

class Inventory
{
public:
    Inventory(int itemNum)
    {
        _items = new Item[itemNum];
    }

    Inventory(const Inventory& rhs)
    {
        if (rhs._items != nullptr)
        {
            size_t size = _msize(rhs._items) / sizeof(Item);
            _items = new Item[size];
            for (size_t i = 0; i < size; i++)
            {
                _items[i] = rhs._items[i];
            }
        }
    }

    Inventory& operator=(const Inventory& rhs)
    {
        // 자기 자신이면 그냥 리턴
        if (&rhs == this) return *this;

        // swap기능 이용
        // 기존 데이터를 미리 보관하고 있다가 할당에 실패하면 보존한 데이터를 다시 할당
        Item* originItems = _items;
        size_t size = _msize(rhs._items) / sizeof(Item);

        if (size > 0)
        {
            _items = new Item[size];
            for (size_t i = 0; i < size; i++)
            {
                _items[i] = rhs._items[i];
            }
        }

        delete[] originItems;

        // 아래는 swap을 사용하지 않아 데이터를 잃어버릴 위험이 있음
        //delete[] _items;

        //size_t size = _msize(rhs._items) / sizeof(Item);
        //_items = new Item[size];
        //for (size_t i = 0; i < size; i++)
        //{
        //    _items[i] = rhs._items[i];
        //}

        return *this;
    }

    ~Inventory()
    {
        delete[] _items;
        _items = nullptr;
    }

private:
    Item* _items = nullptr;
};

int main()
{
    Inventory playerInven(10);
    Inventory npcInven(5);
    playerInven = npcInven;
}
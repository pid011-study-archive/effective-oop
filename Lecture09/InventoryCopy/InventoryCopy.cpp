#include <iostream>

class Item
{
public:
    int number;
};

class Inventory
{
public:
    explicit Inventory(int itemNum)
    {
        _items = new Item[itemNum];
    }

    Inventory(const Inventory& rhs)
    {
        size_t size = _msize(rhs._items) / sizeof(Item);
        _items = new Item[size];
        for (size_t i = 0; i < size; i++)
        {
            _items[i] = rhs._items[i];
        }
    }

    Inventory(Inventory&& rhs) noexcept
    {
        size_t size = _msize(rhs._items) / sizeof(Item);
        _items = new Item[size];
        for (size_t i = 0; i < size; i++)
        {
            _items[i] = rhs._items[i];
        }

        delete[] rhs._items;
        rhs._items = nullptr;
    }

    Inventory& operator=(const Inventory& rhs)
    {
        if (&rhs == this) return *this;

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
        return *this;
    }

    Inventory& operator=(Inventory&& rhs) noexcept
    {
        if (&rhs == this) return *this;

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

        delete[] rhs._items;
        rhs._items = nullptr;

        return *this;
    }

    size_t Size() const
    {
        if (_items == nullptr) return 0;

        return _msize(_items) / sizeof(Item);
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
    using std::cout;
    using std::endl;

    Inventory playerInven(10);
    cout << "player inven size: " << playerInven.Size() << endl;

    Inventory npcInven(5);
    cout << "npc inven size: " << npcInven.Size() << endl;

    cout << endl;

    playerInven = npcInven;
    cout << "player inven size: " << playerInven.Size() << endl;
    cout << "npc inven size: " << npcInven.Size() << endl;

    cout << endl;

    npcInven = Inventory(20);
    cout << "npc inven size: " << npcInven.Size() << endl;

    cout << endl;

    playerInven = std::move(npcInven);
    cout << "player inven size: " << playerInven.Size() << endl;
    cout << "npc inven size: " << npcInven.Size() << endl;
}

/*
player inven size: 10
npc inven size: 5

player inven size: 5
npc inven size: 5

npc inven size: 20

player inven size: 20
npc inven size: 0
*/

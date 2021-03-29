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
        // �ڱ� �ڽ��̸� �׳� ����
        if (&rhs == this) return *this;

        // swap��� �̿�
        // ���� �����͸� �̸� �����ϰ� �ִٰ� �Ҵ翡 �����ϸ� ������ �����͸� �ٽ� �Ҵ�
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

        // �Ʒ��� swap�� ������� �ʾ� �����͸� �Ҿ���� ������ ����
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
#include <iostream>
#include <algorithm>
#include <vector>

class MemoryBlock
{
public:
    explicit MemoryBlock(size_t length) : _length(length), _data(new int[length])
    {
        std::cout << "Constructor Length: " << _length << std::endl;
    }

    ~MemoryBlock()
    {
        std::cout << "Destructor Length: " << _length << std::endl;
        if (_data != nullptr)
        {
            std::cout << "Deleting resource." << std::endl;
            delete[] _data;
        }
    }

    MemoryBlock(const MemoryBlock& other) : _length(other._length), _data(new int[other._length])
    {
        std::cout << "Copy Constructor Length: " << _length << std::endl;
        memcpy_s(_data, _length, other._data, _length);
    }

    MemoryBlock& operator=(const MemoryBlock& other)
    {
        std::cout << "Copy assignment operator Length: " << other._length << std::endl;
        if (this != &other)
        {
            delete[] _data;
            _length = other._length;
            _data = new int[_length];
            memcpy_s(_data, _length, other._data, _length);
        }
        return *this;
    }

    MemoryBlock(MemoryBlock&& other) noexcept : _data(nullptr), _length(0)
    {
        std::cout << "In MemoryBlock(MemoryBlock&&).length = " << other._length << ". Moving resource." << std::endl;

        _data = other._data;
        _length = other._length;

        other._data = nullptr;
        other._length = 0;
    }

    MemoryBlock& operator=(MemoryBlock&& other) noexcept
    {
        std::cout << "In operator=(MemoryBlock&&).length = " << other._length << "." << std::endl;

        if (this != &other)
        {
            delete[] _data;
            _data = other._data;
            _length = other._length;

            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }

    size_t Length() const
    {
        return _length;
    }

private:
    size_t _length;
    int* _data;
};

int main()
{
    std::vector<MemoryBlock> vTemp;
    vTemp.push_back(MemoryBlock(50));
    std::cout << "====================" << std::endl;
    vTemp.push_back(MemoryBlock(100));
    std::cout << "====================" << std::endl;
    vTemp[0] = MemoryBlock(75);
    std::cout << "====================" << std::endl;
    return 0;
}

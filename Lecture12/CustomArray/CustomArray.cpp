#include <iostream>
#include <stdexcept>
#include <array>

template<typename T, size_t Size>
class CustomArray
{
public:
    explicit CustomArray()
    {
        _array.fill(0);
    }

    T& operator[](size_t idx)
    {
        if (idx >= Size)
        {
            throw std::out_of_range("배열이 범위를 벗어났습니다.");
        }
        return _array[idx];
    }

    [[nodiscard]] size_t Length() const
    {
        return _array.size();
    }

private:
    std::array<T, Size> _array;
};

int main()
{
    CustomArray<float, 10> array;

    std::cout << array[4] << std::endl;

    array[9] = 123.4f;
    std::cout << array[9] << std::endl;

    std::cout << "array length: " << array.Length() << std::endl;

    try
    {
        std::cout << array[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

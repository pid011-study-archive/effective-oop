#include <iostream>

template<typename T>
void getArraySize(T arr)
{
    std::cout << sizeof arr / sizeof arr[0] << std::endl;
}

template<typename T>
void getArraySizeExt(T& arr)
{
    std::cout << sizeof arr / sizeof arr[0] << std::endl;
}

int main()
{
    int arrint[] = { 1, 2, 3, 4, 5 };

    getArraySize(arrint);
    getArraySizeExt(arrint);
}

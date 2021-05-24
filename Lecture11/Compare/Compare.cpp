#include <iostream>
#include <random>

template<typename T1, typename T2>
void PrintCompare(T1 a, T2 b)
{
    if (a > b)
    {
        std::cout << "첫번째 수가 큽니다." << std::endl;
    }
    else if (a < b)
    {
        std::cout << "두번째 수가 큽니다." << std::endl;
    }
    else
    {
        std::cout << "두 수는 똑같습니다." << std::endl;
    }
}

template<typename T>
void PrintCompare(T& arr)
{
    const int length = sizeof(arr) / sizeof(arr[0]);

    if (length == 0) return;

    // auto를 사용하면 arr[0]이 int임을 자동 추론함
    auto max = arr[0];
    auto min = arr[0];

    for (int i = 0; i < length; ++i)
    {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    std::cout << "가장 큰 수: " << max << std::endl;
    std::cout << "가장 작은 수: " << min << std::endl;
}

int main()
{
    PrintCompare(1, 2);
    PrintCompare(10, 3.4);

    std::cout << std::endl;

    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<int> dist(1, 100);

    int randomArray[10];
    for (int& i: randomArray)
    {
        i = dist(gen);
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    PrintCompare(randomArray);
}

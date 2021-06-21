#include <iostream>
#include <vector>
#include <random>
#include <map>

template<typename T>
void printArrayInfo(const std::vector<T>& sources)
{
    size_t length = sources.size();

    if (length == 0)
    {
        return;
    }

    size_t middle = length / 2;
    bool isOdd = length % 2 != 0;

    T average {}, median {}, mod {};
    std::map<T, size_t> check;

    for (size_t i = 0; i < length; i++)
    {
        average += sources[i];

        if (i == middle)
        {
            median = isOdd ? sources[i] : (sources[i - 1] + sources[i]) / 2;
        }
        ++check[sources[i]];
    }

    average /= length;

    size_t max {};
    for (const auto& [k, v]: check)
    {
        if (max < v)
        {
            mod = k;
            max = v;
        }
    }

    std::cout << "평균값 : " << average << std::endl;
    std::cout << "중앙값 : " << median << std::endl;
    std::cout << "최빈값 : " << mod << std::endl;
}

int main()
{
    // test
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    std::vector<float> sources;
    const size_t n = 34;
    for (size_t i = 0; i < n; i++)
    {
        auto v = dis(gen);
        sources.push_back(v);
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    printArrayInfo(sources);
}

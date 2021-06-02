#pragma once
#include <vector>
#include <iostream>

template<typename T>
class ObjectManager
{
public:
    void AddObject(const T& obj);
    const T& GetObject(size_t idx);

private:
    std::vector<T> _objects;
};

template<typename T>
void ObjectManager<T>::AddObject(const T& obj)
{
    _objects.push_back(obj);
    std::cout << "AddObject data type" << std::endl;
}

template<typename T>
const T& ObjectManager<T>::GetObject(size_t idx)
{
    std::cout << "GetObject data type" << std::endl;
    return _objects.at(idx);
}

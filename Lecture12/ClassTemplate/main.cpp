#include "ObjectManager.h"
#include <string>

void example()
{
    using objController = ObjectManager<int>;
    ObjectManager<int> arrayObjectManager[3];
    objController arrayObjectController[3];

    ObjectManager<int*> ptrArrayObjectManager[10];
    ObjectManager<ObjectManager<int>> dObjectManager;

    dObjectManager.AddObject(arrayObjectManager[0]);
    dObjectManager.AddObject(arrayObjectManager[1]);
    dObjectManager.AddObject(arrayObjectManager[2]);

    auto itemObjectManager = dObjectManager.GetObject(0);
    itemObjectManager.AddObject(100);
    auto item = itemObjectManager.GetObject(0);
    std::cout << "item value: " << item << std::endl;
}

int main()
{
    ObjectManager<int> intObjects;
    ObjectManager<std::string> stringObjects;

    intObjects.AddObject(10);
    stringObjects.AddObject("가나다");

    auto intVal = intObjects.GetObject(0);
    auto strVal = stringObjects.GetObject(0);

    std::cout << intVal << std::endl;
    std::cout << strVal << std::endl;

    example();
}

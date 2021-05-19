#include <iostream>
#include <memory>
#include "Jobs.h"
#include "Weapons.h"

int main()
{
    const Engineer engineer(std::make_unique<GunWeapon>());
    const Assault assault(std::make_unique<LaserWeapon>());
    const Medic medic(std::make_unique<RocketWeapon>());

    engineer.Weapon()->printWeaponName();
    std::cout << medic.JobName() << std::endl;

    engineer.attack();
    assault.attack();
    medic.attack();
}

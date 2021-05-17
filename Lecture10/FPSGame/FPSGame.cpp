#include <iostream>
#include "Jobs.h"
#include "Weapons.h"

int main()
{
    Engineer engineer(GunWeapon {});
    Assault assault(LaserWeapon {});
    Medic medic(RocketWeapon {});

    engineer.attack();
    assault.attack();
    medic.attack();
}

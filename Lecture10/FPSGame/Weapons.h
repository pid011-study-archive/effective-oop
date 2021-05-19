#pragma once
#include <string>
#include <iostream>
#include "IWeapon.h"

class GunWeapon : public IWeapon
{
public:
    void fire() const override
    {
        std::cout << "fire - gun" << std::endl;
    }

    void printWeaponName() const override
    {
        std::cout << "Gun" << std::endl;
    }

private:
};

class RocketWeapon : public IWeapon
{
public:
    void fire() const override
    {
        std::cout << "fire - rocket" << std::endl;
    }

    void printWeaponName() const override
    {
        std::cout << "Rocket" << std::endl;
    }
};

class LaserWeapon : public IWeapon
{
public:
    void fire() const override
    {
        std::cout << "fire - laser" << std::endl;
    }

    void printWeaponName() const override
    {
        std::cout << "Laser" << std::endl;
    }
};

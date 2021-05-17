#pragma once
#include <string>
#include <iostream>
#include "IWeapon.h"

class GunWeapon : public IWeapon
{
public:
    virtual void fire() const override
    {
        std::cout << "fire - gun" << std::endl;
    }

    virtual void getWeaponName() const override
    {
        std::cout << "Gun" << std::endl;
    }

private:
};

class RocketWeapon : public IWeapon
{
public:
    virtual void fire() const override
    {
        std::cout << "fire - rocket" << std::endl;
    }

    virtual void getWeaponName() const override
    {
        std::cout << "Rocket" << std::endl;
    }
};

class LaserWeapon : public IWeapon
{
public:
    virtual void fire() const override
    {
        std::cout << "fire - laser" << std::endl;
    }

    virtual void getWeaponName() const override
    {
        std::cout << "Laser" << std::endl;
    }
};

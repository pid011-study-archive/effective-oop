#pragma once
class IWeapon
{
public:
    virtual ~IWeapon() = default;
    virtual void fire() const = 0;
    virtual void printWeaponName() const = 0;
};

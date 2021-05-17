#pragma once
class IWeapon
{
public:
    virtual ~IWeapon() = default;
    virtual void fire() const = 0;
    virtual void getWeaponName() const = 0;
};

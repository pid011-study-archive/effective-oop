#pragma once
#include <iostream>
#include <string>
#include "IPlayer.h"
#include "IWeapon.h"

class Job : public IPlayer
{
public:
    Job(std::string jobName, const IWeapon& defaultWeapon) : _jobName(jobName), _weapon(defaultWeapon) { }
    virtual ~Job() override = default;
    virtual void move() const = 0;
    virtual void attack() const = 0;

    const std::string& JobName() const { return _jobName; }
    const IWeapon& Weapon() const { return _weapon; }

protected:
    const IWeapon& _weapon;
    const std::string _jobName;
};

class Engineer : public Job
{
public:
    Engineer(const IWeapon& defaultWeapon) : Job("Engineer", defaultWeapon) { }

    virtual void move() const override { }
    virtual void attack() const override
    {
        _weapon.fire();
    }
};

class Assault : public Job
{
public:
    Assault(const IWeapon& defaultWeapon) : Job("Assault", defaultWeapon) { }

    virtual void move() const override { }
    virtual void attack() const override
    {
        _weapon.fire();
    }
};

class Medic : public Job
{
public:
    Medic(const IWeapon& defaultWeapon) : Job("Medic", defaultWeapon) { }

    virtual void move() const override { }
    virtual void attack() const override
    {
        _weapon.fire();
    }
};

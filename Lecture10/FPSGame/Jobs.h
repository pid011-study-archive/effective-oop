#pragma once
#include <string>
#include <utility>
#include <memory>
#include "IPlayer.h"
#include "IWeapon.h"

class Job : public IPlayer
{
public:
    explicit Job(std::string&& jobName, std::unique_ptr<IWeapon>&& defaultWeapon)
        : _weapon(std::move(defaultWeapon)), _jobName(std::move(jobName)) { }

    ~Job() override = default;
    void move() const override = 0;
    void attack() const override = 0;

    [[nodiscard]] const std::string& JobName() const { return _jobName; }
    [[nodiscard]] const IWeapon* Weapon() const { return _weapon.get(); }

protected:
    std::unique_ptr<IWeapon> _weapon;
    const std::string _jobName;
};

class Engineer final : public Job
{
public:
    explicit Engineer(std::unique_ptr<IWeapon>&& defaultWeapon) : Job("Engineer", std::move(defaultWeapon)) { }

    void move() const override { }
    void attack() const override
    {
        _weapon->fire();
    }
};

class Assault final : public Job
{
public:
    explicit Assault(std::unique_ptr<IWeapon>&& defaultWeapon) : Job("Assault", std::move(defaultWeapon)) { }

    void move() const override { }
    void attack() const override
    {
        _weapon->fire();
    }
};

class Medic final : public Job
{
public:
    explicit Medic(std::unique_ptr<IWeapon>&& defaultWeapon) : Job("Medic", std::move(defaultWeapon)) { }

    void move() const override { }
    void attack() const override
    {
        _weapon->fire();
    }
};

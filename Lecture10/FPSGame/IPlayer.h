#pragma once
class IPlayer
{
public:
    virtual ~IPlayer() = default;
    virtual void move() const = 0;
    virtual void attack() const = 0;
};

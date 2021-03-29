#pragma once
#include "Util.h"
#include "Player.h"

Player::Player(std::string raw) : _score(0)
{
    auto splited = split(raw, ';');
    _teamName = splited[0];
    _record = Record(splited[1]);
}

Player::Player(const Player& rhs)
{
    _teamName = std::string(rhs._teamName);
    _record = Record(rhs._record);
    _score = rhs._score;
}

Player& Player::operator=(const Player& rhs)
{
    _teamName = std::string(rhs._teamName);
    _record = Record(rhs._record);
    _score = rhs._score;

    return *this;
}

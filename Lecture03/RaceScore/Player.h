#pragma once
#include <string>
#include "Record.h"

class Player
{
public:
    Player(std::string raw);
    Player(const Player& rhs);
    Player& operator=(const Player& rhs);

    std::string TeamName() const { return _teamName; }
    const Record& RecordTime() const { return _record; }
    int Score() const { return _score; }

    void SetScore(int score) { _score = score; }

private:
    std::string _teamName;
    Record _record;
    int _score;
};

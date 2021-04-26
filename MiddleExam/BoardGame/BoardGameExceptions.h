#pragma once
#include <exception>
#include <stdexcept>

class game_not_started_exception : public std::exception
{
public:
    game_not_started_exception(const std::string& message) : std::exception(message.c_str()) { }
};

class index_out_of_board : public std::exception
{
public:
    index_out_of_board(const std::string& message) : std::exception(message.c_str()) { }
};

class game_end_exception : public std::exception
{
public:
    game_end_exception(const int winnerNumber) : std::exception()
    {
        _winner = winnerNumber;
    }

    int Winner() const { return _winner; }

private:
    int _winner;
};

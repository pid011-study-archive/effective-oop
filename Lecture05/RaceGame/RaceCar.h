#pragma once
#include <string>

class RaceCar
{
public:
    RaceCar(char logo, std::string name, size_t mapSize)
        : _logo(logo), _name(name), _mapSize(mapSize) { }

    void MoveFront();
    int IsFinished() const;

    void SetLineNumber(int line) { _line = line; }

    char Logo() const { return _logo; }
    std::string Name() const { return _name; }
    int Position() const { return _pos; }
    int LineNumber() const { return _line; }

private:
    char _logo;
    std::string _name;
    size_t _mapSize;
    int _line = -1;
    int _pos = 0;
};

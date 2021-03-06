#pragma once
struct Vector2
{
public:
    Vector2(int x, int y) : _x(x), _y(y) { }

    int X() const { return _x; }
    int Y() const { return _y; }

private:
    int _x;
    int _y;
};

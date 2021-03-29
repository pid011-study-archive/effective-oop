#pragma once
#include <string>

class Record
{
public:
    Record() : _min(0), _sec(0), _ms(0) { }
    Record(std::string raw);

    int Minute() const { return _min; }
    int Second() const { return _sec; }
    int Millisecond() const { return _ms; }

    void Minute(int min) { _min = min; }
    void Second(int sec) { _sec = sec; }
    void Millisecond(int ms) { _ms = ms; }

    std::string ToString() const
    {
        using std::to_string;

        return std::string()
            .append(to_string(_min))
            .append(":")
            .append(to_string(_sec))
            .append(".")
            .append(to_string(_ms));
    }

    bool operator<(const Record& c) const;

private:
    int _min, _sec, _ms;
};

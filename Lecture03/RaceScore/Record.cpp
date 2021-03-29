#include "Util.h"
#include "Record.h"

Record::Record(std::string raw)
{
    auto splited = split(raw, ':');

    _min = stoi(splited[0]);
    _sec = stoi(splited[1]);
    _ms = stoi(splited[2]);
}

bool Record::operator<(const Record& c) const
{
    // 밀리초 단위로 변경해서 비교함
    uint32_t recordA = _min * 60 + _sec * 1000 + _ms * 10;
    uint32_t recordB = c._min * 60 + c._sec * 1000 + c._ms * 10;

    return recordA < recordB;
}

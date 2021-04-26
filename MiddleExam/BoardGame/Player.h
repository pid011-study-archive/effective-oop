#pragma once
#include <vector>
#include "Card.h"
#include "BoardGameExceptions.h"

class Player
{
public:
    Player(int boardSize) : _boardSize(boardSize) { }

    // 카드를 등록하고 몇 번째 카드인지를 반환. 만약 카드가 보드 크기만큼 차면 -1 반환
    int AddCard(Card& card)
    {
        if (_cards.size() >= _boardSize) return -1;

        int idx = _cards.size();
        _cards.push_back(card);

        return idx;
    }

    const std::vector<Card>& Cards() const
    {
        return _cards;
    }

private:
    int _boardSize;
    std::vector<Card> _cards;
};

#pragma once
#include "Vector2.h"

enum class CardType
{
    CA,
    C2,
    C3,
    C4,
    C5,
    C6,
    CJ
};

class Card
{
public:
    Card(CardType cardType, char back) : _position(Vector2(0, 0)), _cardType(cardType), _back(back) { }
    Card(Vector2& pos, CardType cardType, char back) : _position(Vector2(pos.X(), pos.Y())), _cardType(cardType), _back(back) { }

    // 카드를 뒤집는다.
    void Flip() { _isBack = !_isBack; }

    // 카드의 위치
    const Vector2& Position() const { return _position; }

    // 카드의 타입
    CardType Type() const { return _cardType; }

    // 카드의 뒷면
    char Back() const { return _back; }

    bool operator>(const Card& other) const
    {
        // 만약 자신의 카드가 J고 상대방이 A면 false
        if (_cardType == CardType::CJ && other._cardType == CardType::CA) return false;

        // 만약 자신의 카드가 상대방의 카드보다 크면 true
        if (_cardType > other._cardType) return true;

        // 이도 저도 아닌 경우는 자신의 카드가 상대방의 카드보다 같거나 작은 경우이므로 false
        return false;
    }

    bool operator<(const Card& other) const { return !(*this > other); }
    bool operator==(const Card& other) const { return _cardType == other._cardType; }

private:
    Vector2 _position;
    CardType _cardType;
    char _back;
    bool _isBack = true;
};

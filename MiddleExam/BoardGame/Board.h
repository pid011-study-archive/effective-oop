#pragma once
#include <vector>
#include <memory>
#include "Player.h"
#include "BoardGameExceptions.h"

enum class Direction
{
    Front,
    Left,
    Right
};

class Board
{
public:
    const int BoardSize = 7;
    const int MaxPlayer = 2;

    // 보드를 초기화
    Board()
    {
        // 보드를 7x7에 ' '로 초기화
        for (size_t i = 0; i < BoardSize; i++)
        {
            _boardMap.push_back(std::vector<char>());
            for (size_t j = 0; j < BoardSize; j++)
            {
                _boardMap[i].push_back(' ');
            }
        }
    }

    // 보드에 플레이어 등록하고 몇번째 플레이어인지를 반환. 만약 MaxPlayer만큼 등록이 되었다면 -1 반환
    int Register(std::shared_ptr<Player>& player)
    {
        if (_players.size() >= MaxPlayer) return -1;

        // 몇 번째 플레이어인지 저장
        int idx = _players.size();

        // weak_ptr로 _players에 저장
        _players.push_back(std::weak_ptr<Player>(player));

        return idx;
    }

    // 게임을 시작합니다.
    bool StartGame()
    {
        if (_players.size() < MaxPlayer) return false;

        _isPlaying = true;

        return true;
    }

    // 지정된 플레이어의 지정된 카드를 지정한 위치로 옮깁니다.
    void Move(int playerNumber, Direction direction)
    {
        // 게임이 시작되지 않았으면
        if (!_isPlaying)
        {
            throw game_not_started_exception("게임이 시작되지 않았습니다.");
        }

        if (playerNumber < 0 || playerNumber >= _players.size())
        {
            throw std::invalid_argument("플레이어의 번호가 범위를 벗어났습니다.");
        }

        auto player = _players.at(playerNumber).lock();
        // 관련 로직 작성하기
    }

    // 보드맵
    const std::vector<std::vector<char>> Map() const { return _boardMap; }

    // 플레이어 목록
    const std::vector<std::weak_ptr<Player>> Players() const { return _players; }

private:
    bool _isPlaying = false;
    std::vector<std::vector<char>> _boardMap;
    std::vector<std::weak_ptr<Player>> _players;
};

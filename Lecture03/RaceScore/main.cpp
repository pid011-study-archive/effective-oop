#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "Player.h"

std::vector<std::string> readRecordLog(std::string filename);
bool comparePlayerByRecord(const Player& p1, const Player& p2);

int main()
{
    auto logs = readRecordLog("result.txt");

    if (logs.size() == 0)
    {
        std::cout << "플레이어 기록이 비어있습니다." << std::endl;
        return 0;
    }

    std::vector<Player> players;
    for (auto& log: logs) players.push_back(Player(log));

    std::sort(players.begin(), players.end(), comparePlayerByRecord);

    //for (auto& player: players) std::cout << player.TeamName() << " - " << player.RecordTime().ToString() << std::endl;

    std::vector<int> scoresToGive { 1, 3, 5, 10 };

    int teamScoreA = 0, teamScoreB = 0;
    for (auto& player: players)
    {
        int score = 0;
        if (!scoresToGive.empty())
        {
            score = scoresToGive.back();
            scoresToGive.pop_back();
        }

        player.SetScore(score);

        if (player.TeamName() == "A")
        {
            teamScoreA += player.Score();
        }
        else
        {
            teamScoreB += player.Score();
        }
    }

    std::string winner = teamScoreA > teamScoreB ? "A" : "B";
    std::cout << winner << " team win" << std::endl;
}

std::vector<std::string> readRecordLog(std::string filename)
{
    std::ifstream fs;
    fs.open(filename);

    std::vector<std::string> logs;

    if (fs.fail())
    {
        std::cout << "파일을 열 수 없습니다." << std::endl;
        return logs;
    }

    while (!fs.eof())
    {
        std::string line;
        std::getline(fs, line);
        logs.push_back(line);
    }

    fs.close();

    return logs;
}

bool comparePlayerByRecord(const Player& p1, const Player& p2)
{
    return p1.RecordTime() < p2.RecordTime();
}
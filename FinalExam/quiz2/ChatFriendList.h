#pragma once
#include <map>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>

class ChatFriendList
{
public:
    void addChatFriend(const std::string& userName, const std::string& friendName)
    {
        if (isChatFriend(userName, friendName))
        {
            return;
        }

        mFriendList.emplace(userName, friendName);
    }

    void removeChatFriend(const std::string& userName, const std::string& friendName)
    {
        if (!isChatFriend(userName, friendName))
        {
            return;
        }

        auto remove = std::remove(
            mFriendList.begin(),
            mFriendList.end(),
            [&](std::pair<std::string, std::string>& x) {
                return (x.first == userName) && (x.second == friendName);
            });
        mFriendList.erase(remove, mFriendList.end());
    }

    bool isChatFriend(const std::string& userName, const std::string& friendName)
    {
        auto check = [&](const std::pair<std::string, std::string>& x) {
            return x.first == userName && x.second == friendName;
        };

        return std::find_if(mFriendList.cbegin(), mFriendList.cend(), check) != mFriendList.cend();
    }

    void printChatFriend()
    {
        std::map<std::string, std::vector<std::string>> list;

        for (const auto& [k, v]: mFriendList)
        {
            list[k].push_back(v);
        }

        for (const auto& [userName, friends]: list)
        {
            std::cout << "이름 : " << userName << std::endl;
            std::cout << "\t친구 수 : " << friends.size() << std::endl;
            for (const auto& friendName: friends)
            {
                std::cout << "\t\t" << friendName << std::endl;
            }
        }
    }

private:
    std::map<std::string, std::string> mFriendList;
};

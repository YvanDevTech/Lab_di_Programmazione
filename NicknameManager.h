//
// Created by 39351 on 05/01/2024.
//

#ifndef PROJECT_CHAT_NICKNAMEMANAGER_H
#define PROJECT_CHAT_NICKNAMEMANAGER_H

#endif //PROJECT_CHAT_NICKNAMEMANAGER_H
#include <list>
#include <stdexcept>

class NicknameManager {
public:
    static std::list<std::string> usedNicks;

    static void reserveNickname(const std::string &nk);
};
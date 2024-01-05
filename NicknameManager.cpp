//
// Created by 39351 on 05/01/2024.
//
#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>

class NicknameManager {
public:
    static std::list<std::string> usedNicks;

    static void reserveNickname(const std::string &nk) {
        if (std::find(usedNicks.begin(), usedNicks.end(), nk) == usedNicks.end()) {
            usedNicks.push_back(nk);
        } else {
            throw std::invalid_argument("Nickname già in uso.");
        }
    }
};
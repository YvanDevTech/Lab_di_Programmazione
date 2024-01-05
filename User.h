//
// Created by 39351 on 01/05/2023.
//

#ifndef PROJECT_CHAT_USER_H
#define PROJECT_CHAT_USER_H
#include <string>
#include <list>
#include <utility>
#include <algorithm>
#include <iostream>
#include "Message.h"
#include "ChatRegister.h"


class User {
public:
    ~User();

    explicit User(const std::string &nk);

    User(const User &original) = default;

    User &operator=(const User &rhs) = delete;

    const std::string &getNick() const;

    bool isRegisterEmpty() const;

    void startNewChat(User &otherUser);

    void removeChat(const std::string &username);

    bool removeChat(const std::string &username);

    Chat &getChat(const User &otherUser) const;

    void sendMessage(const User &addressee, const std::string &text);

    void addChat(const User &username, const Chat &newChat);

    static const std::list<std::string> *getUsedNicks();

private:
    std::string nick;
    static std::list<std::string> usedNicks;
    ChatRegister chatRegister;

};


#endif //PROJECT_CHAT_USER_H

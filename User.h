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

    const std::string &

    getNick() const;


    bool isRegisterEmpty() const;

    bool startNewChat(User &otherUser);

    bool removeChat(const std::string &username);



    const std::shared_ptr<Chat> getChat(const User &otherUser) const;

    bool sendMessage(const User &addressee, const std::string &text);



    void addChat(const User &username, const Chat &newChat);

    static const std::vector<std::string> *getUsedNicks();

private:
    std::string nick;
    ChatRegister chatRegister;
    static std::vector<std::string> usedNicks;

};
#endif //PROJECT_CHAT_USER_H
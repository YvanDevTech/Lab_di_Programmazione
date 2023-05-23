//
// Created by 39351 on 01/05/2023.
//

#ifndef PROJECT_CHAT_CHAT_H
#define PROJECT_CHAT_CHAT_H
#include <iostream>
#include <list>
#include "Message.h"


class Chat {
public:
    Chat(std::string u1, std::string u2) : user1(std::move(u1)), user2(std::move(u2)) {};

    void addMessage(const Message &msg);

    std::_List_iterator<Message> firstUnreadMessage();

    void open();

    void deleteAll();

    void deleteMsg(int msgPos);

    const std::string &getUser1() const;

    const std::string &getUser2() const;

    const std::list<Message> *getMessages() const;

    bool findMessage(const std::string &text);

    bool operator==(const Chat &rhs) const;

    bool operator!=(const Chat &rhs) const;

private:
    std::string user1;
    std::string user2;
    std::list<Message> messages;

};


#endif //PROJECT_CHAT_CHAT_H

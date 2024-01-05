//
// Created by 39351 on 01/05/2023.
//

#ifndef PROJECT_CHAT_CHAT_H
#define PROJECT_CHAT_CHAT_H
#include <iostream>
#include <list>
#include "Message.h"
#include <vector>
#include <valarray>


class Chat {
public:
    Chat(std::string u1, std::string u2) : person1(std::move(u1)), person2(std::move(u2)) {};

    void addMessage(const Message &msg);

    auto firstUnreadMessage() const;

    //void open();

    void deleteAll();

    void deleteMsg(int msgPos);

    const std::string &getUser1() const;

    const std::string &getUser2() const;

    const std::list<Message> *getMessages() const;

    bool findMessage(const std::string &text);

    bool operator==(const Chat &rhs) const;

    bool operator!=(const Chat &rhs) const;

    void readMessage(int msgPos) const;

private:
    std::string person1;
    std::string person2;
    std::vector<Message> messages;




};


#endif //PROJECT_CHAT_CHAT_H

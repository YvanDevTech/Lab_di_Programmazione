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
#include <optional>


class Chat {
public:

    Chat(const std::string &user1, const std::string &user2);

    void addMessage(const Message &msg);

    void deleteAll();

    void deleteMsg(int msgPos);

    const std::string &getUser1() const;

    const std::string &getUser2() const;

    const std::vector<Message> *getMessages() const;

    bool findMessage(const std::string &text);

    bool operator==(const Chat &rhs) const;

    bool operator!=(const Chat &rhs) const;

    bool isMessageRead(int index) const;

    void readMessage(int msgPos, std::ostream& outputStream ) const;

    int getMessageCount() const;
    int getReadMessageCount() const;
    int getUnreadMessageCount() const;


    void markMessageAsRead(int index);

    ~Chat();
private:
    std::string person1;
    std::string person2;
    std::vector<Message> messages;
    std::vector<bool> messageReadStatus;


};
#endif //PROJECT_CHAT_CHAT_H
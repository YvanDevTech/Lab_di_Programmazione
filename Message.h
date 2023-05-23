//
// Created by 39351 on 01/05/2023.
//

#ifndef PROJECT_CHAT_MESSAGE_H
#define PROJECT_CHAT_MESSAGE_H
#include <iostream>
#include <chrono>



class Message {
public:
    Message(std::string s, std::string a, std::string t);

    const std::string &getSender() const;

    void setSender(const std::string &sender);

    const std::string &getAddressee() const;

    void setAddressee(const std::string &addressee);

    const auto &getTime() const;

    const std::string &getText() const;

    bool isRead() const;

    void setRead(bool read);

    bool isImportant() const;

    void setImportant(bool important);

    bool operator==(const Message &rhs);

    bool operator!=(const Message &rhs);


private:
    std::string sender;
    std::string addressee;
    std::string text;
    bool read{false};
    bool important{false};
    decltype(std::chrono::system_clock::now()) time;

};


#endif //PROJECT_CHAT_MESSAGE_H

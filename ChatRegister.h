//
// Created by 39351 on 01/05/2023.
//

#ifndef PROJECT_CHAT_CHATREGISTER_H
#define PROJECT_CHAT_CHATREGISTER_H
#include <map>
#include <memory>
#include "Chat.h"



class ChatRegister {
public:
    const std::shared_ptr<Chat> &addChat(const std::string &username, const Chat &newChat);

    void removeChat(const std::string &username);

    Chat &getChat(const std::string &username) const;

    void deleteAll();

    std::map<std::string, std::shared_ptr<Chat>> &getChats();

    bool isEmpty() const;

    std::map<std::string, std::shared_ptr<Chat>> chats;

};


#endif //PROJECT_CHAT_CHATREGISTER_H

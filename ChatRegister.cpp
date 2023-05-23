//
// Created by 39351 on 01/05/2023.
//

#include "ChatRegister.h"

const std::shared_ptr<Chat> &ChatRegister::addChat(const std::string &username, const Chat &newChat) {
    chats.emplace(std::make_pair(username, std::make_shared<Chat>(newChat)));
    return chats.find(username)->second;
}

void ChatRegister::removeChat(const std::string &username) {
    chats.erase(username);
}

void ChatRegister::deleteAll() {
    chats.clear();
}

std::map<std::string, std::shared_ptr<Chat>> &ChatRegister::getChats() {
    return chats;
}

Chat &ChatRegister::getChat(const std::string &username) const {
    auto it = chats.find(username);
    if (it != chats.end())
        return *it->second;
    else
        throw std::invalid_argument("Messaggio con questo user non esistente.");
}

bool ChatRegister::isEmpty() const {
    return chats.empty();
}


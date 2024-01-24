//
// Created by 39351 on 01/05/2023.
//

#include "User.h"


std::vector<std::string> User::usedNicks;

User::User(const std::string &nk) {

    nick = nk;
    usedNicks.push_back(nk);
}

const std::string &User::getNick() const {
    return nick;
}

bool User::isRegisterEmpty() const {
    return chatRegister.isEmpty();
}

bool User::startNewChat(User &otherUser) {
    Chat newChat(nick, otherUser.nick);
    auto &chatList = chatRegister.chats;
    auto &othersChatList = otherUser.chatRegister.chats;

    if (chatList.empty() || chatList.find(otherUser.nick) == chatList.end()) {
        auto chatShared = chatRegister.addChat(otherUser.nick, newChat);
        othersChatList.emplace(nick, chatShared);
        return true;  // La messaggeria è stata avviata con successo
    } else {
        return false;  // La messaggeria con questo utente esiste già
    }
}

void User::addChat(const User &otherUser, const Chat &newChat) {
    chatRegister.addChat(otherUser.nick, newChat);
}

bool User::removeChat(const std::string &username) {

    auto it = chatRegister.chats.find(username);

    if (it != chatRegister.chats.end()) {
        chatRegister.chats.erase(it);
        return true;  // La chat è stata rimossa con successo
    } else {
        return false;  // La chat con questo utente non esiste
    }
}

bool User::sendMessage(const User &addressee, const std::string &text) {

    std::shared_ptr<Chat> chat =  getChat(addressee);

    if (chat) {
        chat->addMessage(Message(nick, addressee.nick, text));
        return true;  // Il messaggio è stato inviato con successo
    } else {
        return false;  // La chat con l'utente specificato non esiste
    }
}

const std::shared_ptr<Chat> User::getChat(const User &otherUser) const {
    auto it = chatRegister.chats.find(otherUser.nick);

    if (it != chatRegister.chats.end()) {
        return it->second;  // Restituisce un puntatore alla chat trovata
    } else {
        return nullptr;  // La chat con l'utente specificato non esiste
    }
}

User::~User() {
    usedNicks.erase(std::remove(usedNicks.begin(), usedNicks.end(), nick), usedNicks.end());
}

const std::vector<std::string> *User::getUsedNicks() {
    return &usedNicks;
}
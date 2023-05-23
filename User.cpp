//
// Created by 39351 on 01/05/2023.
//

#include "User.h"

std::list<std::string> User::usedNicks;

User::User(const std::string &nk) {
    if (usedNicks.empty() || std::find(usedNicks.begin(), usedNicks.end(), nk) == usedNicks.end()) {
        nick = nk;
        usedNicks.push_back(nick);
    } else
        throw std::invalid_argument(" nickname selezionato gia esistente.");
}

const std::string &User::getNick() const {
    return nick;
}

bool User::isRegisterEmpty() const {
    return chatRegister.isEmpty();
}

void User::startNewChat(User &otherUser) {
    Chat newChat(nick, otherUser.nick);
    auto &chatList = chatRegister.getChats();
    auto &othersChatList = otherUser.chatRegister.getChats();
    if (chatList.empty() || chatList.find(otherUser.nick) == chatList.end()) {
        auto chatShared = chatRegister.addChat(otherUser.nick, newChat);
        othersChatList.emplace(nick, chatShared);
        std::cout << nick << " Nuova messaggeria iniziata " << otherUser.nick << "." << std::endl;
    } else
        throw std::invalid_argument("La messaggeria con questo user esiste gia.");
}

void User::addChat(const User &otherUser, const Chat &newChat) {
    chatRegister.addChat(otherUser.nick, newChat);
}

void User::removeChat(const std::string &username) {
    std::cout << "Messaggeria tra te e " << username << " è stata rimossa." << std::endl;
    chatRegister.removeChat(username);
}

void User::sendMessage(const User &addressee, const std::string &text) {
    auto &chat = getChat(addressee);
    chat.addMessage(Message(nick, addressee.nick, text));
    std::cout << "Il messaggio e stato aggiunto tra " << nick << " e " << addressee.nick << std::endl;
    std::cout << "    Mittente: " << nick << std::endl << "    Indirizzo: " << addressee.nick << std::endl;
    std::cout << "    Text: '" << text << "'" << std::endl;
}

Chat &User::getChat(const User &otherUser) const {
    return chatRegister.getChat(otherUser.getNick());
}

User::~User() {
    usedNicks.remove(nick);
}

const std::list<std::string> *User::getUsedNicks() {
    return &usedNicks;
}





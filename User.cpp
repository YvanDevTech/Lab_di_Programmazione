//
// Created by 39351 on 01/05/2023.
//

#include "User.h"

//std::list<std::string> User::usedNicks;
std::list<std::string> NicknameManager::usedNicks;

/*User::User(const std::string &nk) {
    if (usedNicks.empty() || std::find(usedNicks.begin(), usedNicks.end(), nk) == usedNicks.end()) {
        nick = nk;
        usedNicks.push_back(nick);
    } else
        throw std::invalid_argument(" nickname selezionato gia esistente.");
}*/
public:
    User(const std::string &nk) {
        NicknameManager::reserveNickname(nk);
        nick = nk;
    }
    const std::string &getNick() const {
        return nick;
    }
}
bool User::isRegisterEmpty() const {
    return chatRegister.isEmpty();
}

void User::startNewChat(User &otherUser) {
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

void User::removeChat(const std::string &username) {

    auto it = chatRegister.chats.find(username);

    if (it != chatRegister.chats.end()) {
        chatRegister.chats.erase(it);
        return true;  // La chat è stata rimossa con successo
    } else {
        return false;  // La chat con questo utente non esiste
    }
}

void User::sendMessage(const User &addressee, const std::string &text) {
    auto &chat = getChat(addressee);
    chat.addMessage(Message(nick, addressee.nick, text));

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

}



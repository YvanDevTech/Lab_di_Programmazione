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
    auto &chatList = chatRegister.getChats();
    auto &othersChatList = otherUser.chatRegister.getChats();
    if (chatList.empty() || chatList.find(otherUser.nick) == chatList.end()) {
        auto chatShared = chatRegister.addChat(otherUser.nick, newChat);
        othersChatList.emplace(nick, chatShared);

    } else
        throw std::invalid_argument("La messaggeria con questo user esiste gia.");
}

void User::addChat(const User &otherUser, const Chat &newChat) {
    chatRegister.addChat(otherUser.nick, newChat);
}

void User::removeChat(const std::string &username) {

    chatRegister.removeChat(username);
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



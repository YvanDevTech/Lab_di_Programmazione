//
// Created by 39351 on 01/05/2023.
//

#include "User.h"
#include "NicknameManager.h"

//std::list<std::string> User::usedNicks;
std::list<std::string> NicknameManager::usedNicks;

/*User::User(const std::string &nk) {
    if (usedNicks.empty() || std::find(usedNicks.begin(), usedNicks.end(), nk) == usedNicks.end()) {
        nick = nk;
        usedNicks.push_back(nick);
    } else
        throw std::invalid_argument(" nickname selezionato gia esistente.");
}*/

User::User(const std::string &nk) {
        NicknameManager::reserveNickname(nk);
        nick = nk;
    }
    /*const std::string &getNick()  {
        return nick;
    }*/

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
   // auto &chat = getChat(addressee);
    //chat.addMessage(Message(nick, addressee.nick, text));
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
    usedNicks.remove(nick);
}

const std::list<std::string> *User::getUsedNicks() {
    return &usedNicks;
}





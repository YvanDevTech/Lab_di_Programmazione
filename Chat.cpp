//
// Created by 39351 on 01/05/2023.
//

#include "Chat.h"


void Chat::addMessage(const Message &msg) {
    if (msg.getAddressee() != person1 && msg.getAddressee() != person2)
        throw std::invalid_argument("Messaggio non corrispondente a nessun user.");
    messages.emplace_back(msg.getSender(), msg.getAddressee(), msg.getText());
}

auto Chat::firstUnreadMessage() const -> auto {
    auto result = messages.end();
    for (auto it = messages.begin(); it != messages.end(); it++) {
        if (!it->isRead()) {
            result = it;
            break;
        }
    }
    return result;
}
/*void Chat::open() {
    std::cout << "Hai aperto una messaggeria tra " << person1 << " e " << person2 << std::endl;
    for (auto it = firstUnreadMessage(); it != messages.end(); it++) {
        it->setRead(true);
    }
}*/

void Chat::deleteAll() {
    messages.clear();
}

void Chat::deleteMsg(int msgPos) {

    if (msgPos >= messages.size() || msgPos < 0)
        throw std::out_of_range("Il messaggio selezionato non esiste.");

    messages.erase(messages.begin() + msgPos);
}

const std::string &Chat::getUser1()   const {
    return person1;
}


const std::string &Chat::getUser2() const {
    return person2;
}

void Chat::readMessage(int msgPos) const {
    if (msgPos >= messages.size() || msgPos < 0)
        throw std::out_of_range("Il messaggio selezionato non esiste.");

    auto it = messages.begin();
    std::advance(it, msgPos);

    std::cout << "Mittente: " << it->getSender() << std::endl;
    std::cout << "Testo: " << it->getText() << std::endl;
    std::cout << "Letto: " << (it->isRead() ? "Sì" : "No") << std::endl;

}

/*const std::list<Message> *Chat::getMessages() const {
    return &messages;
}*/

bool Chat::operator==(const Chat &rhs) const {
    return (rhs.person1 == person1 && rhs.person2 == person2);
}

bool Chat::operator!=(const Chat &rhs) const {
    return !(*this == rhs);
}

bool Chat::findMessage(const std::string &text) {
    bool result = false;
    for (const auto &msg : messages) {
        if (msg.getText() == text) {
            result = true;
            break;
        }
    }
    return result;
}

int Chat::getMessageCount() const {
    return messages.size();
}

int Chat::getReadMessageCount() const {
    int readCount = 0;
    for (bool readStatus : messageReadStatus) {
        if (readStatus) {
            readCount++;
        }
    }
    return readCount;
}

int Chat::getUnreadMessageCount() const {
    return getMessageCount() - getReadMessageCount();
}


void Chat::markMessageAsRead(int index) {
    if (index >= 0 && index < static_cast<int>(messageReadStatus.size())) {
        messageReadStatus[index] = true;  // Marquer le message comme lu
    }
}

bool Chat::isMessageRead(int index) const {
    if (index >= 0 && index < static_cast<int>(messageReadStatus.size())) {
        return messageReadStatus[index];
    }
    return false;  // Par défaut, considéré comme non lu si l'index est hors limites
}


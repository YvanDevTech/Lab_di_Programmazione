//
// Created by 39351 on 01/05/2023.
//

#include "Chat.h"

Chat::Chat(const std::string &user1, const std::string &user2)
        : person1(user1), person2(user2) {
    messageReadStatus.resize(0, true);
}

void Chat::addMessage(const Message &msg) {
    if (msg.getAddressee() != person1 && msg.getAddressee() != person2)
        throw std::invalid_argument("Messaggio non corrispondente a nessun user.");
    messages.emplace_back(msg.getSender(), msg.getAddressee(), msg.getText());
    messageReadStatus.push_back(false);
}

const std::vector<Message>* Chat::getMessages() const {
    return &messages;
}

void Chat::deleteAll() {
    messages.clear();
}

void Chat::deleteMsg(int msgPos) {

    if (msgPos >= messages.size() || msgPos < 0)
        throw std::out_of_range("Il messaggio selezionato non esiste.");

    messages.erase(messages.begin() + msgPos);
    messageReadStatus.erase(messageReadStatus.begin() + msgPos);
}

const std::string &Chat::getUser1()   const {
    return person1;
}


const std::string &Chat::getUser2() const {
    return person2;
}

bool Chat::isMessageRead(int index) const {
    if (index >= 0 && index < static_cast<int>(messageReadStatus.size())) {
        return messageReadStatus[index];
    }
    return false;
}

void Chat::readMessage(int msgPos, std::ostream& outputStream) const {
    if (msgPos >= messages.size() || msgPos < 0)
        throw std::out_of_range("Il messaggio selezionato non esiste.");

    auto it = messages.begin();
    std::advance(it, msgPos);
    outputStream << "Reading message from " << it->getSender() << " to " << it->getAddressee() << std::endl;
    outputStream << "Text: " << it->getText() << std::endl;


}


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
    int unreadCount = 0;
    for (size_t i = 0; i < messageReadStatus.size(); ++i) {
        if (!messageReadStatus[i]) {
            ++unreadCount;
        }
    }
    return unreadCount;
}


void Chat::markMessageAsRead(int index) {
    if (index >= 0 && index < static_cast<int>(messageReadStatus.size())) {
        messageReadStatus[index] = true;
    }
}


Chat::~Chat() {
}
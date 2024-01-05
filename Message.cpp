//
// Created by 39351 on 01/05/2023.
//

#include "Message.h"

Message::Message(const std::string &s, const std::string &a, const std::string &t) : sender(std::move(s)), addressee(std::move(a)),
                                                                text(std::move(t)) {
    time = std::chrono::system_clock::now();
}

bool Message::isRead() const {
    return read;
}

void Message::setRead(bool read) {
    Message::read = read;
}

bool Message::isImportant() const {
    return important;
}

void Message::setImportant(bool important) {
    Message::important = important;
}

bool Message::operator==(const Message &rhs) {
    return (rhs.addressee == addressee && rhs.sender == sender && rhs.text == text && rhs.time == time);
}

bool Message::operator!=(const Message &rhs) {
    return !(*this == rhs);
}

const std::string &Message::getSender() const {
    return sender;
}

void Message::setSender(const std::string &sender) {
    Message::sender = sender;
}

const std::string &Message::getAddressee() const {
    return addressee;
}

void Message::setAddressee(const std::string &addressee) {
    Message::addressee = addressee;
}

const auto &Message::getTime() const {
    return time;
}

const std::string &Message::getText() const {
    return text;
}



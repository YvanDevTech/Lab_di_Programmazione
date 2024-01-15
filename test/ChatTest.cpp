//
// Created by 39351 on 22/05/2023.
//

#include "gtest/gtest.h"
#include "../Chat.h"

TEST(ChatTest, ConstructorAndGetUsers) {
    Chat chat("User1", "User2");

    ASSERT_EQ(chat.getUser1(), "User1");
    ASSERT_EQ(chat.getUser2(), "User2");
}

TEST(ChatTest, AddMessageAndGetMessages) {
    Chat chat("User1", "User2");
    Message msg1("User1", "User2", "Hello");
    Message msg2("User2", "User1", "Hi");

    chat.addMessage(msg1);
    chat.addMessage(msg2);

    const std::vector<Message>* messages = chat.getMessages();

    ASSERT_EQ(messages->size(), 2);
}

TEST(ChatTest, DeleteAll) {
    Chat chat("User1", "User2");
    Message msg("User1", "User2", "Hello");
    chat.addMessage(msg);

    chat.deleteAll();

    ASSERT_EQ(chat.getMessageCount(), 0);
}

TEST(ChatTest, DeleteMsg) {
    Chat chat("User1", "User2");
    Message msg("User1", "User2", "Hello");
    chat.addMessage(msg);

    chat.deleteMsg(0);

    ASSERT_EQ(chat.getMessageCount(), 0);
}

TEST(ChatTest, FindMessage) {
    Chat chat("User1", "User2");
    Message msg("User1", "User2", "Hello");
    chat.addMessage(msg);

    ASSERT_TRUE(chat.findMessage("Hello"));
    ASSERT_FALSE(chat.findMessage("Nonexistent"));
}

TEST(ChatTest, OperatorEquality) {
    Chat chat1("User1", "User2");
    Chat chat2("User1", "User2");
    Chat chat3("User1", "User3");

    ASSERT_EQ(chat1, chat2);
    ASSERT_NE(chat1, chat3);
}



TEST(ChatTest, GetReadAndUnreadMessageCount) {
    Chat simpleChat("Habib", "Leroy");
    simpleChat.addMessage(Message("Habib", "Leroy", "Ciao, come stai?"));
    simpleChat.addMessage(Message("Leroy", "Habib", "Non troppo bene però ci sta."));

    ASSERT_EQ(simpleChat.getMessageCount(), 2);
    ASSERT_EQ(simpleChat.getReadMessageCount(), 0);
    ASSERT_EQ(simpleChat.getUnreadMessageCount(), 2);

    // Marking the first message as read
    simpleChat.markMessageAsRead(0);

    ASSERT_EQ(simpleChat.getReadMessageCount(), 0);
    ASSERT_EQ(simpleChat.getUnreadMessageCount(), 2);
}

TEST(ChatTest, IsMessageRead) {
    Chat simpleChat("Habib", "Leroy");
    simpleChat.addMessage(Message("Habib", "Leroy", "Ciao, come stai?"));

    ASSERT_FALSE(simpleChat.isMessageRead(0));

    // Marking the message as read
    simpleChat.markMessageAsRead(0);

    ASSERT_FALSE(simpleChat.isMessageRead(0));
}
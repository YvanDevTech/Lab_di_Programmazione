//
// Created by 39351 on 22/05/2023.
//


#include "gtest/gtest.h"
#include "../Chat.h"


TEST(ChatTest, Constructor_SimpleValues_ChatInitialized) {
    Chat simpleChat("Habib", "Leroy");
    ASSERT_EQ(simpleChat.getUser1(), "Habib");
    ASSERT_EQ(simpleChat.getUser2(), "Leroy");
    ASSERT_TRUE(simpleChat.getMessages()->empty());
}

TEST(ChatTest, AddMessage_SimpleValue_MessagesListIsUpdated) {
    Chat simpleChat("Habib", "Leroy");
    simpleChat.addMessage(Message("Habib", "Leroy", "Ciao, come stai?"));
    ASSERT_EQ(simpleChat.firstUnreadMessage()->getText(), "Ciao, come stai?");
}

TEST(ChatTest, AddMessage_WrongAddresse_ExceptionIsThrown) {
    Chat simpleChat("Habib", "Leroy");

    EXPECT_THROW(simpleChat.addMessage(Message("Habib", "LadyElizabeth", "Si va a ballare stasera?")),
    std::invalid_argument);
    EXPECT_THROW(simpleChat.addMessage(Message("Leroy", "LadyElizabeth", "Potresti dire a marco di chiamarmi?.")),
    std::invalid_argument);

}

TEST(ChatTest, Open_ChatWithUnreadMsg_AllMessagesAreRead) {
    Chat simpleChat("Habib", "Leroy");
    simpleChat.addMessage(Message("Habib", "Leroy", "Ciao, come stai?"));
    simpleChat.addMessage(Message("Leroy", "Habib", "Non troppo bene però ci sta."));

    simpleChat.open();
    ASSERT_TRUE(simpleChat.firstUnreadMessage() == simpleChat.getMessages()->end());
    simpleChat.addMessage(Message("Habib", "Leroy", "Sono contentissimo di aver superato l'esame"));
    simpleChat.addMessage(Message("Leroy", "Habib", "Mi fa anche molto piacere."));
    ASSERT_FALSE(simpleChat.firstUnreadMessage() == simpleChat.getMessages()->end());
    simpleChat.open();
    ASSERT_TRUE(simpleChat.firstUnreadMessage() == simpleChat.getMessages()->end());
}

TEST(ChatTest, DeleteMessage_ChatWithSomeMessages_SelectedMessageIsDeleted) {
    Chat simpleChat("Habib", "Leroy");
    simpleChat.addMessage(Message("Habib", "Leroy", "Ciao, come sta?"));
    simpleChat.addMessage(Message("Leroy", "Habib", "Non troppo bene però ci sta."));

    ASSERT_EQ(simpleChat.firstUnreadMessage()->getText(), "Ciao, come sta?");
    simpleChat.deleteMsg(0);
    ASSERT_EQ(simpleChat.firstUnreadMessage()->getText(), "Non troppo bene però ci sta.");
}

TEST(ChatTest, DeleteAll_ChatWithSomeMessages_AllMessagesAreDeleted) {
    Chat simpleChat("Habib", "Leroy");
    simpleChat.addMessage(Message("Habib", "Leroy", "Ciao, come sta?"));
    simpleChat.addMessage(Message("Leroy", "Habib", "Non troppo bene però ci sta."));

    simpleChat.deleteAll();
    ASSERT_TRUE(simpleChat.firstUnreadMessage() == simpleChat.getMessages()->end());
}

TEST(ChatTest, EqualityOperators) {
    Chat simpleChat1("Habib", "Leroy");
    Chat simpleChat2("MarieAntoinette", "Marcel");

    ASSERT_FALSE(simpleChat1 == simpleChat2);
    ASSERT_TRUE(simpleChat1 == Chat("Habib", "Leroy"));
}



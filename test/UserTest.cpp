//
// Created by 39351 on 22/05/2023.
//


#include "gtest/gtest.h"
#include "../User.h"



TEST(UserTest, Constructor) {
    User u1("Ama");
    ASSERT_TRUE(u1.isRegisterEmpty());
}

TEST(UserTest, Destructor_SimpleValue_NickRemovedFromUsedNicks) {
    User *u1 = new User("Frank");
    const auto nicks = User::getUsedNicks();

    ASSERT_TRUE(std::find(nicks->begin(), nicks->end(), "Frank") != nicks->end());
    delete u1;
    ASSERT_TRUE(std::find(nicks->begin(), nicks->end(), "Frank") == nicks->end());
}

TEST(UserTest, AddChat_SimpleValue_ChatIsAddedToRegister) {
    User u1("Joe");
    User u2("Sam");
    Chat c1("Joe", "Sam");

    u1.addChat(u2, c1);
}

TEST(UserTest, SendMessage_SimpleValue_MessageAddedToChat) {
    User u1("Joffrey");
    User u2("Ary");

    u1.startNewChat(u2);

    u1.sendMessage(u2, "Stasera vado a cenare fuori.");
    u2.sendMessage(u1, "Io non ce la faccio ad uscire oggi.");
    ASSERT_TRUE(u1.getChat(u2)->findMessage("Stasera vado a cenare fuori."));
    ASSERT_TRUE(u1.getChat(u2)->findMessage("Io non ce la faccio ad uscire oggi."));
    ASSERT_TRUE(u2.getChat(u1)->findMessage("Stasera vado a cenare fuori."));
    ASSERT_TRUE(u2.getChat(u1)->findMessage("Io non ce la faccio ad uscire oggi."));
}

TEST(UserTest, RemoveChat_SimpleValue_ChatRemoved) {
    User u1("Joffrey");
    User u2("Ary");

    u1.startNewChat(u2);
    u1.removeChat("Ary");

    ASSERT_EQ(u1.getChat(u2), nullptr);
}

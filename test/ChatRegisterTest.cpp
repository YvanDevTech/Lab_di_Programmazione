//
// Created by 39351 on 22/05/2023.
//

#include "gtest/gtest.h"
#include "../ChatRegister.h"


TEST(ChatRegisterTest, Constructor) {
    ChatRegister cR1;
    ASSERT_TRUE(cR1.isEmpty());
}

TEST(ChatRegisterTest, AddChat_SimpleValue_ChatAddedToRegister) {
    ChatRegister cR1;
    Chat c1("Jake", "Raymond");

    cR1.addChat("Raymond", c1);
    ASSERT_FALSE(cR1.isEmpty());
    ASSERT_THROW(cR1.getChat("Terence"), std::invalid_argument);
    ASSERT_TRUE(cR1.getChat("Raymond") == c1);
}

TEST(ChatRegisterTest, RemoveChat_SimpleValue_ChatRemovedFromRegister) {
    ChatRegister cR1;
    Chat c1("Jake", "Raymond");
    Chat c2("Amy", "Gina");
    cR1.addChat("Raymond", c1);
    cR1.addChat("Gina", c2);

    ASSERT_TRUE(cR1.getChats().size() == 2);
    cR1.removeChat("Raymond");
    ASSERT_THROW(cR1.getChat("Raymond"), std::invalid_argument);
    ASSERT_TRUE(cR1.getChats().size() == 1);
}

TEST(ChatRegisterTest, DeleteChat_SimpleValue_RegisterIsEmpty) {
    ChatRegister cR1;
    Chat c1("Jake", "Raymond");
    Chat c2("Amy", "Gina");
    cR1.addChat("Raymond", c1);
    cR1.addChat("Gina", c2);

    cR1.deleteAll();
    ASSERT_TRUE(cR1.isEmpty());
}
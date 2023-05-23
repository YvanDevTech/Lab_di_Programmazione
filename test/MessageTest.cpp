//
// Created by 39351 on 22/05/2023.
//


#include "gtest/gtest.h"
#include "../Message.h"


TEST(MessageTest, Constructor) {
    Message m1("Marcel", "Jack", "Dove si compra il biglietto per Milano?");

    ASSERT_EQ(m1.getSender(), "Marcel");
    ASSERT_EQ(m1.getAddressee(), "Jack");
    ASSERT_EQ(m1.getText(), "Dove si compra il biglietto per Milano?");
}

TEST(MessageTest, equalityOperators) {
    Message m1("Marcel", "Jack", "Dove si compra il biglietto per Milano?");
    Message m2("Jack", "Marcel", "Alla stazione centrale c'è la biglietteria");
    Message m3("Marcel", "Jack", "Dove si compra il biglietto per Milano?");
    Message m4 = m1;


    ASSERT_TRUE(m1 != m2);
    ASSERT_FALSE(m1 == m3);
    ASSERT_TRUE(m1 == m4);

}
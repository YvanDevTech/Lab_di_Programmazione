#include <iostream>
#include "User.h"
#include "Chat.h"

int main() {
    User *yvan = new User("YvanTonga");
    User *michelle = new User("MichelleStella");
    User *jordan = new User("JordanLoic");
    User *ingrid = new User("IngridJulie");



    jordan->startNewChat(*ingrid);
    std::cout << "Chat started between " << jordan->getNick() << " and " << ingrid->getNick() << std::endl;

    std::cout << jordan->getNick() << " sent a message to " << ingrid->getNick() << std::endl;
    jordan->sendMessage(*ingrid, " Che ne pensi di andare in vacanza a Londra ?");

    const std::shared_ptr<Chat> chatfromJordanIngrid = jordan->getChat(*ingrid);
    if (chatfromJordanIngrid) {
        int messageCount = chatfromJordanIngrid->getMessageCount();
        if (messageCount > 0) {
            // Esempio di lettura di un messaggio
            chatfromJordanIngrid->readMessage(0, std::cout);
        } else {
            std::cout << "La chat è vuota. Nessun messaggio da leggere." << std::endl;
        }
    } else {
        std::cout << "La chat non esiste." << std::endl;
    }

    // Ingrid risponde a Jordan
    ingrid->sendMessage(*jordan, "Si, sarebbe fantastico! Londra e una citta meravigliosa.");
    chatfromJordanIngrid->markMessageAsRead(0);
    const std::shared_ptr<Chat> updatedChatfromJordanIngrid = jordan->getChat(*ingrid);

    if (updatedChatfromJordanIngrid) {
        int totalMessages = updatedChatfromJordanIngrid->getMessageCount();
        int readMessages = updatedChatfromJordanIngrid->getReadMessageCount();
        int unreadMessages = updatedChatfromJordanIngrid->getUnreadMessageCount();

        std::cout << "Total Messages: " << totalMessages << std::endl;
        std::cout << "Read Messages: " << readMessages << std::endl;
        std::cout << "Unread Messages: " << unreadMessages << std::endl;

        // Leggi il messaggio di Ingrid nella chat aggiornata
        if (totalMessages > 0) {
            updatedChatfromJordanIngrid->readMessage(totalMessages - 1, std::cout);
        } else {
            std::cout << "La chat è vuota. Nessun messaggio da leggere." << std::endl;
        }
    } else {
        std::cout << "La chat non esiste." << std::endl;
    }


    yvan->startNewChat(*michelle);
    std::cout << "Chat started between " << yvan->getNick() << " and " << michelle->getNick() << std::endl;

    yvan->sendMessage(*michelle, " Sto pensando di visitare Firenze. Non ci sono mai stato e voglio vedere i suoi famosi monumenti.");
    std::cout << yvan->getNick() << " sent a message to " << michelle->getNick() << std::endl;

    // Verifica se ci sono messaggi nella chat prima di leggere
    const std::shared_ptr<Chat> chatfromYvan = yvan->getChat(*michelle);

    if (chatfromYvan) {
        int messageCount = chatfromYvan->getMessageCount();
        if (messageCount > 0) {
            // Esempio di lettura di un messaggio
            chatfromYvan->readMessage(0, std::cout);
        } else {
            std::cout << "La chat è vuota. Nessun messaggio da leggere." << std::endl;
        }
    } else {
        std::cout << "La chat non esiste." << std::endl;
    }
    int totalMessage = chatfromYvan->getMessageCount();
    int readMessage = chatfromYvan->getReadMessageCount();
    int unreadMessage = chatfromYvan->getUnreadMessageCount();

    std::cout << "Total Message: " << totalMessage << std::endl;
    std::cout << "Read Message: " << readMessage << std::endl;
    std::cout << "Unread Message: " << unreadMessage << std::endl;


    delete michelle;
    delete yvan;
    delete jordan;
    delete ingrid;

    return 0;
}

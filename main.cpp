#include <iostream>
#include "User.h"

int main() {
    User *yvan = new User("YvanTonga");
    User *jordan = new User("JordanLoic");
    User *michelle = new User("MichelleStella");
    User *ingrid = new User("IngridJulienne");


    yvan->startNewChat(*michelle);
    yvan->sendMessage(*michelle, " Sto pensando di visitare Firenze. Non ci sono mai stato e voglio vedere i suoi famosi monumenti.");
    michelle->sendMessage(*yvan, " Sarà una bellissima esperienza! Assicurati di visitare il Duomo e il Ponte Vecchio.");
    yvan->startNewChat(*jordan);
    yvan->sendMessage(*jordan," Sai, ho appena finito di leggere un libro davvero interessante. Ne hai letto qualcosa di recente?");
    jordan->sendMessage(*yvan, "Oh, che bello! Mi piace leggere, ma negli ultimi tempi non ho avuto molto tempo. Qual era il libro?");

    jordan->startNewChat(*michelle);
    jordan->sendMessage(*michelle," Ho avuto una giornata impegnativa al lavoro, ma ora sono a casa e sto rilassandomi un po'. Hai piani per il weekend?");
    michelle->sendMessage(*jordan, "Nulla di speciale, probabilmente passero del tempo con la mia famiglia. E tu?");

    michelle->startNewChat(*ingrid);
    michelle->sendMessage(*ingrid, "Anche io sto bene, grazie! Hai fatto qualcosa di interessante oggi?");
    ingrid->sendMessage(*michelle, "Si, sono andato al parco con il mio cane. È stato divertente!");
    michelle->removeChat("YvanTonga");
    yvan->removeChat("JordanLoic");

    delete michelle;
    delete jordan;
    delete yvan;
    delete ingrid;
}

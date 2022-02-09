//
// Created by mrgat on 2/9/2022.
//
//Testing functionality of Texas Holdem
#include "Card.h"
#include "Player.h"
#include "Holdem.h"
bool testPlayerFunction(Player&);
bool testPlayerHands(Player&);
bool testCardFunction(Card&);
bool testGameFunction(HoldemGame&);
int main() {
    HoldemGame testGame;
    Player testPlayer;
    Card testCard;

    testPlayerFunction(testPlayer);

    testPlayerHands(testPlayer);

    testCardFunction(testCard);

    testGameFunction(testGame);

    return 0;
}

bool testPlayerFunction(Player& fTestPlayer) {
    //testing getters and setters
    return true;
}

bool testPlayerHands(Player& fTestPlayer) {
    //inputting vectors with set hands to test all of the possible hands
    // in a player and checking to see if evaluateHand() works
    return true;
}

bool testCardFunction(Card& fTestCard) {

    return true;
}

bool testGameFunction(HoldemGame& fTestGame) {

    return true;
}
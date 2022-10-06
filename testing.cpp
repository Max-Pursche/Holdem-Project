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

bool testPlayerHands(Player& fTestPlayer) {
    Card test_card(2, 12);
    Card test_card2(2,9);
    Card test_card3(2, 3);
    Card test_card4(2, 4);
    Card test_card5(2, 6);
    fTestPlayer.setCard1(test_card); //ace of spades
    fTestPlayer.setCard2(test_card2); //jack of spades
    test_card.setValue(7);
    test_card.setValue(0);
    //inputting vectors with set hands to test all of the possible hands
    // in a player and checking to see if evaluateHand() works
    vector<Card> testBoard = {test_card, test_card2, test_card3, test_card4, test_card5};
//    if (fTestPlayer) {
//
//    }

    return true;
}

bool testCardFunction(Card& fTestCard) {

    return true;
}

bool testGameFunction(HoldemGame& fTestGame) {

    return true;
}
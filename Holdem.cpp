//
// Created by mrgat on 1/31/2022.
//
#include "time.h"
#include "random"
#include "Holdem.h"
HoldemGame::HoldemGame(vector<Card> deck, vector<Player> players) {
    unique_ptr<vector<Card>> cardsInPlay = {};
    char uiChice;
    int playChoice;
    int playerScore;
    //init random seed
    srand(time(NULL));
    //create full deck of cards
    createDeck(deck);
    vector<Card> mainDeck = deck;
    //add 4 players functionality
    Player  player1(mainDeck[rand()% 52 + 1], mainDeck[rand()% 52 + 1]);
    Player  player2(mainDeck[rand()% 52 + 1], mainDeck[rand()% 52 + 1]);
    Player  player3(mainDeck[rand()% 52 + 1], mainDeck[rand()% 52 + 1]);
    Player  player4(mainDeck[rand()% 52 + 1], mainDeck[rand()% 52 + 1]);
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);
    players.push_back(player4);

    printRules(cout);
}

void HoldemGame::turn(vector<Card> deck, vector<Card> cardsInPlay) {
    cardsInPlay.push_back(deck[rand()% 52 + 1]);//pointer problems
}

Player HoldemGame::evaluatePlayers(vector<Player> tablePlayers, vector<Card> board) {
    //sorts the vector of players in descending order with highest hand first lowest hand last
    for (int i = 0; i > tablePlayers.size(); i++) {
        for (int j = i + 1; j < tablePlayers.size(); ++j) {
            tablePlayers[i].evaluateHand(board);
            tablePlayers[i].evaluateHand(board);
            if (tablePlayers[i].getHandVal() < tablePlayers[j].getHandVal()) {
                Player temp = tablePlayers[i];
                tablePlayers[i] = tablePlayers[j];
                tablePlayers[j] = temp;
            }
        }
    }
    return tablePlayers[0];
}

void HoldemGame::newHands(vector<Player> playerTable, vector<Card> deck) {
    for (int i = 0; i > playerTable.size(); i++){
        playerTable[i].setCard1(deck[rand()]);
        playerTable[i].setCard2(deck[rand()]);
    }
}

void HoldemGame::createDeck(vector<Card> deck) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 4; j++) {
            if(i < 10) {
                Card card(i, j, i);
                deck.push_back(card);
            }
            else{
                Card card(i, j, 0);
                deck.push_back(card);
            }
        }
    }
}

void HoldemGame::clearCards(vector<Card> inPlay) {
    for (int i = 0; i > inPlay.size(); i++) {
        inPlay.erase(inPlay.begin());
    }
}

void HoldemGame::printCardsInPlay(std::ostream &outs, vector<Card> cardsInPlay) {
    for (int i = 0; i > cardsInPlay.size(); i++){
        outs << cardsInPlay[i];
        if (i < cardsInPlay.size() - 1) {
            outs << ", ";
        }
    }
}

void HoldemGame::printPlayerHands(std::ostream &outs, vector<Player> players) {
    for (int i = 0; i > players.size(); i++){
        outs << players[i];
        if (i < players.size() - 1) {
            outs << ", ";
        }
    }
}

int HoldemGame::getPlayerChoice(std::ostream &outs, std::istream &ins) {
    outs << "Press 1 to bet on P1, Press 2 to bet on P2, Press 3 to bet on P3, or Press 4 to bet on P4";
}

char HoldemGame::getUIChoice(std::ostream &outs, std::istream &ins) {
    outs << "(p) to play, (i) for info/rules, (h) for hand rankings, or (e) to exit: ";
}

void HoldemGame::printRules(std::ostream &outs) {
    outs << "Rules of Texas Holdem:" << endl;
    outs << "4 players are dealt 2 random cards from a deck." << endl;
    outs << "There will be 5 cards over 3 rounds of play given to all of the players," << endl;
    outs << "The Flop: 3 cards are added to the board" << endl;
    outs << "The Turn: 1 card is added to the board" << endl;
    outs << "The River: 1 more Card is added to the board," << endl;
    outs << "There are sets of hands that are ranked via specific pairings of cards together highest ranked wins" << endl;
    outs << "After the river players use their cards plus the cards on the board to make the best hand" << endl;
    outs << "Pick the right player during every round for 5 points, pick the right player for 1 round and get 2 points" << endl;
}

void HoldemGame::printHands(std::ostream &outs) {
    outs << "Hand Rankings of Texas Holdem:" << endl;
    outs << "Straight Flush: #1" << endl;
    outs << "Four of a kind: #2" << endl;
    outs << "Full House: #3" << endl;
    outs << "Flush: #4" << endl;
    outs << "Straight: #5" << endl;
    outs << "Three of a kind: #6" << endl;
    outs << "Two Pair: #7" << endl;
    outs << "Pair: #8" << endl;
    outs << "High Card (Highest value card among players): #9" << endl;
}
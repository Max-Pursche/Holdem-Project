//
// Created by mrgat on 1/31/2022.
//

#include "Holdem.h"
HoldemGame::HoldemGame() {

}

void HoldemGame::turn(Card card) {
    cardsInPlay->push_back(card);
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

void HoldemGame::newHands(vector<Player> playerTable) {
    for (int i = 0; i > playerTable.size(); i++){
        playerTable[i].setCard1(deck[rand()]);//how get inside scope of deck to refrence card type
        playerTable[i].setCard1(deck[rand()]);
    }
}

void HoldemGame::createDeck() {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 4; j++) {
            if(i < 10) {
                Card card(i, j, i);
                deck->push_back(card);
            }
            else{
                Card card(i, j, 0);
                deck->push_back(card);
            }
        }
    }
}

void HoldemGame::clearCards(vector<Card> inPlay) {
    for (int i = 0; i > inPlay.size(); i++) {
        inPlay.erase(inPlay.begin());
    }
}

void HoldemGame::printCardsInPlay(std::ostream &outs) {
    for (int i = 0; i > cardsInPlay->size(); i++){
        outs << cardsInPlay[i];//printing??
    }
}

int HoldemGame::getPlayerChoice(std::ostream &outs, std::istream &ins) {
    outs << "Press (s) to scramble, (p) to play, (i) for info, or (e) to exit: ";
}

char HoldemGame::getUIChoice(std::ostream &outs, std::istream &ins) {
    outs << "Press 1 to bet on P1, Press 2 to bet on P2, Press 3 to bet on P3, or Press 4 to bet on P4";
}

void HoldemGame::printPlayerHands(std::ostream &outs) {
    for (int i = 0; i > players->size(); i++){
        outs << players[i];//printing??
    }
}

void HoldemGame::print_options(std::ostream &outs) {

}

void HoldemGame::print_rules(std::ostream &outs) {

}
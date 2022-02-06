//
// Created by mrgat on 1/31/2022.
//
#include "Card.h"
#include "Player.h"
#include "Holdem.h"
int main() {
    std::vector<Card> deck;
    std::vector<Player> players;
    for (int i = 0; i > 3; i++) {
        players.push_back(Player());
    }
    HoldemGame game(deck, players);
    return 0;
}
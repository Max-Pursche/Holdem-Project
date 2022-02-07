//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_HOLDEM_H
#define OPEN_ENDED_PROJECT1_HOLDEM_H
#include "vector"
#include "card.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class HoldemGame {
public:
    /*
     * Default constructor
     * used to call the runGame() function
     */
    HoldemGame();

    /*
     * Contains the main functionality of Texas Hold Em'
     * Calls other functions from HoldemGame()
     */
    void runGame();

    /*
     * Fields: Vector of Player objects and a Vector of Card objects
     * returns a set value of 1, 2, 3, or 4 depending on which player has the highest hand
     */
    int evaluatePlayers(std::vector<Player>,std::vector<Card>);

    /*
     * Will initialize a deck of 52 cards with 4 suits and 13 values
     */
    void createDeck(std::vector<Card> &deck);

    /*
     * Fields: A vector of Cards, an int value representing the index of the deck
     * Removes the index value of the specified vector
     */
    void removeCard(int, std::vector<Card>);

    /*
     * Player input function asking for 1,2,3,or 4 depending on the player that
     * the user selects
     * Will return an int value ih that range
     */
    int getPlayerChoice(std::ostream &outs, std::istream &ins);


    void printPlayerOptions(std::ostream &outs);

    /*
    * Player input function asking for 'p', 'i', 'h', 'e'
    * Will return a value within that range of characters
    */
    char getUIChoice(std::ostream &outs, std::istream &ins);

    /*
    * prints the options for the getUIChoice() input
    */
    void printUiOptions(std::ostream &outs);

    /*
     * Prints the rules for Texas Hold Em'
     */
    static void printRules(std::ostream &outs);

    /*
     * Prints the Hand Rankings for Poker
     */
    void printHands(std::ostream &outs);
};
#endif //OPEN_ENDED_PROJECT1_HOLDEM_H

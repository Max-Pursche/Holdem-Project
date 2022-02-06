//
// Created by mrgat on 1/31/2022.
//
#include "time.h"
#include "random"
#include "Holdem.h"

HoldemGame::HoldemGame(vector<Card> deck, vector<Player> players) {
    vector<Card> cardsInPlay;
    char uiChoice = 'p';
    int playChoice;
    int playerScore = 0;
    //init random seed
    srand(time(NULL));
    //create full deck of cards
    createDeck(deck);
    while (uiChoice != 'e') {
        vector<Card> mainDeck = deck;
        //setting aspects of players
        //card 1
        for (int i = 0; i < players.size(); i++) {
            int randGen = rand() % mainDeck.size() + 1;
            players[i].setCard1(mainDeck[randGen]);
            removeCard(randGen, mainDeck);
        }
        //card 2
        for (int i = 0; i < players.size(); i++) {
            int randGen = rand() % mainDeck.size() + 1;
            players[i].setCard2(mainDeck[randGen]);
            removeCard(randGen, mainDeck);
        }
        //Names for printing
        for (int i = 0; i < players.size(); i++) {
            players[i].setName("Player" + to_string(i));
        }
        printRules(cout);
        uiChoice = getUIChoice(cout, cin);
        switch (uiChoice) {
            //main game
            case 'p':
                printPlayerHands(cout, players);
                printPlayerOptions(cout);
                playChoice = getPlayerChoice(cout, cin);
                for (int i = 0; i < 2; i++){
                    turn(mainDeck, cardsInPlay);
                }
                printCardsInPlay(cout, cardsInPlay);
                printPlayerHands(cout, players);
                cout << "The Turn" << endl;
                turn(mainDeck, cardsInPlay);
                printCardsInPlay(cout, cardsInPlay);
                cout << "The River" << endl;
                turn(mainDeck, cardsInPlay);
                printCardsInPlay(cout, cardsInPlay);
                if (playChoice == evaluatePlayers(players, cardsInPlay)) {
                    playerScore += 5;
                    cout << "You guessed right!\n+5 points\nYour Score:" << to_string(playerScore) << endl;
                }
                else if (playChoice == evaluatePlayers(players, cardsInPlay) - 1){
                    playerScore += 2;
                    cout << "You had the right idea... RIP\n+2 points\nYour Score:" << to_string(playerScore) << endl;
                }
                else {
                    cout << "nice try, time to touch up your hand range sense!\n-2 points\nYour Score:" << to_string(playerScore) << endl;
                }
            case 'i':
                printRules(cout);
                break;
            case 'h':
                printHands(cout);
                break;
        }
    }
}

void HoldemGame::turn(vector<Card> deck, vector<Card> cardsInPlay) {
    //gotta fix rand
    int randGen = rand()% deck.size() + 1;
    cardsInPlay.push_back(deck[randGen]);
    removeCard(randGen, deck);
}

int HoldemGame::evaluatePlayers(vector<Player> tablePlayers, vector<Card> board) {
    //sorts the vector of players in descending order with highest hand first lowest hand last
    for (int i = 0; i > tablePlayers.size(); i++) {
        for (int j = i + 1; j < tablePlayers.size(); ++j) {
            tablePlayers[i].evaluateHand(board);
            tablePlayers[j].evaluateHand(board);
            if (tablePlayers[i].getHandVal() < tablePlayers[j].getHandVal()) {
                Player temp = tablePlayers[i];
                tablePlayers[i] = tablePlayers[j];
                tablePlayers[j] = temp;
            }
            //need a bubble sort else if statement for if the hands are equal and the value of the card needs to be compared
        }
    }
    //if statement depending on which player was chosen 1 2 3 or 4 depending on the player
    return tablePlayers[0];//fixing
}

void HoldemGame::newHands(vector<Player> playerTable, vector<Card> deck) {
    for (int i = 0; i > playerTable.size(); i++){
        //generate int = rand() % deck.size + 1
        playerTable[i].setCard1(deck[rand()]);
        playerTable[i].setCard2(deck[rand()]);
        //remove from deck
    }
}

void HoldemGame::createDeck(vector<Card> deck) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 4; j++) {
            //if card has a face value instead of number value
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

//too complicated
void HoldemGame::removeCard(int index1, vector<Card> deck){
    //loop through vector of cards with index value from random generation
    for(int i=0; i < deck.size();i++) {
        //if the index value of the loop is equal to the index value generated
        if(i == index1) {
            //remove the card from the deck at the index value
            deck.erase(deck.begin() + i);
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
    int choice;
    printPlayerOptions(outs);
    ins >> choice;
    while (choice != 1 && choice !=  2 && choice != 3 && choice != 4) {
        outs << endl << "Invalid option. " << endl;
        printPlayerOptions(outs);
        ins >> choice;
    }
    return choice;
}

char HoldemGame::getUIChoice(std::ostream &outs, std::istream &ins) {
    char choice;
    printUiOptions(outs);
    ins >> choice;
    while (choice != 's' && choice !=  'p' && choice != 'i' && choice != 'e') {
        outs << endl << "Invalid option. " << endl;
        printUiOptions(outs);
        ins >> choice;
    }
    return choice;
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

void HoldemGame::printPlayerOptions(std::ostream &outs) {
    outs << "Press 1 to bet on P1, Press 2 to bet on P2, Press 3 to bet on P3, or Press 4 to bet on P4";
}

void  HoldemGame::printUiOptions(std::ostream &outs) {
    outs << "(p) to play, (i) for info/rules, (h) for hand rankings, or (e) to exit: ";
}
//
// Created by mrgat on 1/31/2022.
//
#include "time.h"
#include "random"
#include "Holdem.h"

HoldemGame::HoldemGame() {
}

void HoldemGame::runGame() {
    std::vector<Player> players;
    std::vector<Card> cardsInPlay;
    std::vector<Card> deck;
    char uiChoice = 'p';
    int playChoice = 0;
    int playerScore = 0;
    int evaluation = 0;
    int randGen;
    //init random seed
    srand(time(NULL));
    //init players
    for (int i = 1; i < 5; i++) {
        Player player;
        players.push_back(Player());
    }
    //create full deck of cards
    createDeck(deck);
    printRules(cout);
    while (uiChoice != 'e') {
        //init main deck
        std::vector<Card> mainDeck = deck;
        cardsInPlay = {};
        //setting aspects of players
        //card 1
        for (int i = 0; i < players.size(); i++) {
            int randInt = rand() % mainDeck.size() + 1;
            players[i].setCard1(mainDeck[randInt]);
            removeCard(randInt, mainDeck);
        }
        //card 2
        for (int i = 0; i < players.size(); i++) {
            int randInt = rand() % mainDeck.size() + 1;
            players[i].setCard2(mainDeck[randInt]);
            removeCard(randInt, mainDeck);
        }
        //Names for printing
        for (int i = 1; i < players.size()+ 1; i++) {
            players[i - 1].setName("Player " + to_string(i));
        }
        //opening loop for game
        uiChoice = getUIChoice(cout, cin);
        switch (uiChoice) {
            //main game
            case 'p':
                //printing players hands
                for (int i = 0; i < players.size(); i++) {
                    cout << players[i].getName() << "'s hand: " << players[i].getCard1() << " ," << players[i].getCard2() << endl;
                }
                //getting player choice
                playChoice = getPlayerChoice(cout, cin);

                //first three cards
                for (int i = 0; i < 3; i++) {
                    int randInt = rand()% deck.size() + 1;
                    cardsInPlay.push_back(mainDeck[randInt]);
                    removeCard(randInt, mainDeck);
                }
                //Printing
                cout << "The Flop" << endl;
                for (int i = 0; i < cardsInPlay.size(); i++) {
                    cout << cardsInPlay[i] << endl;
                }

                //turn portion: eventually will score players
                cout << "The Turn" << endl;
                randGen = rand()% deck.size() + 1;
                cout << mainDeck[randGen] << endl;
                cardsInPlay.push_back(deck[randGen]);
                removeCard(randGen, deck);

                //river portion: eventually will score players
                cout << "The River" << endl;
                randGen = rand()% deck.size() + 1;
                cout << mainDeck[randGen] << endl;
                cardsInPlay.push_back(deck[randGen]);
                removeCard(randGen, deck);

                evaluation = evaluatePlayers(players, cardsInPlay);
                //Checking if Player Choice is equal to the evaluation of the players
                if (playChoice == evaluation) {
                    playerScore += 5;
                    cout << "You guessed right!\n+5 points\nYour Score:" << to_string(playerScore) << endl;
                }
                else if (playChoice == 2) {
                    //(evaluation - 1)
                    playerScore += 2;
                    cout << "You had the right idea..\n+2 points\nYour Score:" << to_string(playerScore) << endl;
                }
                else if(playerScore != 0) {
                    cout << "nice try, time to touch up your hand range sense!\n-2 points\nYour Score:" << to_string(playerScore) << endl;
                }
                else {
                    cout << "Only place from the bottom is up!\nYour Score:" << to_string(playerScore) << endl;
                }
                break;
            case 'i':
                printRules(cout);
                break;
            case 'h':
                printHands(cout);
                break;
            case 'e':
                cout << "Goodbye, your final score was: " << to_string(playerScore) << endl;
                break;
        }
    }
}

int HoldemGame::evaluatePlayers(vector<Player> tablePlayers, vector<Card> board) {
    //sorts the vector of players in descending order with highest hand first lowest hand last
    for (int i = 0; i < tablePlayers.size(); i++) {
        for (int j = i + 1; j < tablePlayers.size(); ++j) {
            tablePlayers[i].evaluateHand(board);
            tablePlayers[j].evaluateHand(board);
            if (tablePlayers[i].getHandVal() < tablePlayers[j].getHandVal()) {
                Player temp = tablePlayers[i];
                tablePlayers[i] = tablePlayers[j];
                tablePlayers[j] = temp;
            }
            //need a bubble sort else if statement for if the hands are equal and the value of the card needs to be compared aka look for high card
//            else if (tablePlayers[i].getHandVal() == tablePlayers[j].getHandVal()) {
//                if (tablePlayers[i].getCard1() < tablePlayers[j].getCard1() && tablePlayers[i].getCard1() < tablePlayers[j].getCard1()) {
//
//                }
//
//            }
        }
    }
    //if statement depending on which player won, returning 1 2 3 or 4 depending on the player
    if (tablePlayers[0].getName() == "Player1" ){
        return 1;
    }
    else if (tablePlayers[0].getName() == "Player2" ) {
        return 2;
    }
    else if (tablePlayers[0].getName() == "Player3" ) {
        return 3;
    }
    else if (tablePlayers[0].getName() == "Player4" ) {
        return 4;
    }
}

void HoldemGame::createDeck(vector<Card> &deck) {
    Card card;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            //if card has a face value instead of number value
            card.setValue(j);
            card.setSuitVal(i);
            deck.push_back(card);
        }
    }
}

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
    while (choice != 'p' && choice !=  'i' && choice != 'h' && choice != 'e') {
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
    outs << "Press (1) to bet on P1. Press (2) to bet on P2. Press (3) to bet on P3. or Press (4) to bet on P4: ";
}

void  HoldemGame::printUiOptions(std::ostream &outs) {
    outs << "(p) to play, (i) for info/rules, (h) for hand rankings, or (e) to exit: ";
}
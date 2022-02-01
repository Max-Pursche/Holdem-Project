//
// Created by mrgat on 1/31/2022.
//

#include "Player.h"
#include "Card.h"

Player::Player(Card crd1, Card crd2) {
    card1 = crd1;
    card2 = crd2;
}

Card Player::getCard1() const {
    return card1;
}

Card Player::getCard2() const {
    return card2;
}

int Player::getHandVal() const {
    return handVal;
}

void Player::setCard1(Card crd) {
    card1 = crd;
}

void Player::setCard2(Card crd) {
    card2 = crd;
}

void Player::setHandVal(int value) {
    handVal = value;
}

//void sort( face_values& values ) // ascending
//{
//    for( std::size_t i = 0 ; i < NCARDS ; ++i )
//        for( std::size_t j = i+1 ; j < NCARDS ; ++j )
//            if( values[i] > values[j] )
//            {
//                int temp = values[i] ;
//                values[i] = values[j] ;
//                values[j] = temp ;
//            }
//}
void Player::Sort(vector<Card> hand) { // ascending
    for( size_t i = 0 ; i < hand.size(); ++i ) {
        for (size_t j = i + 1; j < hand.size(); ++j) {
            if (hand[i].getValue() > hand[j].getValue()) { //need to overload card operators for >,<,= function
                Card temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

//straight flush is the highest hand I am going to add for now, maybe royal if I can finish this before sunday
void Player::evaluateHand(vector<Card> board) {
    //loop through the board to make a hand which will be set to a hand value,
    //want to make this organised from lowest to highest value for easier looping in isStraight
    vector<Card> fullHand;
    fullHand.push_back(card1);
    fullHand.push_back(card2);
    for (int i = 0; i < board.size(); i++){
        fullHand.push_back(board[i]);
    }
    //sorting into ascending order
    Sort(fullHand);
    //checking and setting hand values
    if (isStraightFlush(fullHand)){
        setHandVal(9);
    }
    else if (isPairTripQuad(fullHand) == 1) {
        setHandVal(8);
    }
    else if (isPairTripQuad(fullHand) == 2){
        setHandVal(7);
    }
    else if (isFlush(fullHand)){
        setHandVal(6);
    }
    else if (isStraight(fullHand)){
        setHandVal(5);
    }
    else if (isPairTripQuad(fullHand) == 3){
        setHandVal(4);
    }
    else if (isPairTripQuad(fullHand) == 4){
        setHandVal(3);
    }
    else if (isPairTripQuad(fullHand) == 5){
        setHandVal(2);
    }
    else{
        setHandVal(1);
    }

}

bool Player::isFlush(vector<Card> hand) {
    int flushCrit = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].getSuit() == hand[i+1].getSuit()){
            flushCrit++;
        }
    }
    if (flushCrit == 5){
        return true;
    }
    else{
        return false;
    }
}

bool Player::isStraight(vector<Card> hand) {
    //fill vector with false booleans that is the size of the hand
    vector<bool> chainOrdering[hand.size()];
    for (int i = 0; i < hand.size(); i++) {
        chainOrdering->push_back(false);
    }
    //looping through a sorted list of cards in ascending int value 2 - 14(Ace)

}

//checks for both true booleans for
bool Player::isStraightFlush(vector<Card> hand) {
    //checks boolean values of isStraight and isFlush
    return isStraight(hand) && isFlush(hand);
}

//unsure if needed
bool Player::isFullHouse(vector<Card> hand) {
    //if pair + threeOfKind return true
    //else return false
    if (isPairTripQuad(hand) == 2){
        return true;
    }
    else return false;
}

int Player::isPairTripQuad(vector<Card> hand) {
    //boolean values for the possible hand combinations
    bool pair = false;
    bool twoPair = false;
    bool threeOfKind = false;
    bool fourOfKind = false;
    //Looping through the hand to check for occurrences of the same card
    int occurrences;

    //returns the level of hand, 1 being highest and 5 being the lowest with 6 being if no hand was made
    if (fourOfKind) {
        return 1;
    }
    else if (pair && threeOfKind) {
        //full house
        return 2;
    }
    else if (threeOfKind) {
        return 3;
    }
    else if (twoPair) {
        return 4;
    }
    else if (pair) {
        return 5;
    }
    else {
        //if none are true then 6 is the value that none of them are set to true
        return 6;
    }
}


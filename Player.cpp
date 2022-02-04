//
// Created by mrgat on 1/31/2022.
//

#include "Player.h"

Player::Player(Card crd1, Card crd2) {
    hand.card1 = crd1;
    hand.card2 = crd2;
}

Card Player::getCard1() const {
    return hand.card1;
}

Card Player::getCard2() const {
    return hand.card2;
}

int Player::getHandVal() const {
    return hand.handVal;
}

Hand Player::getHand() const{
    return hand;
}

void Player::setCard1(Card crd) {
    hand.card1 = crd;
}

void Player::setCard2(Card crd) {
    hand.card2 = crd;
}

void Player::setHandVal(int value) {
    hand.handVal = value;
}

//void setHand(Card crd1, Card crd2, int value){
//
//}

// sorts a vector in ascending order
void Player::BubbleSort(vector<Card> hand) {
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
void Player::evaluateHand(const vector<Card>& board) {
    //loop through the board to make a hand which will be set to a hand value,
    //want to make this organised from lowest to highest value for easier looping in isStraight
    vector<Card> fullHand;
    fullHand.push_back(hand.card1);
    fullHand.push_back(hand.card2);
    for (auto & i : board) {
        fullHand.push_back(i);
    }
    //sorting into ascending order 2 - 14
    BubbleSort(fullHand);
    //checking and setting hand values
    if (isStraightFlush(fullHand)){
        setHandVal(10);
    }
    else if (isPairTripQuad(fullHand) == 1) {
        setHandVal(9);
    }
    else if (isQuads(fullHand)) {
        setHandVal(8);
    }
    else if (isFullHouse(fullHand)) {
        setHandVal(7);
    }
    else if (isFlush(fullHand)){
        setHandVal(6);
    }
    else if (isStraight(fullHand)){
        setHandVal(5);
    }
    else if (isTrips(fullHand)){
        setHandVal(4);
    }
    else if (isTwoPair(fullHand)){
        setHandVal(3);
    }
    else if (isPair(fullHand)){
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
    int ordering;
    //looping through a sorted list of cards in ascending int value 2 - 14(Ace)
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i+1].getValue() == hand[i].getValue() + 1) {
            ordering++;
        }
        if (ordering == 5){
            return true;
        }
    }
    return false;
}

//checks for both true booleans for
bool Player::isStraightFlush(const vector<Card>& hand) {
    //checks boolean values of isStraight and isFlush
    return isStraight(hand) && isFlush(hand);
}

bool Player::isPair(vector<Card> hand) {
    int occurrences = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i+1].getValue() == hand[i].getValue()) {
            occurrences++;
        }
        if (occurrences == 1){
            return true;
        }
    }
    return false;
}

bool Player::isTwoPair(vector<Card> hand) {
    int occurrences = 0;
    for (int i = 0; i < hand.size(); i++) {
        int pair1 = -1;
        if ((hand[i+1].getValue() == hand[i].getValue()) && (hand[i].getValue() != pair1)) {
            pair1 = hand[i].getValue();
            occurrences++;
        }
        if (occurrences == 2){
            return true;
        }
    }
    return false;
}

bool Player::isTrips(vector<Card> hand){
    int occurrences = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i+1].getValue() == hand[i].getValue()) {
            occurrences++;
        }
        if (occurrences == 2){
            return true;
        }
    }
    return false;
}

bool Player::isFullHouse(const vector<Card>& hand) {
    return isPair(hand) && isTrips(hand);
}

bool Player::isQuads(vector<Card> hand) {
    int occurrences = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i+1].getValue() == hand[i].getValue()) {
            occurrences++;
        }
        if (occurrences == 3){
            return true;
        }
    }
    return false;
}
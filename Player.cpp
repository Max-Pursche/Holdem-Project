//
// Created by mrgat on 1/31/2022.
//

#include "Player.h"
Player::Player() {
    setName("default");
}

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

string Player::getName() const {
    return name;
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

void Player::setName(string nme) {
    name = nme;
}

void Player::setHandVal(HandValue value) {
    hand.handVal = value;
}

//we are changing this max... we cant go on like this
vector<Card> Player::BubbleSort(vector<Card> handCrds) {
    for( int i = 0 ; i < handCrds.size(); ++i ) {
        for (int j = i + 1; j < handCrds.size(); ++j) {
            if (handCrds[i].getValue() > handCrds[j].getValue()) {
                Card temp = handCrds[i];
                handCrds[i] = handCrds[j];
                handCrds[j] = temp;
            }
        }
    }
    return handCrds;
}

//straight flush is the highest hand I am going to add for now, maybe royal if I can finish this before sunday
void Player::evaluateHand(vector<Card>& board) {
    //loop through the board to make a hand which will be set to a hand value,
    //want to make this organised from lowest to highest value for easier looping in isStraight
    vector<Card> fullHand;
    board.push_back(hand.card1);
    board.push_back(hand.card2);
    //sorting into ascending order 0 - 12
    fullHand = BubbleSort(board);
    //checking and setting hand values
    //Consider using a switch statement
    if (isStraightFlush(fullHand)){
        setHandVal(STRAIGHTFLUSH);
    }
    else if (isQuads(fullHand)) {
        setHandVal(FOUROFKIND);
    }
    else if (isFullHouse(fullHand)) {
        setHandVal(FULLHOUSE);
    }
    else if (isFlush(fullHand)){
        setHandVal(FLUSH);
    }
    else if (isStraight(fullHand)){
        //need to save the value of the higher straight****
        setHandVal(STRAIGHT);
    }
    else if (isTrips(fullHand)){
        setHandVal(THREEOFKIND);
    }
    else if (isTwoPair(fullHand)){
        setHandVal(TWOPAIR);
    }
    else if (isPair(fullHand)){
        setHandVal(PAIR);
    }
    else{
        setHandVal(HIGH);
    }
}

bool Player::isFlush(vector<Card>& hand) {
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

bool Player::isStraight(vector<Card>& hand) {
    //Straight value implementation
    int ordering = 0;
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

//checks for both true booleans
bool Player::isStraightFlush( vector<Card>& hand) {
    //checks boolean values of isStraight and isFlush
    return isStraight(hand) && isFlush(hand);
}

bool Player::isPair(vector<Card>& hand) {
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

bool Player::isTwoPair(vector<Card>& hand) {
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

bool Player::isTrips(vector<Card>& hand){
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

bool Player::isFullHouse(vector<Card>& hand) {
    return isPair(hand) && isTrips(hand);
}

bool Player::isQuads(vector<Card>& hand) {
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

std::ostream& operator << (std::ostream& outs, const Player& player) {
    outs << player.getName() << "'s hand:" << player.getCard1() << " , " << player.getCard2() << endl;
}

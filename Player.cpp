//
// Created by mrgat on 1/31/2022.
//

#include "Player.h"
#include "Card.h"


Player::Player(Card crd1, Card crd2) {
    card1 = crd1;
    card2 = crd2;
}

Card Player::getCard1() {
    return card1;
}

Card Player::getCard2() {
    return card2;
}

int Player::getHandVal() {
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

void Player::evaluateHand(vector<Card> board) {
    //loop through the board to make a hand which will be set to a hand value
    vector<Card> fullHand;
    fullHand.push_back(card1);
    fullHand.push_back(card2);
    for (int i = 0; i < board.size(); i++){
        fullHand.push_back(board[i]);
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
    //fill vector with false booleans
    vector<bool> chainOrdering[hand.size()];
    for (int i = 0; i < hand.size(); i++) {
        chainOrdering->push_back(false);
    }


}

bool Player::isStraightFlush(vector<Card> hand) {
    return isStraight(hand) && isFlush(hand);
}

bool Player::isFullHouse(vector<Card>) {
    //if pair + threeOfKind return true
    //else return false
}

int Player::isPairTripQuad(vector<Card> hand) {
    bool pair = false;
    bool twoPair = false;
    bool threeOfKind = false;
    bool fourOfKind = false;


}


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


}
//
// Created by mrgat on 1/31/2022.
//

#include "Card.h"

Card::Card(int intVal, int suit, int face) {
    value = intVal;
    suitVal = Suit(suit);
    faceVal = Face(face);
}

Face Card::getFace() {
    return faceVal;
}

Suit Card::getSuit() {
    return suitVal;
}

int Card::getValue() {
    return value;
}

void Card::setFaceVal(int intVal) {
    faceVal = Face(intVal);
}

void Card::setSuitVal(int intVal) {
    suitVal = Suit(intVal);
}

void Card::setValue(int intVal) {
    value = intVal;
}
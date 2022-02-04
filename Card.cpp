//
// Created by mrgat on 1/31/2022.
//

#include "Card.h"

Card::Card(int intVal, int suit, int face) {
    value = intVal;
    suitVal = Suit(suit);
    faceVal = Face(face);
}

Face Card::getFace() const {
    return faceVal;
}

Suit Card::getSuit() const {
    return suitVal;
}

int Card::getValue() const  {
    return value;
}

void Card::setFaceVal(int intVal) {
    faceVal = Face(intVal);
    setValue(Face(intVal));
}

void Card::setSuitVal(int intVal) {
    suitVal = Suit(intVal);
}

void Card::setValue(int intVal) {
    value = intVal;
}

bool operator >= (const Card& lhs, const Card& rhs) {
    return lhs.getValue() >= rhs.getValue();
}
bool operator <= (const Card& lhs, const Card& rhs) {
    return lhs.getValue() <= rhs.getValue();
}

bool operator > (const Card& lhs, const Card& rhs) {
    return lhs.getValue() >= rhs.getValue();
}

bool operator < (const Card& lhs, const Card& rhs) {
    return lhs.getValue() < rhs.getValue();
}
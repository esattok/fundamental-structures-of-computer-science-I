// Author: Esad Ismail Tok
// Student ID: 21801679

#include <iostream>
#include <string>
#include "Seat.h"
using namespace std;

// Constructors
Seat::Seat() {
    isAvailable = true;
}

Seat::Seat(const bool value) {
    isAvailable = value;
}

// Destructor
Seat::~Seat() {
    // Empty destructor since there is no dynamically allocated data member.
}

// Accessors
bool Seat::getIsAvailable() const {
    return isAvailable;
}

// Mutators
void Seat::setIsAvailable(const bool value) {
    isAvailable = value;
}

// Assignment operator
Seat& Seat::operator=(const Seat& right) {
    if (&right != this) {
        isAvailable = right.isAvailable;
    }

    return *this;
}

// Friend functions
ostream& operator<<(ostream& out, const Seat& seat) {
    if (seat.getIsAvailable()) {
        out << "o";
    }

    else {
        out << "x";
    }

    return out;
}
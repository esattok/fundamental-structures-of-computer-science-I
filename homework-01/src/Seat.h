// Author: Esad Ismail Tok
// Student ID: 21801679

#ifndef __SEAT_H
#define __SEAT_H

#include <iostream>
#include <string>
using namespace std;

class Seat {
public:
    // Constructors
    Seat();
    Seat(const bool);

    // Destructor
    ~Seat();

    // Accessors
    bool getIsAvailable() const;

    // Mutators
    void setIsAvailable(const bool);

    // Operators
    Seat& operator=(const Seat&);



private:
    bool isAvailable;

// Friend Functions
friend ostream& operator<<(ostream&, const Seat&);
};

#endif
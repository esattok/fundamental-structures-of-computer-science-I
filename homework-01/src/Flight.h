// Author: Esad Ismail Tok
// Student ID: 21801679

#ifndef __FLIGHT_H
#define __FLIGHT_H

#include <iostream>
#include <string>
#include "Seat.h"
using namespace std;

class Flight {
public:
    // Constructors
    Flight();
    Flight(const int, const int, const int);

    // Destructor
    ~Flight();

    // Accessors
    int getFlightNo() const;
    int getNumOfRows() const;
    int getNumOfSeatsPerRow() const;
    int getTotalSeatNumber() const;
    int getNumOfAvailableSeats() const;
    void showSeatingPlan() const;
    Seat** getListOfSeats() const;

    // Mutators
    void setFlightNo(const int);
    void setNumOfRows(const int);
    void setNumOfSeatsPerRow(const int);
    void setNumOfAvailableSeats();
    void setListOfSeats();

    // Operators
    Flight& operator=(const Flight&);

private:
    int flightNo;
    int numOfRows;
    int numOfSeatsPerRow;
    int numOfAvailableSeats;
    Seat** listOfSeats; // 2D array of the seating plan

// Friend Functions
friend ostream& operator<<(ostream&, const Flight&);
};

#endif
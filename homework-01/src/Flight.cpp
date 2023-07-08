// Author: Esad Ismail Tok
// Student ID: 21801679

#include <iostream>
#include <string>
#include "Flight.h"
using namespace std;


// Constructors
Flight::Flight() {
    flightNo = 0;
    numOfRows = 0;
    numOfSeatsPerRow = 0;
    numOfAvailableSeats = 0;

    // Since the row and column number is 0 for the default construction, the size of the array is 0
    listOfSeats = NULL;
}

Flight::Flight(const int flightNo, const int rowNo, const int seatNo) {
    this->flightNo = flightNo;
    numOfRows = rowNo;
    numOfSeatsPerRow = seatNo;

    // Generating the 2D array of seating plan
    listOfSeats = new Seat*[numOfRows];
    for (int i = 0; i < numOfRows; i++) {
        listOfSeats[i] = new Seat[numOfSeatsPerRow];
    }

    setNumOfAvailableSeats();
}

// Destructor
Flight::~Flight() {
    if (listOfSeats) {
        for (int i = 0; i < numOfRows; i++) {
            delete [] listOfSeats[i];
        }
        delete [] listOfSeats;
    }
}

// Accessors
int Flight::getFlightNo() const {
    return flightNo;
}

int Flight::getNumOfRows() const {
    return numOfRows;
}

int Flight::getNumOfSeatsPerRow() const {
    return numOfSeatsPerRow;
}

int Flight::getTotalSeatNumber() const {
    return (numOfRows * numOfSeatsPerRow);
}

int Flight::getNumOfAvailableSeats() const {
    return numOfAvailableSeats;
}

void Flight::showSeatingPlan() const {
    int start = 65;
    int end = start + numOfSeatsPerRow;

    for (int i = start; i < end; i++) {
        if (i == start) {
            cout << " ";
        }
        cout << " " << (char)i;
    }
    cout << endl;

    for (int i = 0; i < numOfRows; i++) {
        cout << i + 1;
        for (int j = 0; j < numOfSeatsPerRow; j++) {
            cout << " " << listOfSeats[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

Seat** Flight::getListOfSeats() const {
    return listOfSeats;
}

// Mutators
void Flight::setFlightNo(const int no) {
    flightNo = no;
}

void Flight::setNumOfRows(const int rowNo) {
    numOfRows = rowNo;
}

void Flight::setNumOfSeatsPerRow(const int seatNo) {
    numOfSeatsPerRow = seatNo;
}

void Flight::setNumOfAvailableSeats() {
    numOfAvailableSeats = 0;

    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfSeatsPerRow; j++) {
            if (listOfSeats[i][j].getIsAvailable() == true) {
                numOfAvailableSeats++;
            }
        }
    }
}

void Flight::setListOfSeats() {
    // Generating the 2D array of seating plan
    listOfSeats = new Seat*[numOfRows];
    for (int i = 0; i < numOfRows; i++) {
        listOfSeats[i] = new Seat[numOfSeatsPerRow];
    }
}

// Assignment Operator (To make a deep copying when expandSize() method is called in the ReservationSystem class)
Flight& Flight::operator=(const Flight& right) {
    if (&right != this) {
        flightNo = right.flightNo;
        
        for (int i = 0; i < numOfRows; i++) {
            delete [] listOfSeats[i];
        }
        delete [] listOfSeats;

        numOfRows = right.numOfRows;
        numOfSeatsPerRow = right.numOfSeatsPerRow;

        listOfSeats = new Seat*[numOfRows];
        for (int i = 0; i < numOfRows; i++) {
            listOfSeats[i] = new Seat[numOfSeatsPerRow];
        }

        for (int i = 0; i < numOfRows; i++) {
            for (int j = 0; j < numOfSeatsPerRow; j++) {
                listOfSeats[i][j] = right.listOfSeats[i][j];
            }
        }
        setNumOfAvailableSeats();
    }

    return *this;
}

// Friend Functions
ostream& operator<<(ostream& out, const Flight& flight) {
    out << "Flight " << flight.getFlightNo() << " (" << flight.getNumOfAvailableSeats() << " available seats)" << endl;

    return out;
}

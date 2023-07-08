// Author: Esad Ismail Tok
// Student ID: 21801679

#include <iostream>
#include <string>
#include "Reservation.h"
using namespace std;

int Reservation::reservationCount = 0; // Initialization of the static variable

// Constructors
Reservation::Reservation() {
    reservationCode = 0;
    flightNo = 0;
    numOfPassengers = 0;
    rowList = NULL;
    columnList = NULL;
}

Reservation::Reservation(const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol) {
    reservationCount++;
    reservationCode = reservationCount;

    this->flightNo = flightNo;
    numOfPassengers = numPassengers;
    rowList = new int[numPassengers];
    columnList = new char[numPassengers];

    for (int i = 0; i < numPassengers; i++) {
        rowList[i] = seatRow[i];
        columnList[i] = seatCol[i];
    }
}

// Destructor
Reservation::~Reservation() {
    if (rowList) {
        delete [] rowList;
    }

    if (columnList) {
        delete [] columnList;
    }
}

// Accessors
int Reservation::getReservationCount() {
    return reservationCount;
}

int Reservation::getReservationCode() const {
    return reservationCode;
}

int Reservation::getFlightNo() const {
    return flightNo;
}

int Reservation::getNumOfPassengers() const {
    return numOfPassengers;
}

int* Reservation::getRowList() const {
    return rowList;
}

char* Reservation::getColumnList() const {
    return columnList;
}

// Mutators
void Reservation::setReservationCount() {
    reservationCount++;
}

void Reservation::setReservationCode(const int no) {
    reservationCode = no;
}

void Reservation::setFlightNo(const int no) {
    flightNo = no;
}

void Reservation::setNumOfPassengers(const int no) {
    numOfPassengers = no;
}

void Reservation::setRowList(const int* list, const int size) {
    if (rowList != NULL) {
        delete [] rowList;
    }

    rowList = new int[size];

    for (int i = 0; i < size; i++) {
        rowList[i] = list[i];
    }
}

void Reservation::setColumnList(const char* list, const int size) {
    if (columnList != NULL) {
        delete [] columnList;
    }

    columnList = new char[size];

    for (int i = 0; i < size; i++) {
        columnList[i] = list[i];
    }
}

// Assignment Operator (To make a deep copying when expandSizeReservation() method is called in the ReservationSystem class)
Reservation& Reservation::operator=(const Reservation& right) {
    if (&right != this) {
        reservationCode = right.reservationCode;
        flightNo = right.flightNo;
        numOfPassengers = right.numOfPassengers;

        if (rowList != NULL) {
            delete [] rowList;
        }
        if (columnList != NULL) {
            delete [] columnList;
        }

        rowList = new int[numOfPassengers];
        columnList = new char[numOfPassengers];

        for (int i = 0; i < numOfPassengers; i++) {
            rowList[i] = right.rowList[i];
            columnList[i] = right.columnList[i];
        }
    }
    return *this;
}

// Friend Functions
ostream& operator<<(ostream& out, const Reservation& reservation) {
    out << "Reservations under Code " << reservation.getReservationCode() << " in Flight " << reservation.getFlightNo() << ": ";
    
    for (int i = 0; i < reservation.getNumOfPassengers(); i++) {
        out << reservation.getRowList()[i] << reservation.getColumnList()[i] << " ";
    }
    out << endl;

    return out;
}
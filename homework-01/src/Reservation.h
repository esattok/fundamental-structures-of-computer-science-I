// Author: Esad Ismail Tok
// Student ID: 21801679

#ifndef __RESERVATION_H
#define __RESERVATION_H

#include <iostream>
#include <string>
using namespace std;

class Reservation {
public:
    // Constructors
    Reservation();
    Reservation(const int, const int, const int*, const char*);

    // Destructor
    ~Reservation();

    // Accessors
    static int getReservationCount();
    int getReservationCode() const;
    int getFlightNo() const;
    int getNumOfPassengers() const;
    int* getRowList() const;
    char* getColumnList() const;

    // Mutators
    static void setReservationCount();
    void setReservationCode(const int);
    void setFlightNo(const int);
    void setNumOfPassengers(const int);
    void setRowList(const int*, const int);
    void setColumnList(const char*, const int);

    // Operators
    Reservation& operator=(const Reservation&);

private:
    static int reservationCount;
    int reservationCode;
    int flightNo;
    int numOfPassengers;
    int* rowList;
    char* columnList;

// Friend functions
friend ostream& operator<<(ostream&, const Reservation&);
};

#endif
// Author: Esad Ismail Tok
// Student ID: 21801679

#ifndef __RESERVATIONSYSTEM_H
#define __RESERVATIONSYSTEM_H

#include <iostream>
#include <string>
#include "Flight.h"
#include "Reservation.h"
using namespace std;

class ReservationSystem {
public:
    ReservationSystem();
    ~ReservationSystem();

    void addFlight(const int flightNo, const int rowNo, const int seatNo);
    void cancelFlight(const int flightNo);

    void showAllFlights();
    void showFlight(const int flightNo);

    int makeReservation(const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol);
    void cancelReservation(const int resCode);
    void showReservation(const int resCode);

    // Additional Functions

    // Accessor Functions (Just to test the program)
    int getFlightSize() const;
    int getCurrentFlightSize() const;
    Flight* getFlightList() const;

    int getReservationSize() const;
    int getCurrentReservationSize() const;
    Reservation* getReservationList() const;

    // Expands the size of the flight list
    void expandSize();

    // Expands the size of the reservation list
    void expandSizeReservation();

private:
    Flight* flightList;
    int size;
    int currentSize;

    Reservation* reservationList;
    int reservationSize;
    int currentReservationSize;
};

#endif
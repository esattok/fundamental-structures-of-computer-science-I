// Author: Esad Ismail Tok
// Student ID: 21801679

#include <iostream>
#include <string>
#include "ReservationSystem.h"
using namespace std;

// Constructor
ReservationSystem::ReservationSystem() {
    size = 10;
    currentSize = 0;
    flightList = new Flight[size];

    reservationSize = 10;
    currentReservationSize = 0;
    reservationList = new Reservation[reservationSize];
}

// Destructor
ReservationSystem::~ReservationSystem() {
    if (flightList) {
        delete [] flightList;
    }

    if (reservationList) {
        delete [] reservationList;
    }
}

// Functions
void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo) {
    bool flag = true;
    for (int i = 0; i < currentSize; i++) {
        if (flightList[i].getFlightNo() == flightNo) {
            flag = false;
        }
    }

    if (!flag) {
        cout << "Flight " << flightNo << " already exists" << endl;
    }

    else {
        if (rowNo <= 0 || seatNo <= 0) {
            cout << "Number of rows and number of seats per rows must be positive integers" << endl;
        }

        else {
            if (currentSize < size) {
                flightList[currentSize].setFlightNo(flightNo);
                flightList[currentSize].setNumOfRows(rowNo);
                flightList[currentSize].setNumOfSeatsPerRow(seatNo);
                flightList[currentSize].setListOfSeats();
                flightList[currentSize].setNumOfAvailableSeats();
                currentSize++;
                cout << "Flight " << flightNo << " has been added" << endl;
            }

            else {
                expandSize();
                flightList[currentSize].setFlightNo(flightNo);
                flightList[currentSize].setNumOfRows(rowNo);
                flightList[currentSize].setNumOfSeatsPerRow(seatNo);
                flightList[currentSize].setListOfSeats();
                flightList[currentSize].setNumOfAvailableSeats();
                currentSize++;
                cout << "Flight " << flightNo << " has been added" << endl;
            }
        }
    }
}

void ReservationSystem::cancelFlight(const int flightNo) {
    bool flag = false;
    int index;

    for (int i = 0; i < currentSize; i++) {
        if (flightList[i].getFlightNo() == flightNo) {
            flag = true;
            index = i;
        }
    }

    if (!flag) {
        cout << "Flight " << flightNo << " does not exist" << endl;
    }

    else {
        // Removing reservations having the entered flight no
        for (int i = 0; i < currentReservationSize; i++) {
            if (reservationList[i].getFlightNo() == flightNo) {
                for (int j = i; j < (currentReservationSize-1); j++) {
                    reservationList[j] = reservationList[j+1];
                }
                i--;
                currentReservationSize--;
            }
        }

        // Removing the flight having entered flight no
        for (int i = index; i < (currentSize-1); i++) {
            flightList[i] = flightList[i+1];
        }
        currentSize--;

        cout << "Flight " << flightNo << " and all of its reservations are canceled" << endl;
    }
}

void ReservationSystem::showAllFlights() {
    if (currentSize <= 0) {
        cout << "No flights exist" << endl;
    }

    else {
        cout << "Flights currently operated:" << endl;

        for (int i = 0; i < currentSize; i++) {
            cout << flightList[i];
        }
    }
}

void ReservationSystem::showFlight(const int flightNo) {
    bool flag = false;
    int index;

    for (int i = 0; i < currentSize; i++) {
        if (flightList[i].getFlightNo() == flightNo) {
            flag = true;
            index = i;
        }
    }

    if (!flag) {
        cout << "Flight " << flightNo << " does not exist" << endl;
    }

    else {
        cout << "Flight " << flightNo << " has " << flightList[index].getNumOfAvailableSeats() << " available seats" << endl;
        flightList[index].showSeatingPlan();
    }
}

int ReservationSystem::makeReservation(const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol) {
    bool flagFlightNo = false;
    bool flagSeats = true;
    int index;
    int count = 0;

    for (int i = 0; i < currentSize; i++) {
        if (flightList[i].getFlightNo() == flightNo) {
            flagFlightNo = true;
            index = i;
        }
    }

    if (!flagFlightNo) {
        cout << "Flight " << flightNo << " does not exist" << endl;
        return -1;
    }

    for (int i = 0; i < numPassengers; i++) {
        if (!flightList[index].getListOfSeats()[seatRow[i] - 1][(int)seatCol[i] - 65].getIsAvailable()) {
            flagSeats = false;
            count++;
            cout << seatRow[i] << seatCol[i] << " ";
        }
    }

    
    if (!flagSeats) {
        if (count == 1) {
            cout << "is not available" << endl;
        }

        else {
            cout << "are not available" << endl;
        }
        
        return -1;
    }

    else {
        if (currentReservationSize < reservationSize) {
            Reservation::setReservationCount();
            reservationList[currentReservationSize].setReservationCode(Reservation::getReservationCount());
            reservationList[currentReservationSize].setFlightNo(flightNo);
            reservationList[currentReservationSize].setNumOfPassengers(numPassengers);
            reservationList[currentReservationSize].setRowList(seatRow, numPassengers);
            reservationList[currentReservationSize].setColumnList(seatCol, numPassengers);
            currentReservationSize++;
        }

        else {
            expandSizeReservation();
            
            Reservation::setReservationCount();
            reservationList[currentReservationSize].setReservationCode(Reservation::getReservationCount());
            reservationList[currentReservationSize].setFlightNo(flightNo);
            reservationList[currentReservationSize].setNumOfPassengers(numPassengers);
            reservationList[currentReservationSize].setRowList(seatRow, numPassengers);
            reservationList[currentReservationSize].setColumnList(seatCol, numPassengers);
            currentReservationSize++;
        }
        
        int flightIndex;
        for (int i = 0; i < currentSize; i++) {
            if (flightList[i].getFlightNo() == flightNo) {
                flightIndex = i;
            }
        }

        for (int i = 0; i < numPassengers; i++) {
            // Since the 2D array of seats takes integers items in seatCol will be changed to int starting from 0
            // 65 is the ASCII code for 'A'
            flightList[flightIndex].getListOfSeats()[seatRow[i] - 1][(int)seatCol[i] - 65].setIsAvailable(false);
        }

        flightList[flightIndex].setNumOfAvailableSeats();
        
        return reservationList[currentReservationSize-1].getReservationCode();
    }

    return -1; // If something went wrong return -1 anyway
}

void ReservationSystem::cancelReservation(const int resCode) {
    bool flag = false;
    int index;
    int flightNo;
    int flightIndex;

    for (int i = 0; i < currentReservationSize; i++) {
        if (reservationList[i].getReservationCode() == resCode) {
            flag = true;
            index = i;
        }
    }

    if (!flag) {
        cout << "No reservations are found under Code " << resCode << endl;
    }

    else {
        flightNo = reservationList[index].getFlightNo();
        
        for (int i = 0; i < currentSize; i++) {
            if (flightList[i].getFlightNo() == flightNo) {
                flightIndex = i;
            }
        }

        if (reservationList[index].getNumOfPassengers() > 1) {
            cout << "Reservation for the seats ";
        }
    
        else {
            cout << "Reservation for the seat ";
        }
        
        for (int i = 0; i < reservationList[index].getNumOfPassengers(); i++) {
            flightList[flightIndex].getListOfSeats()[reservationList[index].getRowList()[i] - 1][((int)(reservationList[index].getColumnList()[i]))-65].setIsAvailable(true);
            cout << reservationList[index].getRowList()[i] << reservationList[index].getColumnList()[i] << " ";
        }
        
        flightList[flightIndex].setNumOfAvailableSeats();
        cout << "is canceled in Flight " << flightNo << endl;

        // Removing the canceled reservation from the reservation list
        for (int i = index; i < (currentReservationSize-1); i++) {
            reservationList[i] = reservationList[i+1];
        }
        currentReservationSize--;
    }
}

void ReservationSystem::showReservation(const int resCode) {
    bool flag = false;
    int index;

    for (int i = 0; i < currentReservationSize; i++) {
        if (reservationList[i].getReservationCode() == resCode) {
            flag = true;
            index = i;
        }
    }

    if (!flag) {
        cout << "No reservations under Code " << resCode << endl;
    }

    else {
        cout << reservationList[index];
    }
}

// Accessor Functions (Just to test the program)
int ReservationSystem::getFlightSize() const {
    return size;
}

int ReservationSystem::getCurrentFlightSize() const {
    return currentSize;
}

Flight* ReservationSystem::getFlightList() const {
    return flightList;
}

int ReservationSystem::getReservationSize() const {
    return reservationSize;
}

int ReservationSystem::getCurrentReservationSize() const {
    return currentReservationSize;
}

Reservation* ReservationSystem::getReservationList() const {
    return reservationList;
}

// Expands the size of the flight list
void ReservationSystem::expandSize() {
    int newSize = size * 2;
    Flight* temp = new Flight[newSize];

    for (int i = 0; i < size; i++) {
        temp[i] = flightList[i];
    }

    size = newSize;
    delete [] flightList;
    flightList = temp;
}

// Expands the size of the reservation list
void ReservationSystem::expandSizeReservation() {
    int newSize = reservationSize * 2;
    Reservation* temp = new Reservation[newSize];

    for (int i = 0; i < reservationSize; i++) {
        temp[i] = reservationList[i];
    }

    reservationSize = newSize;
    delete [] reservationList;
    reservationList = temp;
}

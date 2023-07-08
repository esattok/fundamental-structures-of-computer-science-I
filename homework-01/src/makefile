# Author: Esad Ismail Tok
# Student ID: 21801679
# This makefile is written to be used with a driver file named as main.cpp

output: main.o Seat.o Flight.o Reservation.o ReservationSystem.o
	g++ main.o Seat.o Flight.o Reservation.o ReservationSystem.o -o output

main.o: main.cpp
	g++ -c main.cpp

Seat.o: Seat.cpp Seat.h
	g++ -c Seat.cpp

Flight.o: Flight.cpp Flight.h
	g++ -c Flight.cpp

Reservation.o: Reservation.cpp Reservation.h
	g++ -c Reservation.cpp

ReservationSystem.o: ReservationSystem.cpp ReservationSystem.h
	g++ -c ReservationSystem.cpp


# Cleans the object files and executable
clean:
	rm *.o output


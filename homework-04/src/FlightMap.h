// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#ifndef __FLIGHTMAP_H
#define __FLIGHTMAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Stack.h"
using namespace std;

class FlightMap {
public:
	FlightMap(const string cityFile, const string flightFile);
	~FlightMap();

	void displayAllCities() const;
	void displayAdjacentCities(const string cityName) const;
	void displayFlightMap() const;

	void findFlights(const string deptCity, const string destCity) const;
	void findLeastCostFlight(const string deptCity, const string destCity) const;

	void runFlightRequests(const string requestFile) const;

	// Additional public functions
	void setAllUnvisited() const;
	void setVisited(const string cityName) const;
	void setUnvisited(const string cityName) const;
	bool getVisited(const string cityName) const;
	int getCityIndexByName(const string cityName) const;
	string getNextCity(const string cityName, const int count) const;
	int getNumOfAdjacent(const string cityName) const;
	int getCount(const string cityName) const;
	void incrementCount(const string cityName) const;
	void setCountToZero(const string cityName) const;
	
	

private:
	// Helper structures and adjacency list for the storage of the graph

	// Struct that represent the adjacency list node
	struct AdjacencyNode {
		string adjacentCityName;
		int flightId;
		int cost;
		AdjacencyNode* next;
	};

	// Struct that represents each city with a pointer to the adjacency note to both provide the city name and head to the adjacency list
	struct CityNode {
		string cityName;
		AdjacencyNode* head;
		bool isVisited;
		int count;
		int numOfAdjacent;
	};

	// Array of CityNodes each representing a linked list
	CityNode* adjacencyList;

	int numOfCities; // Number of vertices in the graph

	// Additional private function
	void printPath(Stack st, int& totalCost) const;
};

#endif
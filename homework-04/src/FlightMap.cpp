// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include "FlightMap.h"
using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile) {
	// Declaring the variables
	ifstream cityInputFile;
	string cityText = "";
	int count = 0;
	int tempCount;
	AdjacencyNode* currentNode;

	ifstream flightInputFile;
	string originCity = "", destinationCity = "", strFlightId = "", strCost = "";
	int flightId = 0, cost = 0;

	// Open streams
	cityInputFile.open(cityFile.c_str(), ios_base::in);
	flightInputFile.open(flightFile.c_str(), ios_base::in);

	// Find number of vertices (cities) in the graph
	while (cityInputFile.eof() == false) {
		getline(cityInputFile, cityText, '\n');
		count++;
	}

	// Number of cities founded
	numOfCities = count;
	adjacencyList = new CityNode[numOfCities];

	// Since the city file is written, clear the file state and seek to the beggining
	cityInputFile.clear();
	cityInputFile.seekg(0, ios::beg);

	// Writing the names of each city
	count = 0;
	while (cityInputFile.eof() == false) {
		getline(cityInputFile, cityText, '\n');
		
		adjacencyList[count].cityName = cityText;
		adjacencyList[count].head = NULL; // Initially none of the cities have an adjacent vertex
		adjacencyList[count].isVisited = false; // Initially cities are unvisited
		adjacencyList[count].count = 0;
		adjacencyList[count].numOfAdjacent = 0;
		count++;
	}

	// Implementation for each line of information in flight file
	while (flightInputFile.eof() == false) {
		// Getting the information of the first line
		getline(flightInputFile, originCity, ',');
		getline(flightInputFile, destinationCity, ',');
		getline(flightInputFile, strFlightId, ',');
		getline(flightInputFile, strCost, '\n');

		// Convert the flight id and cost to integer
		stringstream convert1(strFlightId);
		stringstream convert2(strCost);

		convert1 >> flightId;
		convert2 >> cost;

		// Filling the adjacency list
		for (int i = 0; i < numOfCities; i++) {
			if (adjacencyList[i].cityName == originCity) {
				AdjacencyNode* newNode = new AdjacencyNode;

				// Determining the properties of the new node
				newNode->adjacentCityName = destinationCity;
				newNode->flightId = flightId;
				newNode->cost = cost;

				tempCount = 0;
				// Adding the node to the adjacency list
				for (AdjacencyNode* cur = adjacencyList[i].head; cur != NULL; cur = cur->next) {
					tempCount++; // Represents the size of the list
				}

				// Finds the last list item to add the new item at the end
				currentNode = adjacencyList[i].head;
				for (int k = 1; k < tempCount; k++) {
					currentNode = currentNode->next;
				}

				if (tempCount == 0) {
					newNode->next = NULL;
					adjacencyList[i].head = newNode;
				}

				else {
					newNode->next = NULL;
					currentNode->next = newNode;
				}
				

				adjacencyList[i].numOfAdjacent++;
				break; // Can exit the for loop since there will be no two cities having the same name
			}
		}
	}

	// Closing the streams
	cityInputFile.close();
	flightInputFile.close();
}

FlightMap::~FlightMap() {
	AdjacencyNode* cur;

	// Deleting the adjacent city nodes for each city in the adjacency list
	for (int i = 0; i < numOfCities; i++) {

		while (adjacencyList[i].head != NULL) {
			cur = adjacencyList[i].head;
			adjacencyList[i].head = adjacencyList[i].head->next;

			cur->next = NULL;
			delete cur;
			cur = NULL;
		}
	}

	// Deleting the adjacency list itself
	delete [] adjacencyList;
}

void FlightMap::displayAllCities() const {

	for (int i = 0; i < numOfCities; i++) {
		// To avoid the comma printing at the end of the output
		if (i > 0) {
			cout << ", ";
		}

		cout << adjacencyList[i].cityName;
	}

	cout << endl;
}

void FlightMap::displayAdjacentCities(const string cityName) const {
	Stack tempSt; // To be able to print the list in reverse order
	string tempName;
	int size = 0;

	for (int i = 0; i < numOfCities; i++) {
		if (adjacencyList[i].cityName == cityName) {
			size = adjacencyList[i].numOfAdjacent;

			for (AdjacencyNode* cur = adjacencyList[i].head; cur != NULL; cur = cur->next) {
				tempSt.push(cur->adjacentCityName);
			}

			break; // Can exit the for loop since there will be no two cities having the same name
		}
	}

	cout << cityName << " -> ";
	for (int i = 0; i < size; i++) {
		// To avoid the comma priting at the end of the output
		if (i != 0) {
			cout << ", ";
		}
		tempSt.pop(tempName);

		cout << tempName;
	}

	cout << endl;
}

void FlightMap::displayFlightMap() const {
	for (int i = 0; i < numOfCities; i++) {
		displayAdjacentCities(adjacencyList[i].cityName);
	}
}

void FlightMap::findFlights(const string deptCity, const string destCity) const {
	// Declerations
	Stack st;
	bool isFound = false;
	string lastCity; // Represents the city that is on th top of the stack
	string nextCity; // Represents the next city to go
	int totalCost;

	// Program Code
	st.push(deptCity);
	st.getTop(lastCity);
	setVisited(lastCity);

	cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;

	while (!st.isEmpty()) {
		nextCity = getNextCity(lastCity, getCount(lastCity));
		incrementCount(lastCity);

		if (nextCity == "") {
			setCountToZero(lastCity);
			st.pop();
			setUnvisited(lastCity);
		}

		else {
			if (getVisited(nextCity)) {
				// Dont do anything
			}

			else {
				st.push(nextCity);
				setVisited(nextCity);
			}
		}

		if (!st.isEmpty()) {
			st.getTop(lastCity);
		}

		if (lastCity == destCity) {
			isFound = true;
			printPath(st, totalCost);
			cout << endl;

			// When find the path pop the stack and update the top item
			setCountToZero(lastCity);
			st.pop();
			setUnvisited(lastCity);

			if (!st.isEmpty()) {
				st.getTop(lastCity);
			}
		}
	}

	if (!isFound) {
		cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << endl;
	}

}

void FlightMap::findLeastCostFlight(const string deptCity, const string destCity) const {
	// Declerations
	Stack st;
	Stack leastCostPath;
	Stack tempStack;
	bool isFound = false;
	string lastCity; // Represents the city that is on th top of the stack
	string nextCity; // Represents the next city to go
	string tempTop;
	string tempPrint;
	int totalCost;
	int numOfPaths = 0;
	int leastCostPrice;
	int temporaryCount;

	// Program Code
	st.push(deptCity);
	st.getTop(lastCity);
	setVisited(lastCity);

	cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;

	while (!st.isEmpty()) {
		nextCity = getNextCity(lastCity, getCount(lastCity));
		incrementCount(lastCity);

		if (nextCity == "") {
			setCountToZero(lastCity);
			st.pop();
			setUnvisited(lastCity);
		}

		else {
			if (getVisited(nextCity)) {
				// Do nothing
			}

			else {
				st.push(nextCity);
				setVisited(nextCity);
			}
		}

		if (!st.isEmpty()) {
			st.getTop(lastCity);
		}

		if (lastCity == destCity) {
			// Printing the current path
			isFound = true;
			printPath(st, totalCost);
			cout << endl;


			// Finding the least cost path
			if (numOfPaths == 0) {
				leastCostPrice = totalCost;
				leastCostPath = st;
			}

			else {
				if (totalCost < leastCostPrice) {
					leastCostPrice = totalCost;
					leastCostPath = st;
				}
			}

			numOfPaths++;

			// When find the path pop the stack and update the top item
			setCountToZero(lastCity);
			st.pop();
			setUnvisited(lastCity);

			if (!st.isEmpty()) {
				st.getTop(lastCity);
			}
		}
	}

	if (!isFound) {
		cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << endl;
	}

	else {
		cout << "A least cost path from " << deptCity << " to " << destCity << " is ";

		// Transfering the stack content to the temporary one to print in correct order
		while (!leastCostPath.isEmpty()) {
			leastCostPath.getTop(tempTop);
			tempStack.push(tempTop);
			leastCostPath.pop();
		}

		temporaryCount = 0;
		while (!tempStack.isEmpty()) {
			tempStack.getTop(tempPrint);

			if (temporaryCount != 0) {
				cout << " -> ";
			}
			cout << tempPrint;

			tempStack.pop();
			temporaryCount++;
		}

		cout << " and its cost is " << leastCostPrice << " TL" << endl;
	}
}

void FlightMap::runFlightRequests(const string requestFile) const {
	string deptCity;
	string destCity;

	ifstream requestInputFile;

	// Opening the stream
	requestInputFile.open(requestFile.c_str(), ios_base::in);

	// Executing the requests
	while (requestInputFile.eof() == false) {
		// Getting the information of the first line
		getline(requestInputFile, deptCity, ',');
		getline(requestInputFile, destCity, '\n');

		findLeastCostFlight(deptCity, destCity);
		cout << endl;
	}

	// Closing the stream
	requestInputFile.close();
}

// Additional Functions

int FlightMap::getNumOfAdjacent(const string cityName) const {
	int tempIndex;
	int result = 0;
	tempIndex = getCityIndexByName(cityName);
	result = adjacencyList[tempIndex].numOfAdjacent;

	return result;
}

int FlightMap::getCount(const string cityName) const {
	int tempIndex;
	int result = 0;
	tempIndex = getCityIndexByName(cityName);
	result = adjacencyList[tempIndex].count;

	return result;
}

void FlightMap::incrementCount(const string cityName) const {
	int tempIndex;
	tempIndex = getCityIndexByName(cityName);
	adjacencyList[tempIndex].count++;
}

void FlightMap::setCountToZero(const string cityName) const {
	int tempIndex;
	tempIndex = getCityIndexByName(cityName);
	adjacencyList[tempIndex].count = 0;
}

int FlightMap::getCityIndexByName(const string cityName) const {
	for (int i = 0; i < numOfCities; i++) {
		if (adjacencyList[i].cityName == cityName) {
			return i;
		}
	}

	return -1;
}

string FlightMap::getNextCity(const string cityName,  const int count) const {
	int index;
	string result = "";
	
	index = getCityIndexByName(cityName);
	AdjacencyNode* cur = adjacencyList[index].head;

	if (count > adjacencyList[index].numOfAdjacent - 1) {
		cur = NULL;
	}

	else {
		for (int i = 0; i < count; i++) {
			cur = cur->next;
		}
	}

	
	if (cur != NULL) {
		result = cur->adjacentCityName;
	}

	return result;
}

void FlightMap::setAllUnvisited() const {
	for (int i = 0; i < numOfCities; i++) {
		adjacencyList[i].isVisited = false;
	}
}

void FlightMap::setVisited(const string cityName) const {
	int index = getCityIndexByName(cityName);

	for (int i = 0; i < numOfCities; i++) {
		if (adjacencyList[i].cityName == cityName) {
			adjacencyList[i].isVisited = true;
		}
	}
}

void FlightMap::setUnvisited(const string cityName) const {
	int index = getCityIndexByName(cityName);

	for (int i = 0; i < numOfCities; i++) {
		if (adjacencyList[i].cityName == cityName) {
			adjacencyList[i].isVisited = false;
		}
	}
}

bool FlightMap::getVisited(const string cityName) const {
	int index = getCityIndexByName(cityName);

	for (int i = 0; i < numOfCities; i++) {
		if (adjacencyList[i].cityName == cityName) {
			return adjacencyList[i].isVisited;
		}
	}

	return false;
}

void FlightMap::printPath(Stack st, int& totalCost) const {
	Stack temp;
	string top;
	int index1;
	int index2;
	totalCost = 0;

	
	// To print the stack in reverse order push all the stack elements of the original stack to a temporary stack
	while (!st.isEmpty()) {
		st.getTop(top);
		temp.push(top);
		st.pop();
	}
	

	string lastCity;
	

	AdjacencyNode* cur;
	while (true) {
		temp.getTop(lastCity);
		index1 = getCityIndexByName(lastCity);
		temp.pop();

		if (temp.isEmpty()) {
			break;
		}

		else {
			temp.getTop(lastCity);
			index2 = getCityIndexByName(lastCity);

			for (cur = adjacencyList[index1].head; cur != NULL; cur = cur->next) {
				if (cur->adjacentCityName == adjacencyList[index2].cityName) {
					break;
				}
			}

			if (cur != NULL) {
				totalCost = totalCost + cur->cost;

				cout << "Flight #" << cur->flightId << " from " << adjacencyList[index1].cityName << " to " << cur->adjacentCityName;
				cout << "\tCost: " << cur->cost << " TL" << endl;
			}
		}
	}
	cout << "Total Cost .......... " << totalCost << " TL" << endl;
}

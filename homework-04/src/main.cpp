// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include "FlightMap.h"
#include "Stack.h"
using namespace std;

int main() {

	FlightMap fm("cityFile.txt", "flightFile.txt");

	// Sample output testings
	cout << "The list of the cities that HPAir serves is given below:" << endl;
	fm.displayAllCities();
	cout << endl;

	cout << "The cities adjacent to W are:" << endl;
	fm.displayAdjacentCities("W");
	cout << endl;

	cout << "The whole flight map is shown below:" << endl;
	fm.displayFlightMap();
	cout << endl;

	fm.findFlights("W", "Z");
	cout << endl;

	fm.findFlights("S", "P");
	cout << endl;

	fm.findLeastCostFlight("Y", "Z");
	cout << endl;

	fm.findLeastCostFlight("P", "X");
	cout << endl;

	fm.runFlightRequests("requestFile.txt");



	// Additional Testings
	cout << "\n\n\nAdditional Testings------------------------------------" << endl << endl;


	fm.findFlights("X", "Z");
	cout << endl;

	fm.findLeastCostFlight("X", "Z");
	cout << endl << endl;


	fm.findFlights("P", "W");
	cout << endl;

	fm.findLeastCostFlight("P", "W");
	cout << endl << endl;


	fm.findFlights("P", "Z");
	cout << endl;

	fm.findLeastCostFlight("P", "Z");
	cout << endl << endl;


	fm.findFlights("S", "Z");
	cout << endl;

	fm.findLeastCostFlight("S", "Z");
	cout << endl << endl;


	fm.findFlights("W", "T");
	cout << endl;

	fm.findLeastCostFlight("W", "T");
	cout << endl << endl;


	fm.findFlights("P", "X");
	cout << endl;

	fm.findLeastCostFlight("P", "X");
	cout << endl << endl;


	fm.findFlights("Q", "R");
	cout << endl;

	fm.findLeastCostFlight("Q", "R");
	cout << endl << endl;


	fm.findFlights("S", "W");
	cout << endl;

	fm.findLeastCostFlight("S", "W");
	cout << endl << endl;


	fm.findFlights("T", "W");
	cout << endl;

	fm.findLeastCostFlight("T", "W");
	cout << endl << endl;


	fm.findFlights("W", "Y");
	cout << endl;

	fm.findLeastCostFlight("W", "Y");
	cout << endl << endl;


	fm.findFlights("W", "Z");
	cout << endl;

	fm.findLeastCostFlight("W", "Z");
	cout << endl << endl;




	// Testing the stack
	cout << "\n\n\nStack Test -------------------------------------------" << endl;
	cout << endl;

	Stack st;
	string temp1;

	st.push("Esat");
	st.push("Hasan");
	st.push("Ali");
	st.push("Veli");
	st.push("Deniz");
	//cout << st.isEmpty() << endl;

	string temp2;
	Stack equals;
	equals.push("Merhaba");
	equals.push("Olaaa");
	equals.push("lkdfgldkfgj");
	equals.pop();
	equals.getTop(temp2);
	cout << "Top of the old equals " << temp2 << endl;

	equals = st;

	st.push("Degisti mi");
	st.push("hahahah");
	st.pop();

	cout << "Printing eqals:" << endl;
	while (!equals.isEmpty()) {
		equals.getTop(temp1);
		cout << temp1 << endl;
		equals.pop();
	}

	cout << "Printing st:" << endl;
	while (!st.isEmpty()) {
		st.getTop(temp1);
		cout << temp1 << endl;
		st.pop();
	}

	cout << equals.isEmpty() << endl;
	cout << st.isEmpty() << endl;

	return 0;
}
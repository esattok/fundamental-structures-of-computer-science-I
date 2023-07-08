// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#ifndef __SIMPLESTUDENT_H
#define __SIMPLESTUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student(); // Default Constructor
	Student(const int id, const string name); // Constructor

	// Accessor Functions
	int getId() const;
	string getName() const;

	// Mutator Functions
	void setId(const int newId);
	void setName(const string newName);

private:
	int id;
	string name;
};

#endif
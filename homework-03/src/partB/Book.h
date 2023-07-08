// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#ifndef __BOOK_H
#define __BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
public:
	Book(); // Default Constructor
	Book(const int id, const string title, const int year); // Constructor

	// Accessor Functions
	int getId() const;
	string getTitle() const;
	int getYear() const;

	// Mutator Functions
	void setId(const int newId);
	void setTitle(const string newTitle);
	void setYear(const int newYear);

private:
	int id;
	string title;
	int year;
};

#endif
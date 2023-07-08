// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book() {
	id = 0;
	title = "";
	year = 0;
}

Book::Book(const int id, const string title, const int year) {
	this->id = id;
	this->title = title;
	this->year = year;
}

int Book::getId() const {
	return id;
}

string Book::getTitle() const {
	return title;
}

int Book::getYear() const {
	return year;
}


void Book::setId(const int newId) {
	id = newId;
}

void Book::setTitle(const string newTitle) {
	title = newTitle;
}

void Book::setYear(const int newYear) {
	year = newYear;
}

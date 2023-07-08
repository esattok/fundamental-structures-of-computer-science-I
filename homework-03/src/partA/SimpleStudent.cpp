// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include <iostream>
#include <string>
#include "SimpleStudent.h"
using namespace std;

Student::Student() {
	id = 0;
	name = "";
}

Student::Student(const int id, const string name) {
	this->id = id;
	this->name = name;
}

int Student::getId() const {
	return id;
}

string Student::getName() const {
	return name;
}

void Student::setId(const int newId) {
	this->id = newId;
}

void Student::setName(const string newName) {
	this->name = newName;
}
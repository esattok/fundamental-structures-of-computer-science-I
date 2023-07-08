// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#ifndef __SIMPLELIBRARYSYSTEM_H
#define __SIMPLELIBRARYSYSTEM_H

#include <iostream>
#include <string>
#include "SimpleStudent.h"
using namespace std;

class LibrarySystem {
public:
	LibrarySystem();
	~LibrarySystem();
	void addStudent(const int studentId, const string studentName);
	void deleteStudent(const int studentId);
	void showStudent(const int studentId) const;

	// Additional Functions
	bool isEmptyStudent() const;
	int getLengthStudent() const;

private:
	struct StudentNode {
		Student data;
		StudentNode* next;
	};

	int studentSize;
	StudentNode* headStudent;

	// Private function to find a student in the linked list
	StudentNode* findStudent(const int index) const;
};

#endif
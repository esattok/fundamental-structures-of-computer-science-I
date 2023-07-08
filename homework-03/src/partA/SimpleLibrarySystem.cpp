// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include <iostream>
#include <string>
#include "SimpleLibrarySystem.h"
using namespace std;

LibrarySystem::LibrarySystem() {
	studentSize = 0;
	headStudent = NULL;
}

LibrarySystem::~LibrarySystem() {
	StudentNode* cur;

	// Deletes the student at the first position untill the list is cleared
	while (!isEmptyStudent()) {
		cur = headStudent;
		headStudent = headStudent->next;

		studentSize--;

		cur->next = NULL;
		delete cur;
		cur = NULL;
	}
}

bool LibrarySystem::isEmptyStudent() const {
	if (studentSize == 0) {
		return true;
	}

	else {
		return false;
	}
}

int LibrarySystem::getLengthStudent() const {
	return studentSize;
}

LibrarySystem::StudentNode* LibrarySystem::findStudent(const int index) const {
	if (index < 1 || index > this->getLengthStudent()) {
		return NULL;
	}

	else {
		StudentNode* cur = headStudent;

		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}

		return cur;
	}
}

void LibrarySystem::addStudent(const int studentId, const string studentName) {
	bool isExist = false;

	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == studentId) {
			isExist = true;
			break;
		}
	}

	// If the student id already exists do not add the student
	if (isExist) {
		cout << "Student " << studentId << " already exists" << endl;
	}
	
	// Since the list can be unsorted and there is no index specification, adding to the beggining of the list is better for the time complexity
	else {
		StudentNode* newNode = new StudentNode;
		(newNode->data).setId(studentId);
		(newNode->data).setName(studentName);

		newNode->next = headStudent;
		headStudent = newNode;
		studentSize++;

		cout << "Student " << studentId << " has been added" << endl;
	}
}

void LibrarySystem::deleteStudent(const int studentId) {
	bool isExist = false;
	int count = 1; // Count will be the index of the student to be deleted

	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == studentId) {
			isExist = true;
			break;
		}

		else {
			count++;
		}
	}

	if (!isExist) {
		cout << "Student " << studentId << " does not exist" << endl;
	}

	else {
		StudentNode* cur; // Will hold the address of the node to be deleted

		if (count == 1) {
			cur = headStudent;
			headStudent = headStudent->next;
		}

		else {
			cur = findStudent(count);
			StudentNode* prev = findStudent(count - 1);
			prev->next = cur->next;
		}

		studentSize--;
		cur->next = NULL;
		delete cur;
		cur = NULL;

		cout << "Student " << studentId << " has been deleted" << endl;
	}
}

void LibrarySystem::showStudent(const int studentId) const {
	bool isExist = false;
	int count = 1;

	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == studentId) {
			isExist = true;
			break;
		}

		else {
			count++;
		}
	}

	if (!isExist) {
		cout << "Student " << studentId << " does not exist" << endl;
	}

	else {
		StudentNode* temp = findStudent(count); // Stores the address of the requested student
		cout << "Student id: " << (temp->data).getId() << " student name: " << (temp->data).getName() << endl;
	}
}


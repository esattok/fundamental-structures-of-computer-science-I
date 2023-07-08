// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {
	id = 0;
	name = "";
	size = 0;
	head = NULL;
}

Student::Student(const int id, const string name) {
	this->id = id;
	this->name = name;
	size = 0;
	head = NULL;
}

Student::~Student() {
	Node* cur;

	// Deletes the book at the first position untill the list is cleared
	while (!isEmpty()) {
		cur = head;
		head = head->next;

		size--;

		cur->next = NULL;
		delete cur;
		cur = NULL;
	}
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

Student::Node* Student::find(const int index) const {
	if (index < 1 || index > this->getLength()) {
		return NULL;
	}

	else {
		Node* cur = head;

		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}

		return cur;
	}
}

bool Student::isEmpty() const {
	if (size == 0) {
		return true;
	}

	else {
		return false;
	}
}

int Student::getLength() const {
	return size;
}

void Student::addItem(const int bookId, const string bookTitle, const int bookYear) {
	Node* newNode = new Node;
	(newNode->data).setId(bookId);
	(newNode->data).setTitle(bookTitle);
	(newNode->data).setYear(bookYear);

	if (isEmpty()) {
		newNode->next = NULL;
		head = newNode;
	}

	else {
		Node* prev = find(getLength());
		newNode->next = NULL;
		prev->next = newNode;
	}
	
	size++;
}

bool Student::removeItem(const int bookId) {
	bool isExist = false;
	int count = 1;

	for (Node* cur = head; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			isExist = true;
			break;
		}

		else {
			count++;
		}
	}

	if (!isExist) {
		return false;
	}

	else {
		Node* cur;

		if (count == 1) {
			cur = head;
			head = head->next;
		}

		else {
			cur = find(count);
			Node* prev = find(count - 1);
			prev->next = cur->next;
		}

		cur->next = NULL;
		delete cur;
		cur = NULL;

		size--;

		return true;
	}
}

bool Student::isBookExists(const int bookId) const {
	for (Node* cur = head; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			return true;
		}
	}

	return false;
}

int Student::getIdBook(const int bookId) const {
	int count = 1;

	for (Node* cur = head; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			break;
		}

		else {
			count++;
		}
	}

	return (find(count)->data).getId();
}

int Student::getIdBookByIndex(const int index) const {
	return (find(index)->data).getId();
}

string Student::getTitleBook(const int bookId) const {
	int count = 1;

	for (Node* cur = head; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			break;
		}

		else {
			count++;
		}
	}

	return (find(count)->data).getTitle();
}

int Student::getYearBook(const int bookId) const {
	int count = 1;

	for (Node* cur = head; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			break;
		}

		else {
			count++;
		}
	}

	return (find(count)->data).getYear();
}

void Student::displayAllItems() const {
	for (Node* cur = head; cur != NULL; cur = cur->next) {
		cout.width(10); cout << left << (cur->data).getId();
		cout.width(25); cout << left << (cur->data).getTitle();
		cout.width(10); cout << left << (cur->data).getYear();
		cout << endl;
	}
}

void Student::displayAllItemsWithStatus() const {
	for (Node* cur = head; cur != NULL; cur = cur->next) {
		cout.width(10); cout << left << (cur->data).getId();
		cout.width(25); cout << left << (cur->data).getTitle();
		cout.width(10); cout << left << (cur->data).getYear();
		cout.width(10); cout << left << "Checked out by student " << this->getId();
		cout << endl;
	}
}
// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class Student {
public:
	Student(); // Default Constructor
	Student(const int id, const string name); // Constructor
	~Student(); // Destructor

	// Accessor Functions
	int getId() const;
	string getName() const;

	// Mutator Functions
	void setId(const int newId);
	void setName(const string newName);

	// Linked List Operations
	bool isEmpty() const;
	int getLength() const;

	void addItem(const int bookId, const string bookTitle, const int bookYear);
	bool removeItem(const int bookId);

	bool isBookExists(const int bookId) const;

	// Gets the contents of the specified book
	int getIdBook(const int bookId) const;
	int getIdBookByIndex(const int index) const;
	string getTitleBook(const int bookId) const;
	int getYearBook(const int bookId) const;

	// Displays the current checked books
	void displayAllItems() const;
	
	// Displays the current checked books together with its status
	void displayAllItemsWithStatus() const;

private:
	// Node represents the each element of the linked list that holds the book that is checked for each student
	struct Node {
		Book data;
		Node* next;
	};

	int id;
	string name;

	int size;
	Node* head;

	Node* find(const int index) const;
};

#endif
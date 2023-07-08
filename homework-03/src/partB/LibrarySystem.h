// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#ifndef __LIBRARYSYSTEM_H
#define __LIBRARYSYSTEM_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Book.h"
using namespace std;

class LibrarySystem {
public:
	LibrarySystem();
	~LibrarySystem();

	void addBook(const int bookId, const string bookName, const int bookYear);
	void deleteBook(const int bookId);

	void addStudent(const int studentId, const string studentName);
	void deleteStudent(const int studentId);

	void checkoutBook(const int bookId, const int studentId);
	void returnBook(const int bookId);

	void showAllBooks() const;
	void showBook(const int bookId) const;
	void showStudent(const int studentId) const;

	// Additional Functions
	bool isEmptyStudent() const;
	int getLengthStudent() const;

	bool isEmptyUncheckedBook() const;
	int getLengthUncheckedBook() const;

	
private:
	struct StudentNode {
		Student data;
		StudentNode* next;
	};

	int studentSize;
	StudentNode* headStudent;

	struct UncheckedBookNode {
		Book data;
		UncheckedBookNode* next;
	};

	int uncheckedBookSize;
	UncheckedBookNode* headBook;

	// Private function to find a student in the linked list
	StudentNode* findStudent(const int index) const;

	// Private function to find an unchecked book in the book list
	UncheckedBookNode* findUncheckedBook(const int index) const;
};

#endif
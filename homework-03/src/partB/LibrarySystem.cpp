// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include <iostream>
#include <string>
#include "LibrarySystem.h"
using namespace std;

LibrarySystem::LibrarySystem() {
	studentSize = 0;
	headStudent = NULL;

	uncheckedBookSize = 0;
	headBook = NULL;
}

LibrarySystem::~LibrarySystem() {
	// Deletes the student at the first position untill the list is cleared
	StudentNode* cur;

	while (!isEmptyStudent()) {
		cur = headStudent;
		headStudent = headStudent->next;

		studentSize--;

		cur->next = NULL;
		delete cur;
		cur = NULL;
	}

	// Deletes the unchecked books starting from the first item
	UncheckedBookNode* temp;

	while (!isEmptyUncheckedBook()) {
		temp = headBook;
		headBook = headBook->next;

		uncheckedBookSize--;

		temp->next = NULL;
		delete temp;
		temp = NULL;
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

bool LibrarySystem::isEmptyUncheckedBook() const {
	if (uncheckedBookSize == 0) {
		return true;
	}

	else {
		return false;
	}
}

int LibrarySystem::getLengthUncheckedBook() const {
	return uncheckedBookSize;
}

LibrarySystem::UncheckedBookNode* LibrarySystem::findUncheckedBook(const int index) const {
	if (index < 1 || index > getLengthUncheckedBook()) {
		return NULL;
	}

	else {
		UncheckedBookNode* cur = headBook;

		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}

		return cur;
	}
}

void LibrarySystem::addBook(const int bookId, const string bookTitle, const int bookYear) {
	bool isExist = false;

	// Checking whether the book id is already exists or not
	// In the unchecked book list
	for (UncheckedBookNode* cur = headBook; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			isExist = true;
			break;
		}
	}

	// In the checked books by students
	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).isBookExists(bookId)) {
			isExist = true;
			break;
		}
	}

	if (isExist) {
		cout << "Book " << bookId << " already exists" << endl;
	}

	// Adding at the end of the list
	else {
		UncheckedBookNode* newNode = new UncheckedBookNode;
		(newNode->data).setId(bookId);
		(newNode->data).setTitle(bookTitle);
		(newNode->data).setYear(bookYear);

		if (isEmptyUncheckedBook()) {
			newNode->next = NULL;
			headBook = newNode;
		}

		else {
			UncheckedBookNode* prev = findUncheckedBook(getLengthUncheckedBook());
			newNode->next = NULL;
			prev->next = newNode;
		}
		
		uncheckedBookSize++;
		
		cout << "Book " << bookId << " has been added" << endl;
	}
}

void LibrarySystem::deleteBook(const int bookId) {
	bool isExistFree = false;
	bool isExistChecked = false;
	int countFree = 1;
	int countChecked = 1;

	// In the unchecked book list
	for (UncheckedBookNode* cur = headBook; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			isExistFree = true;
			break;
		}

		else {
			countFree++;
		}
	}

	// In the checked books by students
	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).isBookExists(bookId)) {
			isExistChecked = true;
			break;
		}

		else {
			countChecked++;
		}
	}

	if (!isExistFree && !isExistChecked) {
		cout << "Book " << bookId << " does not exist" << endl;
	}

	else if (isExistFree && !isExistChecked) {
		UncheckedBookNode* cur; // Will hold the address of the node to be deleted

		if (countFree == 1) {
			cur = headBook;
			headBook = headBook->next;
		}

		else {
			cur = findUncheckedBook(countFree);
			UncheckedBookNode* prev = findUncheckedBook(countFree - 1);
			prev->next = cur->next;
		}

		uncheckedBookSize--;
		cur->next = NULL;
		delete cur;
		cur = NULL;

		cout << "Book " << bookId << " has not been checked out" << endl;
		cout << "Book " << bookId << " has been deleted" << endl;
	}

	else if (!isExistFree && isExistChecked) {
		if ((findStudent(countChecked)->data).removeItem(bookId)) {
			cout << "Book " << bookId << " has been returned" << endl;
			cout << "Book " << bookId << " has been deleted" << endl;
		}
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

	// Adding at the end of the list
	else {
		StudentNode* newNode = new StudentNode;
		(newNode->data).setId(studentId);
		(newNode->data).setName(studentName);

		if (isEmptyStudent()) {
			newNode->next = NULL;
			headStudent = newNode;
		}

		else {
			StudentNode* prev = findStudent(getLengthStudent());
			newNode->next = NULL;
			prev->next = newNode;
		}
		
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
		int tempId; // Will hold the id of the each book that student will return
		
		if (count == 1) {
			cur = headStudent;
			
			// Returning the books of the student
			while (!((cur->data).isEmpty())) {
				tempId = (cur->data).getIdBookByIndex(1);
				returnBook(tempId);
			}

			// Deleting the student
			headStudent = headStudent->next;
		}

		else {
			cur = findStudent(count);
			
			// Returning the books of the student
			while (!((cur->data).isEmpty())) {
				tempId = (cur->data).getIdBookByIndex(1);
				returnBook(tempId);
			}
			
			// Deleting the student
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

void LibrarySystem::checkoutBook(const int bookId, const int studentId) {
	bool isBookExistFree = false;
	bool isBookExistChecked = false;
	bool isStudentExist = false;
	int countBook = 1;
	int countStudent = 1;

	// Checking whether the book exists in the unchecked books list and determining the position of the book if exists
	for (UncheckedBookNode* cur = headBook; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			isBookExistFree = true;
			break;
		}

		else {
			countBook++;
		}
	}

	// Checking whether the book exist and checked by a student 
	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).isBookExists(bookId)) {
			isBookExistChecked = true;
		}
	}

	// Checking whether the student exists and determining the position of the student if exists
	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == studentId) {
			isStudentExist = true;
			break;
		}

		else {
			countStudent++;
		}
	}

	if (!isBookExistChecked && !isBookExistFree) {
	cout << "Book " << bookId << " does not exist for checkout" << endl;
	}

	else if (!isStudentExist) {
		cout << "Student " << studentId << " does not exist for checkout" << endl;
	}

	else if (isBookExistChecked && !isBookExistFree) {
		cout << "Book " << bookId << " has been already checked out by another student" << endl;
	}

	else if (isBookExistFree && !isBookExistChecked) {

		// Adding the book to the students checked books list
		(findStudent(countStudent)->data).addItem((findUncheckedBook(countBook)->data).getId(), (findUncheckedBook(countBook)->data).getTitle(), (findUncheckedBook(countBook)->data).getYear());
		
		// Removing the book from the unchecked book list
		UncheckedBookNode* cur; // Will hold the address of the node to be deleted in the unchecked books

		if (countBook == 1) {
			cur = headBook;
			headBook = headBook->next;
		}

		else {
			cur = findUncheckedBook(countBook);
			UncheckedBookNode* prev = findUncheckedBook(countBook - 1);
			prev->next = cur->next;
		}

		uncheckedBookSize--;
		cur->next = NULL;
		delete cur;
		cur = NULL;

		cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
	}
}

void LibrarySystem::returnBook(const int bookId) {
	bool isBookExistFree = false;
	bool isBookExistChecked = false;
	int studentCount = 1;

	// Checking whether the book exist in the unchecked books list
	for (UncheckedBookNode* cur = headBook; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			isBookExistFree = true;
			break;
		}
	}

	// Checking whether the book exists and checked by a student and finding the position of the student
	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).isBookExists(bookId)) {
			isBookExistChecked = true;
			break;
		}

		else {
			studentCount++;
		}
	}

	if (!isBookExistFree && !isBookExistChecked) {
		cout << "Book " << bookId << " does not exist" << endl;
	}

	else if (isBookExistFree) {
		cout << "Book " << bookId << " has not been checked out" << endl;
	}

	else {
		// Storing the properties of the book to not to lose them after deleting it from student
		int idOfBook = (findStudent(studentCount)->data).getIdBook(bookId);
		string titleOfBook = (findStudent(studentCount)->data).getTitleBook(bookId);
		int yearOfBook = (findStudent(studentCount)->data).getYearBook(bookId);

		// Removing the book from the students checked book list
		(findStudent(studentCount)->data).removeItem(bookId);

		// Adding the book to unchecked book list
		UncheckedBookNode* newNode = new UncheckedBookNode;
		(newNode->data).setId(idOfBook);
		(newNode->data).setTitle(titleOfBook);
		(newNode->data).setYear(yearOfBook);

		newNode->next = headBook;
		headBook = newNode;
		uncheckedBookSize++;

		cout << "Book " << bookId << " has been returned" << endl;
	}
}

void LibrarySystem::showAllBooks() const {
	bool isEmptyChecked = true;

	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if (!((cur->data).isEmpty())) {
			isEmptyChecked = false;
			break;
		}
	}

	if (isEmptyChecked && isEmptyUncheckedBook()) {
		cout << "Library is currently empty" << endl;
	}

	else {
		cout.width(10); cout << left << "Book id";
		cout.width(25); cout << left << "Book Name";
		cout.width(10); cout << left << "Year";
		cout.width(10); cout << left << "Status";
		cout << endl;

		// Displaying the unchecked books
		for (UncheckedBookNode* cur = headBook; cur != NULL; cur = cur->next) {
			cout.width(10); cout << left << (cur->data).getId();
			cout.width(25); cout << left << (cur->data).getTitle();
			cout.width(10); cout << left << (cur->data).getYear();
			cout.width(10); cout << left << "Not checked out";
			cout << endl;
		}

		// Displaying the checked books
		for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
			(cur->data).displayAllItemsWithStatus();
		}
	}
}

void LibrarySystem::showBook(const int bookId) const {
	bool isExistFree = false;
	bool isExistChecked = false;
	int countBook = 1;
	int countStudent = 1;

	// Checking whether the book exists or not
	// In the unchecked book list
	for (UncheckedBookNode* cur = headBook; cur != NULL; cur = cur->next) {
		if ((cur->data).getId() == bookId) {
			isExistFree = true;
			break;
		}

		else {
			countBook++;
		}
	}

	// In the checked books by students
	for (StudentNode* cur = headStudent; cur != NULL; cur = cur->next) {
		if ((cur->data).isBookExists(bookId)) {
			isExistChecked = true;
			break;
		}

		else {
			countStudent++;
		}
	}

	if (!isExistChecked && !isExistFree) {
		cout << "Book " << bookId << " does not exist" << endl;
	}

	else if (isExistFree) {
		cout.width(10); cout << left << (findUncheckedBook(countBook)->data).getId();
		cout.width(25); cout << left << (findUncheckedBook(countBook)->data).getTitle();
		cout.width(10); cout << left << (findUncheckedBook(countBook)->data).getYear();
		cout.width(10); cout << left << "Not checked out";
		cout << endl;
	}

	else if (isExistChecked) {
		cout.width(10); cout << left << (findStudent(countStudent)->data).getIdBook(bookId);
		cout.width(25); cout << left << (findStudent(countStudent)->data).getTitleBook(bookId);
		cout.width(10); cout << left << (findStudent(countStudent)->data).getYearBook(bookId);
		cout.width(10); cout << left << "Checked out by student " << (findStudent(countStudent)->data).getId();
		cout << endl;
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

		if ((temp->data).isEmpty()) {
			cout << "Student " << studentId << " has no books" << endl;
		}

		else {
			cout << "Student " << studentId << " has checked out the following books:" << endl;

			cout.width(10); cout << left << "Book id";
			cout.width(25); cout << left << "Book Name";
			cout.width(10); cout << left << "Year";
			cout << endl;

			(temp->data).displayAllItems();
		}
	}
}


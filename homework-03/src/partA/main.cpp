// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include <iostream>
#include <string>
#include "SimpleLibrarySystem.h"
using namespace std;

int main() {
	LibrarySystem library;

	cout << "Before adding students" << endl;
	if (library.isEmptyStudent()) {
		cout << "library is empty" << endl;
	}
	else {
		cout << "library is NOT empty" << endl;
	}

	cout << "There are " << library.getLengthStudent() << " students in the library" << endl;
	library.showStudent(100);

	cout << "\nAdding Students" << endl;
	library.addStudent(100, "Esat");
	library.addStudent(101, "Hasan");
	library.addStudent(102, "Ali");
	library.addStudent(103, "Veli");
	library.addStudent(103, "deneme");

	cout << "\nAfter adding students" << endl;
	if (library.isEmptyStudent()) {
		cout << "library is empty" << endl;
	}
	else {
		cout << "library is NOT empty" << endl;
	}

	cout << "There are " << library.getLengthStudent() << " students in the library" << endl << endl;

	library.showStudent(102);
	library.showStudent(101);
	library.showStudent(103);
	library.showStudent(100);
	library.showStudent(99);
	library.showStudent(104);

	cout << "\nDeleting Students" << endl;
	library.deleteStudent(200);
	library.deleteStudent(101);
	library.deleteStudent(103);
	library.deleteStudent(99);
	library.deleteStudent(101);
	library.deleteStudent(101);

	cout << "\nAfter deleting students" << endl;
	if (library.isEmptyStudent()) {
		cout << "library is empty" << endl;
	}
	else {
		cout << "library is NOT empty" << endl;
	}

	cout << "There are " << library.getLengthStudent() << " students in the library" << endl << endl;

	library.addStudent(103, "dummyName");
	library.deleteStudent(103);
	library.deleteStudent(103);

	cout << endl;
	library.showStudent(103);
	library.showStudent(101);
	library.showStudent(100);
	library.showStudent(102);

	library.addStudent(200, "ahmet");

	
	if (library.isEmptyStudent()) {
		cout << "library is empty" << endl;
	}
	else {
		cout << "library is NOT empty" << endl;
	}

	cout << "There are " << library.getLengthStudent() << " students in the library" << endl << endl;

	return 0;
}
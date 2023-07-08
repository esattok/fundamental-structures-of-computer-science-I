// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include <iostream>
#include <string>
#include "LibrarySystem.h"
using namespace std;

int main() {
	LibrarySystem LS;

	LS.addBook(1000, "Machine Learning", 1997);
	LS.addBook(1200, "Data Mining", 1991);
	LS.addBook(1300, "Problem S. with C++", 1991);
	LS.addBook(1400, "C++ How to Program", 2005);
	LS.addBook(1200, "Data Mining", 1991);
	LS.deleteBook(1300);
	LS.deleteBook(2000);
	LS.addBook(1500, "Pattern Recognition", 2000);
	cout << endl;

	LS.addStudent(21000000, "Selim Aksoy");
	LS.addStudent(21000011, "Ercument Cicek");
	LS.addStudent(21000011, "Aydamir Mirzayev");
	LS.addStudent(21000020, "Mert Duman");
	LS.addStudent(21000001, "Han Solo");
	LS.addStudent(21000005, "Jack Ryan");
	LS.deleteStudent(21000011);
	LS.deleteStudent(21000050);
	cout << endl;

	
	LS.checkoutBook(1200, 21000000);
	LS.checkoutBook(1400, 21000020);
	LS.checkoutBook(2050, 21000011);
	LS.checkoutBook(1000, 21000444);
	LS.checkoutBook(1500, 21000000);
	LS.checkoutBook(1400, 21000001);
	cout << endl;

	LS.showStudent(21000000);
	cout << endl;
	LS.showStudent(21000005);
	cout << endl;
	LS.showStudent(21000011);
	cout << endl;

	LS.showBook(1000);
	LS.showBook(1200);
	cout << endl;

	LS.showAllBooks();
	cout << endl;

	LS.returnBook(1200);
	LS.returnBook(1000);
	cout << endl;

	LS.checkoutBook(1200, 21000020);
	LS.checkoutBook(1000, 21000000);
	cout << endl;

	LS.showAllBooks();
	cout << endl;
	
	LS.deleteStudent(21000020);
	cout << endl;

	LS.deleteBook(1000);
	cout << endl;

	LS.showStudent(21000000);
	cout << endl;

	LS.showAllBooks();
	cout << endl;

	cout << "--------------------------------Additional Testings----------------------------------" << endl << endl;

	LibrarySystem test;

	test.addStudent(10, "Esat");
	test.addStudent(11, "Ali");
	test.addStudent(12, "Veli");
	test.addStudent(11, "Esat");
	test.deleteStudent(9);
	cout << endl;

	test.showAllBooks();
	test.showStudent(15);
	test.showStudent(12);
	cout << endl;

	test.addBook(100, "Kitap Ismi 1", 2000);
	test.addBook(101, "Kitap Ismi 2", 2000);
	test.addBook(102, "Kitap Ismi 3", 2000);
	test.addBook(103, "Kitap Ismi 4", 2000);
	test.addBook(101, "Kitap Ismi 5", 2000);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.showBook(107);
	test.showBook(101);
	cout << endl;

	test.deleteBook(110);
	test.deleteBook(103);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.checkoutBook(110, 234);
	test.checkoutBook(101, 255);
	test.checkoutBook(120, 11);
	test.checkoutBook(101, 11);
	test.checkoutBook(102, 12);
	test.checkoutBook(101, 11);
	test.checkoutBook(102, 10);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.addBook(104, "Kitap Ismi 7", 2000);
	test.addBook(105, "Kitap Ismi 8", 2000);
	test.addBook(106, "Kitap Ismi 9", 2000);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.checkoutBook(104, 10);
	test.checkoutBook(105, 10);
	cout << endl;

	test.showStudent(10);
	cout << endl;

	test.showStudent(11);
	cout << endl;

	test.showStudent(12);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.showBook(100);
	test.showBook(104);
	test.showBook(102);
	cout << endl;

	test.showStudent(10);
	cout << endl;

	test.returnBook(120);
	test.returnBook(100);
	test.returnBook(104);
	cout << endl;

	test.showStudent(10);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.checkoutBook(100, 10);
	test.checkoutBook(106, 10);
	cout << endl;

	test.showStudent(11);
	cout << endl;

	test.returnBook(101);
	cout << endl;

	test.showStudent(10);
	cout << endl;

	test.showStudent(11);
	cout << endl;

	test.checkoutBook(104, 11);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.deleteBook(130);
	test.deleteBook(101);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.showStudent(10);
	cout << endl;

	test.deleteBook(106);
	cout << endl;
	test.deleteBook(104);
	cout << endl;

	test.showStudent(11);
	cout << endl;

	test.showStudent(10);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.deleteStudent(20);
	cout << endl;
	test.deleteStudent(11);
	cout << endl;

	test.showStudent(11);
	cout << endl;

	test.deleteStudent(12);
	cout << endl;

	test.deleteStudent(10);
	cout << endl;

	test.showAllBooks();
	cout << endl;

	test.showStudent(12);
	cout << endl;
	test.showStudent(10);
	cout << endl;

	test.showBook(104);
	test.showBook(106);
	cout << endl;

	test.showBook(100);
	test.showBook(105);
	test.showBook(102);
	cout << endl;

	test.deleteBook(102);
	test.deleteBook(100);
	test.deleteBook(105);
	cout << endl;

	test.showAllBooks();


	return 0;
}
# Student Name: Esad Ismail Tok
# Student Id: 21801679
# Section: 1

output: main.o Book.o Student.o LibrarySystem.o
	g++ main.o Book.o Student.o LibrarySystem.o -o output

main.o: main.cpp
	g++ -c main.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

LibrarySystem.o: LibrarySystem.cpp LibrarySystem.h
	g++ -c LibrarySystem.cpp


# Cleans the object files and executable
clean:
	rm *.o output


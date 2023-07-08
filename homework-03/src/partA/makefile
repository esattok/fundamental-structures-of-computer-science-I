# Student Name: Esad Ismail Tok
# Student Id: 21801679
# Section: 1

output: main.o SimpleStudent.o SimpleLibrarySystem.o
	g++ main.o SimpleStudent.o SimpleLibrarySystem.o -o output

main.o: main.cpp
	g++ -c main.cpp

SimpleStudent.o: SimpleStudent.cpp SimpleStudent.h
	g++ -c SimpleStudent.cpp

SimpleLibrarySystem.o: SimpleLibrarySystem.cpp SimpleLibrarySystem.h
	g++ -c SimpleLibrarySystem.cpp


# Cleans the object files and executable
clean:
	rm *.o output


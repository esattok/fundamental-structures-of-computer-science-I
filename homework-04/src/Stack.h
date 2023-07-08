// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <string>
using namespace std;

typedef string StackItemType;

class Stack {
public:
	Stack(); // Constructor
	Stack(const Stack&); //Copy Constructor for the deep copy
	~Stack(); // Destructor

	// Stack operations
	bool isEmpty() const; // Checks whether the stack is empty or not
	bool push(const StackItemType&); // Adds a new item to the top of the stack
	bool pop(); // Removes the last added item from the stack
	bool pop(StackItemType&); // Removes the last added item from the stack and returns the value by parameter list
	bool getTop(StackItemType&) const; // Gets te top item of the stack
	void emptyStack(); // Empties the stack

	Stack& operator=(const Stack&); // Overloaded assignment operation for stack

private:
	struct StackNode {
		StackItemType data;
		StackNode* next;
	};

	StackNode* topPtr; // It serves as both the head pointer and top of the stack
};

#endif
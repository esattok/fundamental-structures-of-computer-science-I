// Student Name: Esad Ismail Tok
// Student ID: 21801679
// Section: 1

#include "Stack.h"
using namespace std;

Stack::Stack() {
	topPtr = NULL;
}

Stack::Stack(const Stack& right) {
	if (right.topPtr == NULL) {
		topPtr = NULL;
	}

	else {
		// Copying the first node
		topPtr = new StackNode;
		topPtr->data = right.topPtr->data;

		// Copying the other nodes
		StackNode* newPtr = topPtr;
		for (StackNode* origPtr = right.topPtr->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new StackNode;
			newPtr = newPtr->next;
			newPtr->data = origPtr->data;
		}

		newPtr->next = NULL;
	}
}

Stack::~Stack() {
	while (!isEmpty()) {
		this->pop();
	}
}

bool Stack::isEmpty() const {
	if (topPtr == NULL) {
		return true;
	}

	else {
		return false;
	}
}

bool Stack::push(const StackItemType& newItem) {
	StackNode* newPtr = new StackNode;

	// Adding to the head
	newPtr->data = newItem;

	newPtr->next = topPtr;
	topPtr = newPtr;

	return true;
}

bool Stack::pop() {
	if (this->isEmpty()) {
		return false;
	}

	else {
		StackNode* cur = topPtr; // Keep the first item to avoid memory leak

		topPtr = topPtr->next; // Remove the first node of the linked list since it is the top of the stack

		cur->next = NULL;
		delete cur;
		cur = NULL;

		return true;
	}
}

bool Stack::pop(StackItemType& value) {
	if (this->isEmpty()) {
		return false;
	}

	else {
		StackNode* cur = topPtr; // Keep the first item to avoid memory leak
		value = cur->data; // Return the value to be removed using the parameter list

		topPtr = topPtr->next; // Remove the first node of the linked list since it is the top of the stack

		cur->next = NULL;
		delete cur;
		cur = NULL;

		return true;
	}
}

bool Stack::getTop(StackItemType& value) const {
	if (this->isEmpty()) {
		return false;
	}

	else {
		value = topPtr->data; // Return the value using the parameter list

		return true;
	}
}

void Stack::emptyStack() {
	while (!isEmpty()) {
		this->pop();
	}
}

// Deep copying the parameter stack
Stack& Stack::operator=(const Stack& right) {
	// First empty the stack to make the copy of the right
	this->emptyStack();

	// If the stack to be copied is empty
	if (right.topPtr == NULL) {
		this->topPtr = NULL;
	}

	else {
		// Copying the first node
		topPtr = new StackNode;
		topPtr->data = right.topPtr->data;

		// Copying the rest
		StackNode* newNode = topPtr;
		for (StackNode* origPtr = right.topPtr->next; origPtr != NULL; origPtr = origPtr->next) {
			newNode->next = new StackNode;
			newNode = newNode->next;
			newNode->data = origPtr->data;
		}
		newNode->next = NULL;
	}

	return *this;
}
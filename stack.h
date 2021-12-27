#pragma once

//Includes
#include <iostream>
using namespace std;

class Stack {
private:
	//Node class for Stack
	class Node_s {
	public:
		int data;
		Node_s* prev;
	};

public:
	size_t size;
	Node_s* peek;

	//Stack Constructor
	Stack() {
		peek = NULL;
		size = 0;
	}

	//Stack Destructor 
	~Stack() {
		while (!isEmpty())   pop();
	}

	//Stack Push Node function 
	void push(int data) {
		Node_s* temp = new Node_s;
		temp = peek;
		peek = new Node_s;
		peek->data = data;
		peek->prev = temp;
		size++;
	}

	//Deleting the element from the Stack and returning
	int pop() {
		if (isEmpty())
			throw std::invalid_argument("The stack is empty");
		else {
			int last_data = peek->data;
			Node_s* temp = new Node_s;
			temp = peek->prev;
			delete peek;
			peek = temp;
			size--;
			return last_data;
		}
	}

	//Checking function if Stack isEmpty or not
	bool isEmpty() { return size == 0; }
};
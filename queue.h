#pragma once

//Includes
#include <iostream>
using namespace std;

class Queue {

private:
	//Node class for Queue
	class Node_q {
	public:
		int data;
		Node_q* next;
	};
	Node_q* front;
	Node_q* rear;
	int size;

public:
	//Queue Constructor
	Queue() {
		front = NULL;
		rear = front;
		size = 0;
	}
	
	//Queue Destructor
	~Queue() {
		while (size > 0)   pop();
	}

	//Queue Push Node function
	void push(int data) {
		if (size == 0) {
			front = new Node_q;
			front->data = data;
			rear = front;
		}
		else {
			rear = rear->next = new Node_q;
			rear->data = data;
		}
		size++;
	}

	//Dele the element from the Stack and returning
	int pop() {
		if (isEmpty())
			throw std::out_of_range::out_of_range("The queue is empty");
		else {
			int peek_data = front->data;
			Node_q* temp = new Node_q;
			temp = front->next;
			delete front;
			front = temp;
			size--;
			return peek_data;
		}
	}

	//Checking function if Queue isEmpty or not
	bool isEmpty() { return size == 0; }
};
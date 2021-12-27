#pragma once

#include "stack.h"
#include "queue.h"
#include "iterator.h"

class Tree {

private:
	//Node Class
	class Node {
	public:
		int data = 0;
		Node *left, *right;
	};

public:
	size_t size;
	Node* tail;
	Node* root;//Pointer on a Starting element 

	//Iterator declaration
	Iterator* create_dft_iterator();
	Iterator* create_bft_iterator();

	
	class TreeIterator_s : public Iterator {
	public:
		bool has_next() override;
		int next() override;

		//Constructor for the Iterator for Stack
		TreeIterator_s(Node* root) {
			current = root;
			stack.push(current->data);
		}

	private:
		bool check = false;
		Stack stack;
		Node* root;
		Node* current;
	};


	class TreeIterator_q : public Iterator {
	public:
		bool has_next() override;
		int next() override;

		//Constructor for the Iterator for Queue
		TreeIterator_q(Node* root) {
			current = root;
			queue.push(current->data);
		}
	private:
		Queue queue;
		Node* current;
		Node* root;
		bool check = false;
	
	};
	
	//Tree Constructor
	Tree() {
		root = NULL;
		tail = NULL;
		size = 0;
	}
	
	//Tree Constructor with argument
	Tree(int data) {
		Node* current = new Node;
		current->data = data;
		current->left = current->right = NULL;
		root = current;
		tail = current;
		size = 1;
	}
	
	//Tree Destructor
	~Tree() {
		while (size != 0) {
			remove(root->data);
		}
	}

	//Inserting Element Tree function
	void insert(int data)
	{
		if (root == NULL) {
			Node* current = new Node;
			current->data = data;
			current->left = current->right = NULL;
			root = current;
			tail = current;
			size++;
		}
		else {
			Node* current = tail;
			if (data < current->data)
			{
				if (current->left != NULL) {
					current = current->left;
					tail = current;
					insert(data);
				}
				else
				{
					current->left = new Node;
					current = current->left;
					current->left = NULL;
					current->right = NULL;
					current->data = data;
					tail = root;
					size++;
				}
			}

			if (data > current->data)
			{
				if (current->right != NULL) {
					current = current->right;
					tail = current;
					insert(data);
				}
				else
				{
					current->right = new Node;
					current = current->right;
					current->left = NULL;
					current->right = NULL;
					current->data = data;
					tail = root;
					size++;
				}
			}
		}
		tail = root;
	}

	//Finding Element Tree function
	bool contains(int data) {
		bool Existence = false;
		if (root == NULL) {
			throw invalid_argument("Tree is empty");
		}
		else {
			Node* current = tail;
			if (data == current->data) {
				Existence = true;
				tail = root;
				return Existence;
			}
			else {
				if ((data < current->data) && (current->left != NULL)) {
					current = current->left;
					tail = current;
					if (data == current->data) {
						Existence = true;
						tail = root;
						return Existence;
					}
					if ((current->left == NULL) && (current->right == NULL)) {
						tail = root;
						return Existence;
					}
					else contains(data);
				}
				if ((data > current->data) && (current->right != NULL)) {
					current = current->right;
					tail = current;
					if (data == current->data) {
						Existence = true;
						tail = root;
						return Existence;
					}
					if ((current->left == NULL) && (current->right == NULL)) {
						tail = root;
						return Existence;
					}
					else contains(data);
				}
				else {
					tail = root;
					return Existence;
				}
			}
		}
	}

	//Removing Element Tree function
	void remove(int data) {
		if (root == NULL) {
			throw invalid_argument("List is empty");
		}
		else {
			Node* current = tail;
			if (data == current->data) {
				if ((current->left == NULL) && (current->right == NULL)) {
					current = NULL;
					tail = root;
					size--;
					return;
				}
				else {
					if ((root->right == NULL) && (root->left != NULL)) {
						Node* dopcurrent = root;
						root = root->left;
						size--;
						tail = root;
						delete dopcurrent;
						return;
					}
					Node* dopcurrent = current;
					Node* remove_elem = current;
					dopcurrent = dopcurrent->right;
					int min_elem = dopcurrent->data;
					while (dopcurrent->left != NULL) {
						current = dopcurrent;
						dopcurrent = dopcurrent->left;
						if (dopcurrent->left == NULL) {
							min_elem = dopcurrent->data;
							break;
						}
					}
					if ((root->right == NULL) && (root->left == NULL)) {
						delete root;
						root = NULL;
						size--;
						return;
					}

					if (current == root) {
						current->data = dopcurrent->data;
						current->right = dopcurrent->right;
						dopcurrent->right = NULL;
						tail = root;
						size--;
						return;
					}
					if ((dopcurrent->right != NULL) && (dopcurrent->left == NULL)) {
						current->left = dopcurrent->right;
						delete dopcurrent->right;
						current->left->right = NULL;
						remove_elem->data = min_elem;
						tail = root;
						size--;
						return;
					}
					else {
						remove_elem->data = min_elem;
						delete dopcurrent;
						current->left = NULL;
						tail = root;
						size--;
						return;
					}
				}
			}
			else {
				if ((data == root->data) && (root->right == NULL)) {
					current = root;
					root = root->left;
					delete current;
					size--;
					return;
				}
				if ((data == root->data) && (root->left == NULL)) {
					current = root;
					root = root->right;
					delete current;
					size--;
					return;
				}

				if (current->left != NULL) {
					if (data == current->left->data) {
						if ((current->left->left == NULL) && (current->left->right != NULL)) {
							Node* dopcurrent = current->left;
							current->left = dopcurrent->right;
							delete dopcurrent;
							tail = root;
							size--;
							return;
						}
						if ((current->left->left != NULL) && (current->left->right == NULL)) {
							Node* dopcurrent = current->left;
							current->left = dopcurrent->left;
							delete dopcurrent;
							tail = root;
							size--;
							return;
						}
					}
				}
				if (current->right != NULL) {
					if (data == current->right->data) {
						if ((current->right->left == NULL) && (current->right->right != NULL)) {
							Node* dopcurrent = current->right;
							current->right = dopcurrent->right;
							delete dopcurrent;
							tail = root;
							size--;
							return;
						}
						if ((current->right->left != NULL) && (current->right->right == NULL)) {
							Node* dopcurrent = current->right;
							current->right = dopcurrent->left;
							delete dopcurrent;
							tail = root;
							size--;
							return;
						}
					}
				}
				if ((current->right == NULL) && (current->left == NULL)) {
					throw invalid_argument("Element doesn't exist");
				}
				if (data > current->data) {
					current = current->right;
					tail = current;
				}
				if (data < current->data) {
					current = current->left;
					tail = current;
				}
				remove(data);
			}
		}
	}
};


//Stack Iterator Implementation
Iterator* Tree::create_dft_iterator() {
	return new TreeIterator_s(root);
}

int Tree::TreeIterator_s::next() {
	if (!has_next()) {
		throw out_of_range("Error: No elements");
	}
	else {
		int temp = stack.pop();
		if (check == false) {
			root = current;
			check = true;
		}
		current = root;
		while (current->data != temp) {
			if (temp < current->data) {
				current = current->left;
			}
			if (temp > current->data) {
				current = current->right;
			}
		}

		if (current->right != NULL) {
			stack.push(current->right->data);
		}
		if (current->left != NULL) {
			stack.push(current->left->data);
		}

		return temp;
	}
}

//If Stack is not Empty then it has next element
bool Tree::TreeIterator_s::has_next() {
	return !stack.isEmpty();
}

//Queue Iterator Implementation
Iterator* Tree::create_bft_iterator() {
	return new TreeIterator_q(root);
}
int Tree::TreeIterator_q::next() {
	if (!has_next()) {
		throw out_of_range("No more elements");
	}
	else {
		int temp = queue.pop();
		if (check == false) {
			root = current;
			check = true;
		}
		current = root;
		while (current->data != temp) {
			if (temp < current->data) {
				current = current->left;
			}
			if (temp > current->data) {
				current = current->right;
			}
		}
		if (current->left != NULL) {
			queue.push(current->left->data);
		}
		if (current->right != NULL) {
			queue.push(current->right->data);
		}
		return temp;
	}
}

//If queue is not Empty then it has next element
bool Tree::TreeIterator_q::has_next() {
	return !queue.isEmpty();
}
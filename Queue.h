#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* nextNode;

	Node() {
		data = 0;
		nextNode = NULL;
	}

	Node(int data) {
		this->data = data;
		this->nextNode = NULL;
	}
};

class Queue {
	Node* headerPtr;
	int numItems;
public:
	Queue() {
		headerPtr = NULL;
	}
	int size();
	void push(int data); //places element in the back of the queue
	void pop(); //removes first element of the queue
	int front(); //returns value of the first element in the queue
	bool empty(); //returns true if queue is empty, false otherwise
	void print(); //prints the queue
};
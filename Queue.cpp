#include "Queue.h"

int Queue::size() {
	return numItems;
}
void Queue::push(int data) { //push element to back of queue
	Node* newNode = new Node(data);
	if (headerPtr == NULL) { //queue is empty
		headerPtr = newNode;
		numItems++;
		return;
	}
	Node* temp = headerPtr;
	while (temp->nextNode != NULL) { //traverse to end of queue
		temp = temp->nextNode;
	}
	temp->nextNode = newNode; //make previously last value point to new last value that has just been created
	numItems++;
}

void Queue::pop() { //remove element from front of queue
	if (headerPtr == NULL) { //queue is empty
		cout << "pop attempted, but queue was empty." << endl;
		return;
	}
	else if (headerPtr->nextNode == NULL) { //only 1 item in queue
		delete headerPtr;
		headerPtr = NULL;
		numItems--;
	}
	else {
		Node* temp = headerPtr;
		headerPtr = headerPtr->nextNode; //second value in queue is now the first value in the queue
		delete temp; //delete original first value
		numItems--;
	}
}

int Queue::front() { //returns the header pointer of the queue
	if (headerPtr == NULL) {
		return -1;
	}
	else {
		return headerPtr->data;
	}

}

bool Queue::empty() { //returns a boolean (queue empty (T) or not? (F))
	if (headerPtr == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void Queue::print() { //this is just for testing purposes; prints queue
	Node* temp = headerPtr;
	if (temp == NULL) {
		cout << "Queue is empty. Nothing to print." << endl;
	}
	else {
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->nextNode;
		}
	}
	cout << endl;
}
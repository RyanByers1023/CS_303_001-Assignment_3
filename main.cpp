#include "InfixConverter.h"
#include "Queue.h"

int main() {
	cout << "-----------Testing for infix to postfix conversion functions-----------" << endl;
	string userInput;
	string result;
	userInput = getInput();
	while (!BalanceCheck(userInput)) {
		cout << "The input provided has been determined to include unbalanced brackets. Please enter an expression which contains brackets that are balanced:";
		cin >> userInput;
	}
	result = ConvertToPostfix(userInput);
	cout << "The expression you have provided expressed in postfix: " << result << endl;


	cout << "-----------Testing for queue functions-----------" << endl;
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << "Current queue after q.push(1-4): " << endl;
	q.print();
	q.pop();
	q.pop();
	cout << "Current queue after running q.pop() twice: " << endl;
	q.print();
	cout << "Size of queue right now: " << q.size() << " items." << endl;
	cout << "The front of the queue is: " << q.front() << endl;
	cout << "Running q.empty() right now: " << endl;
	if (q.empty()) {
		cout << "Queue is empty." << endl;
	}
	else {
		cout << "Queue is not empty." << endl;
	}
	q.pop();
	q.pop();
	cout << "Current queue after running q.pop() twice: " << endl;
	q.print();
	cout << "Running q.empty() right now: " << endl;
	if (q.empty()) {
		cout << "Queue is empty." << endl;
	}
	else {
		cout << "Queue is not empty." << endl;
	}
}
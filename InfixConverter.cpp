#include "InfixConverter.h"

string getInput() {//gets an expression from user and returns input as a string
	string userInput;
	cout << "Enter an expression in infix form (eg: (a-j)+b ): ";
	cin >> userInput;
	return userInput;
}

bool BalanceCheck(string userInput) { //takes in a expression as a string in infix form and outputs true or false depending on whether or not the brackets in said string are balanced
	stack<char> bracketStack; //will store opening brackets here
	for (int i = 0; i < userInput.length(); i++) { //looping through user's input (stored as a string)
		if (userInput[i] == '{' || userInput[i] == '(' || userInput[i] == '[') { //is the current character an opening bracket?
			bracketStack.push(userInput[i]); //if so, push it to the stack
		}
		else if (userInput[i] == '}' || userInput[i] == ')' || userInput[i] == ']') { //is the current charcter a closing bracket?
			if (bracketStack.empty()) { //is the stack empty?
				return false; //if so, expression is unbalanced, we have as of yet only encountered a closing bracket.
			}
			switch (bracketStack.top()) { //need to make sure closing bracket we have come across is matching the opening bracket we already have at the top of the stack
			case '{':
				if (userInput[i] == '}') {
					bracketStack.pop();
				}
				else {
					return false;
				}
				break;
			case'(':
				if (userInput[i] == ')') {
					bracketStack.pop();
				}
				else {
					return false;
				}
				break;
			case'[':
				if (userInput[i] == ']') {
					bracketStack.pop();
				}
				else {
					return false;
				}
				break;
			}
		}
	}
	if (bracketStack.empty()) {//brackets were determined to all be balanced.
		return true;
	}
	else {
		return false;
	}
}

int detPrec(char op) { //determines the precedence of various operators (is used in ConvertToPostFix function to reduce clutter) and returns a corresponding value as an int (considers '*', '/', '%', '+', and '-')
	switch (op) {
	case '/':
	case '*':
	case '%':
		return 2;
	case '+':
	case '-':
		return 1;
	}
	return -1;
}

string ConvertToPostfix(string userInput) { //takes in a string in infix form and converts it to postfix form and returns it as a string
	stack<char> operators;
	string result;

	for (int i = 0; i < userInput.size(); i++) {
		if ((userInput[i] >= 'a' && userInput[i] <= 'z') || (userInput[i] >= 'A' && userInput[i] <= 'Z') || (userInput[i] >= '0' && userInput[i] <= '9')) { //is the current character is a operand (a-z or A-Z or 0-9)?
			result += userInput[i]; //if so, push the charcter to the end result string
		}
		else if (userInput[i] == '{' || userInput[i] == '(' || userInput[i] == '[') { //is the next character is an opening bracket?
			operators.push(userInput[i]); //if so, push opening bracket to stack
		}
		else if (userInput[i] == '}' || userInput[i] == ')' || userInput[i] == ']') { //is the next character is a closing bracket?
			switch (userInput[i]) {
			case '}':
				while (operators.top() != '{') { //if so, while the top of the stack is not equal to the equivalent opening bracket (in this case, '{')...
					result += operators.top(); //add the value located at the top of the stack to the end result string...
					operators.pop(); // and remove the value at the top of the stack
				}
				break;
			case')':
				while (operators.top() != '(') {
					result += operators.top();
					operators.pop();
				}
				break;
			case']':
				while (operators.top() != '[') {
					result += operators.top();
					operators.pop();
				}
				break;
			}
			operators.pop(); //we found the closing bracket, remove it from the top of the stack
		}
		else { //operator is the next character in userInput
			while (!operators.empty() && detPrec(operators.top()) >= detPrec(userInput[i])) { //stack not empty and the character on the top of the stack has precedence over the next character in the user's inputted expression
				result += operators.top(); //add the character at the top of the stack to the end result string
				operators.pop(); //remove the item we just added from the top of the stack
			}
			operators.push(userInput[i]); //the next character in user's string has precedence over that which is currently residing at the top of the stack
		}
	}
	while (!operators.empty()) { //all of the remaining elements in the stack can be added to the final result and popped from the stack
		result += operators.top();
		operators.pop();
	}
	return result;
}

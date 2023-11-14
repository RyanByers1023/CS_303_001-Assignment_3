#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string getInput(); //get input from user in infix form
bool BalanceCheck(string userInput); //takes in a expression as a string in infix form and outputs true or false depending on whether or not the brackets in said string are balanced (considers "{}", "()", and "[]")
int detPrec(char op); //determines the precedence of various operators (is used in ConvertToPostFix function to reduce clutter) and returns a corresponding value as an int (considers '*', '/', '%', '+', and '-')
string ConvertToPostfix(string userInput); //takes in a string in infix form and converts it to postfix form and returns it as a string
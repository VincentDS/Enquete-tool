/*
 * question.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//checks the amount of questions in the enquete
int NumberOfSteps(string stepsstring) {
	string tmp;  //temporary string to insert "STEPS" before we can acquire the steps integer.
	int steps;
	istringstream stepsstream(stepsstring);
	stepsstream >> tmp;
	stepsstream >> steps;
	return steps;
}

//analyzes the type of question, given a random questionline.
string QuestionType(string question) {
	istringstream questionstream(question);
	string questionnumber;
	string questiontype;
	questionstream >> questionnumber;
	questionstream >> questiontype;
	return questiontype;
}

//gives the Nth word of a string
string GetNthStringElement(int n, string input){
	istringstream inputstream(input);
	string result;
	for (int i=0; i<n; i++) {
		inputstream >> result;
	}
	return result;
}

//gives the resuming words of a string, starting with the nth word
string GetSubstring(int n, string input){
	istringstream inputstream(input);
	string result;
	for (int i=0; i<(n-1); i++) {
		inputstream >> result;
	}
	getline(inputstream, result);
	return result;
}

void PrintQuestion(string number, string text){
	cout << "Vraag " << number <<": " << text << endl;
}


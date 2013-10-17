/*
 * asker.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <fstream> //for file-access
#include <string>
#include <sstream>
#include "asker.h"
using namespace std;


//checks if the 2 correct files are passed.
bool CorrectArguments(int argc, const char *argv[]) {
	if (argc != 3) {
		cout << "invalid amount of arguments" <<endl;
		return false;
	}
	else if ((strcmp(argv[1], "enquetespecificatie.txt") != 0) ||
			(strcmp(argv[2], "antwoordbestand.txt") != 0) ) {
		cout << "invalid arguments passed" <<endl;
		return false;
	}
	else {
		return true;
	}
}


//prints intro with the filenames
void Intro(const char *argv[]) {
	cout << "vdeschut@vub.ac.be " << "taak1 " << argv[1] << " " << argv[2] << endl;
}


//prints outro with the filename to which the answers are passed
void Outro(const char *argv[]) {
	cout << "Antwoordbestand weggeschreven naar \"" << argv[2] << "\"." << endl;
}


//checks the amount of questions in the enquete
int NumberOfSteps(string stepsstring) {
	string tmp;  // temporary string to insert "STEPS" before we can acquire the steps integer.
	int steps;
	istringstream stepsstream(stepsstring);
	stepsstream >> tmp;
	stepsstream >> steps;
	return steps;
}


string QuestionType(string question) {
	istringstream questionstream(question);
	string questionnumber;
	string questiontype;
	questionstream >> questionnumber;
	questionstream >> questiontype;
	return questiontype;
}


string GetNthStringElement(int n, string input){
	istringstream inputstream(input);
	string result;
	for (int i=0; i<n; i++) {
		inputstream >> result;
	}
	return result;
}


string GetSubstring(int n, string input){
	istringstream inputstream(input);
	string result;
	for (int i=0; i<(n-1); i++) {
		inputstream >> result;
	}
	getline(inputstream, result);
	return result;
}


void TextParser(string question) {
	string questionnumber(GetNthStringElement(1, question));
	string questiontext(GetSubstring(3, question));

	PrintQuestion(questionnumber, questiontext);
}


void ChoiceParser(string question) {
	string questionnumber(GetNthStringElement(1, question));
	string numberofchoices(GetNthStringElement(3, question));
	string questiontext(GetSubstring(4, question));

	PrintQuestion(questionnumber, questiontext);
}


void PrintQuestion(string number, string text){
	cout << "Vraag " << number <<": " << text << endl;
}


int AmountOfChoices(string question){
	string numberofchoices(GetNthStringElement(3, question));
	istringstream buffer(numberofchoices); //making integer from string
	int value;
	buffer >> value;
	return value;
}


void PrintChoices(ifstream& specification, string question){
	int choices(AmountOfChoices(question));
	string result;
	for (int i=1; i<=choices; i++) {
		getline(specification, result);
		cout << i << ") " << result << endl;
	}
}


void WriteUserInput(string number, ofstream& answers){
	string userinput;
	while (getline(cin, userinput)) {
		answers << number << " " << userinput << endl;
		break;
	}
	cout << "OK." << endl;
}


void asker(ifstream& specification, ofstream& answers) {

	string version;
	string id;
	string steps;
	string question;

	getline(specification, version);
	getline(specification, id);
	getline(specification, steps);

	cout << "Deze enquete bestaat uit " << NumberOfSteps(steps) << " vragen." << endl << endl;
	answers << id << endl;


	while (!specification.eof()) {
		getline(specification, question);
		string questionnumber(GetNthStringElement(1, question));

		if (QuestionType(question) == "TEXT") {
			TextParser(question);
			WriteUserInput(questionnumber, answers);
		}
		else if (QuestionType(question) == "CHOICE") {
			ChoiceParser(question);
			PrintChoices(specification, question);
			WriteUserInput(questionnumber, answers);
		}
		else {
			cout << "invalid question type." << endl;
		}
	}


	cout << endl << "Bedankt voor je deelname." << endl;
}


int main(int argc, const char *argv[]) {
	if (CorrectArguments(argc, argv)) {
		ifstream specification(argv[1]);
		ofstream answers(argv[2]);

		Intro(argv);
		asker(specification, answers);
		Outro(argv);
	}
	return 0;
}

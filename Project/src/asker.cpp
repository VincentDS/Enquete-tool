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
bool correctarguments(int argc, const char *argv[]) {
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
void intro(const char *argv[]) {
	cout << "vdeschut@vub.ac.be " << "taak1 " << argv[1] << " " << argv[2] << endl;
}

//prints outro with the filename to which the answers are passed
void outro(const char *argv[]) {
	cout << "Antwoordbestand weggeschreven naar \"" << argv[2] << "\"." << endl;
}


//checks the amount of questions in the enquete
int numberofsteps(string stepsstring) {
	string tmp;  // temporary string to insert "STEPS" before we can acquire the steps integer.
	int steps;
	istringstream stepsstream(stepsstring);
	stepsstream >> tmp;
	stepsstream >> steps;
	return steps;
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

string questiontype(string question) {
	istringstream questionstream(question);
	string questionnumber;
	string questiontype;
	questionstream >> questionnumber;
	questionstream >> questiontype;
	return questiontype;
}

void textparser(string question) {
	string questionnumber(GetNthStringElement(1, question));
	string questiontext(GetSubstring(3, question));

	cout << questiontext << endl;
}


void asker(ifstream& specification, ofstream& answers) {

	string version;
	string id;
	string steps;
	string questions;
	string newline("\n");

	string question;

	getline(specification, version);
	getline(specification, id);
	getline(specification, steps);

	cout << "Deze enquete bestaat uit " << numberofsteps(steps) << " vragen." << endl << endl;
	answers << id << newline;


	while (!specification.eof()) {
	getline(specification, question);
	if (questiontype(question) == "TEXT") {
		textparser(question);
	}
	else if (questiontype(question) == "CHOICE") {
		cout << "this is choice" << endl;
	}
	else {
		cout << "invalid question type." << endl;
	}
	}

//	cout << "Vraag " << questionparser(questions, "number") <<": " << questionparser(questions, "text") << endl;
//	while (getline(cin, question)) {
//		answers << questionparser(questions, "number") << " " << question << endl;
//		break;
//	}




	cout << "Bedankt voor je deelname." << endl;
}


int main(int argc, const char *argv[]) {
	if (correctarguments(argc, argv)) {
		ifstream specification(argv[1]);
		ofstream answers(argv[2]);

		intro(argv);
		asker(specification, answers);
		outro(argv);
	}
	return 0;
}

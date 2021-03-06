/*
 * asker.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "question.h"
#include "text.h"
#include "choice.h"
#include "userinput.h"
#include "utilities.h"
using namespace std;


//checks if the 2 correct files are passed.
bool CorrectArguments(int argc, const char *argv[]) {
	if (argc != 3) {//amount of arguments must be 3 (name of function + 2 arguments)
		cout << "invalid amount of arguments" << endl;
		return false;
	}
	else {
		string enquetepath = argv[1];
		string answerspath = argv[2];
		if (!(CorrectExtension(enquetepath, ".ens")) || !(CorrectExtension(answerspath, ".ena"))) {
			cout << "invalid arguments passed" << endl;
			return false;
		}
		else {
			return true;
		}
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

		if (QuestionType(question) == "TEXT") {
			TextParser(question);
			WriteUserInput(question, answers);
		}
		else if (QuestionType(question) == "CHOICE") {
			ChoiceParser(question);
			PrintChoices(specification, question);
			WriteUserInput(question, answers);
		}
		else {
			cout << "invalid question type." << endl;
		}
	}

	cout << endl << "Bedankt voor je deelname." << endl;
}

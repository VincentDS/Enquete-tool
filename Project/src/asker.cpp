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


bool correctarguments(int argc, const char *argv[]) { //checks if the 2 correct files are passed.
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


void intro(const char *argv[]) {
	cout << "vdeschut@vub.ac.be " << "taak1 " << argv[1] << " " << argv[2] << endl;
}

void outro(const char *argv[]) {
	cout << "Antwoordbestand weggeschreven naar \"" << argv[2] << "\"." << endl;
}


int numberofsteps(string stepsstring) {
	string tmp;  // temporary string to insert "STEPS" before we can acquire the steps integer.
	int steps;
	istringstream stepsstream(stepsstring);
	stepsstream >> tmp;
	stepsstream >> steps;
	return steps;
}


void asker(ifstream& specification, ofstream& answers) {

	string version;
	string id;
	string steps;
	string questions;
	string newline("\n");

	getline(specification, version);
	getline(specification, id);
	getline(specification, steps);
	while (!specification.eof()) {
	getline(specification, questions);
	}


	cout << "Deze enquete bestaat uit " << numberofsteps(steps) << " vragen." << endl << endl;

	answers << id;
	answers << newline;

	cout << questions << endl;


	cout << "Bedankt voor je deelname." << endl;
}


int main(int argc, const char *argv[]) {
	if (correctarguments(argc, argv)) {
		ifstream specification(argv[1]);
		ofstream answers(argv[2]);

		intro(argv); //prints intro with the filenames
		asker(specification, answers);
		outro(argv); //prints outro with the filename to which the answers are passed
	}
	return 0;
}

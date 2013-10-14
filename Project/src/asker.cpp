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
using namespace std;

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

	getline(specification, version);
	getline(specification, id);
	getline(specification, steps);
	while (!specification.eof()) {
	getline(specification, questions);
	}


	cout << "Deze enquete bestaat uit " << numberofsteps(steps) << " vragen." << endl << endl;

	cout << "Bedankt voor je deelname." << endl;
}

/*
 * editor.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Question.h"
#include "Survey.h"
using namespace std;

bool CorrectExtension(string path, string extension) {
	if (path.substr(path.find_last_of(".")) == extension) {
	   return true;
	  }
	else {
	    return false;
	  }
}

int NumberOfSteps(string stepsstring) {
	string tmp;  //temporary string to insert "STEPS" before we can acquire the steps integer.
	int steps;
	istringstream stepsstream(stepsstring);
	stepsstream >> tmp;
	stepsstream >> steps;
	return steps;
}

void editor(ifstream& specification) {
	string version;
	string id;
	string steps;
	getline(specification, version);
	getline(specification, id);
	getline(specification, steps);

	Question testquestion(1, "TEXT", "Vind je C++ leuk?");

	cout << testquestion.text() << endl;

	Survey testsurvey(NumberOfSteps(steps));

	cout << testsurvey.getPointer() << endl;
}

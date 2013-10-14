//============================================================================
// Name        : Project.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream> //for file-access
#include <string>
using namespace std;

void asker(ifstream& specification, ofstream& answers) {

	string result;

	while (!specification.eof()) {
	getline(specification, result);
	cout << result << endl;
	}
}


bool correctarguments(int argc, const char *argv[]) { //checks if the 2 correct files are passed.
	if (argc != 3) {
		cout << "invalid amount of arguments" <<endl;
		return false;
	}
	else if ((strcmp(argv[1], "enquetespecificatie.txt") != 0) ||
			(strcmp(argv[2], "antwoordbestand.txt") != 0) ) {
		cout << "invalid arguments passed" <<endl;
		return true;
	}
	else {
		cout << "correct arguments passed!" <<endl;
		return true;
	}
}


int main(int argc, const char *argv[]) {
	correctarguments(argc, argv);
//	ifstream specification(argv[1]);
//	ofstream answers(argv[2]);
//	asker(specification, answers);
	return 0;
}

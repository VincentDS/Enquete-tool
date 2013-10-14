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


int main() {
	ifstream specification("src/enquetespecificatie.txt");
	ofstream answers("src/antwoordbestand.txt");
	asker(specification, answers);
	return 0;
}

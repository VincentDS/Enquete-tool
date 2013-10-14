/*
 * asker.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: vincentdeschutter
 */

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

/*
 * intro-outro.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
using namespace std;

void intro(const char *argv[]) {
	cout << "vdeschut@vub.ac.be " << "taak1 " << argv[1] << " " << argv[2] << endl;
}

void outro(const char *argv[]) {
	cout << "Antwoordbestand weggeschreven naar \"" << argv[2] << "\"." << endl;
}



/*
 * main.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <string>
#include <fstream>
#include "asker.h"
using namespace std;

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


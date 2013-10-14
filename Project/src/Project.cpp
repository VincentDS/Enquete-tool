//============================================================================
// Name        : Project.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream> //for file-access
#include "asker.h"
#include "correctarguments.h"
#include "intro-outro.h"
using namespace std;


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

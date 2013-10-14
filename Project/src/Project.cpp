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
using namespace std;


int main(int argc, const char *argv[]) {
	if (correctarguments(argc, argv)) {
		ifstream specification(argv[1]);
		ofstream answers(argv[2]);
		asker(specification, answers);
	}
	return 0;
}

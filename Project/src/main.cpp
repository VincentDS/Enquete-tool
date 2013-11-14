/*
 * main.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <fstream>
#include "editor.h"
using namespace std;

int main(int argc, const char *argv[]) {
	if (CorrectExtension(argv[1], ".ens")) {
		ifstream specification(argv[1]);
		editor(specification);
	}
	return 0;
}



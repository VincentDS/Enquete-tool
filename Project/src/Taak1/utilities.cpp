/*
 * utilities.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//making integer from string
int StringToInteger(string string) {
	istringstream buffer(string);
	int value;
	buffer >> value;
	return value;
}

//making string from integer
string IntegerToString(int integer) {
	ostringstream buffer;
	buffer << integer;
	return buffer.str();
}

bool CorrectExtension(string path, string extension) {
	if (path.substr(path.find_last_of(".")) == extension) {
	   return true;
	  }
	else {
	    return false;
	  }
}

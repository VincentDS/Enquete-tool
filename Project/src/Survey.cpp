/*
 * Survey.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: vincentdeschutter
 */

#include "Survey.h"

Survey::Survey(int numberofquestions) {
	numberofquestions_ = numberofquestions;
	p = new Question[numberofquestions];
}

Survey::Survey(const Survey& S) {
	numberofquestions_ = S.getNumberofquestions();
	p = new Question[S.getNumberofquestions()];
	p = S.getPointer();
}

Survey& Survey::operator=(const Survey& S) {
	p = S.getPointer();
	return *this;
}

Survey::~Survey() {
	delete[] p;
}


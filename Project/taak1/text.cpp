/*
 * text.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <string>
#include "question.h"
using namespace std;

//reads a textquestion and prints it to the console
void TextParser(string question) {
	string questionnumber(GetNthStringElement(1, question));
	string questiontext(GetSubstring(3, question));
	PrintQuestion(questionnumber, questiontext);
}


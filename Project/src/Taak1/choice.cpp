/*
 * choice.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <string>
#include <fstream>
#include "question.h"
#include "utilities.h"
using namespace std;

//reads a choicequestion and prints it to the console
void ChoiceParser(string question) {
	string questionnumber(GetNthStringElement(1, question));
	string questiontext(GetSubstring(4, question));
	PrintQuestion(questionnumber, questiontext);
}


//gives the amount of choices of a choice question
int AmountOfChoices(string choicequestion){
	string numberofchoices(GetNthStringElement(3, choicequestion));
	return StringToInteger(numberofchoices);
}

//prints all the choices of a choice question
void PrintChoices(ifstream& specification, string question){
	int choices(AmountOfChoices(question));
	string result;
	for (int i=1; i<=choices; i++) {
		getline(specification, result);
		cout << i << ") " << result << endl;
	}
}


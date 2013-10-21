/*
 * userinput.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <string>
#include <fstream>
#include "question.h"
#include "choice.h"
#include "utilities.h"
using namespace std;

//checks if the input matches with the type of question
bool ValidUserInput(string question, string userinput) {
	string questiontype(GetNthStringElement(2, question));
	if (questiontype == "TEXT") {
		if (userinput != "" && userinput != " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (questiontype == "CHOICE") {
		int inputinteger(StringToInteger(userinput));
		string inputstring(IntegerToString(inputinteger));  //makes again a string from the string that was
		//converted to an integer, to compare it with the userinput. if they are the same, there were no other characters
		//than the integer in the inputstring (e.g. 3F (userinput) => 3 (inputinteger) => 3 (inputstring).
		//userinput != inputstring). This is a bugfix when the users gives "a valid choice number"+"a random string".
		int amountofchoices(AmountOfChoices(question));
		if ((inputinteger > 0) && (inputinteger <= amountofchoices) && (userinput == inputstring)){
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

//writes the input to the answers file if it's a valid input
void WriteUserInput(string question, ofstream& answers){
	string questionnumber(GetNthStringElement(1, question));
	string userinput;
	getline(cin, userinput);
	if (ValidUserInput(question, userinput)) {
		answers << questionnumber << " " << userinput << endl;
		cout << "OK." << endl;
	}
	else {
		cout << "Ongeldige input, gelieve opnieuw te proberen." << endl;
		WriteUserInput(question, answers);
	}
}


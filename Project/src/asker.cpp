/*
 * asker.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: vincentdeschutter
 */

#include <iostream>
#include <fstream> //for file-access
#include <string>
#include <sstream>
#include <cmath>
#include "asker.h"
using namespace std;


//checks if the 2 correct files are passed.
bool CorrectArguments(int argc, const char *argv[]) {
	if (argc != 3) {//amount of arguments must be 3 (name of function + 2 arguments)
		cout << "invalid amount of arguments" << endl;
		return false;
	}
	else if ((strcmp(argv[1], "enquetespecificatie.txt") != 0) ||
			(strcmp(argv[2], "antwoordbestand.txt") != 0) ) {
		cout << "invalid arguments passed" << endl;
		return false;
	}
	else {
		return true;
	}
}

//prints intro with the filenames
void Intro(const char *argv[]) {
	cout << "vdeschut@vub.ac.be " << "taak1 " << argv[1] << " " << argv[2] << endl;
}

//prints outro with the filename to which the answers are passed
void Outro(const char *argv[]) {
	cout << "Antwoordbestand weggeschreven naar \"" << argv[2] << "\"." << endl;
}

//checks the amount of questions in the enquete
int NumberOfSteps(string stepsstring) {
	string tmp;  //temporary string to insert "STEPS" before we can acquire the steps integer.
	int steps;
	istringstream stepsstream(stepsstring);
	stepsstream >> tmp;
	stepsstream >> steps;
	return steps;
}

//analyzes the type of question, given a random questionline.
string QuestionType(string question) {
	istringstream questionstream(question);
	string questionnumber;
	string questiontype;
	questionstream >> questionnumber;
	questionstream >> questiontype;
	return questiontype;
}

//gives the Nth word of a string
string GetNthStringElement(int n, string input){
	istringstream inputstream(input);
	string result;
	for (int i=0; i<n; i++) {
		inputstream >> result;
	}
	return result;
}

//gives the resuming words of a string, starting with the nth word
string GetSubstring(int n, string input){
	istringstream inputstream(input);
	string result;
	for (int i=0; i<(n-1); i++) {
		inputstream >> result;
	}
	getline(inputstream, result);
	return result;
}

//reads a question and prints it to the console
void TextParser(string question) {
	string questionnumber(GetNthStringElement(1, question));
	string questiontext(GetSubstring(3, question));

	PrintQuestion(questionnumber, questiontext);
}

//idem TextParser
void ChoiceParser(string question) {
	string questionnumber(GetNthStringElement(1, question));
	string questiontext(GetSubstring(4, question));

	PrintQuestion(questionnumber, questiontext);
}


void PrintQuestion(string number, string text){
	cout << "Vraag " << number <<": " << text << endl;
}

//gives the amount of choices of a choice question
int AmountOfChoices(string choicequestion){
	string numberofchoices(GetNthStringElement(3, choicequestion));
	return StringToInteger(numberofchoices);
}

//making integer from string
int StringToInteger(string string) {
	istringstream buffer(string);
	int value;
	buffer >> value;
	return value;
}

//return the length of an integer (e.g. IntegerLength(35435) = 5)
int IntegerLength(int x) {
	return (floor(log10(abs(x))) + 1);
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
		int amountofchoices(AmountOfChoices(question));
		int allowedinputlength(IntegerLength(amountofchoices)); //size of the userinput must be smaller or equal
		//as the intergerlength of the amount of choices. (e.g. 3F will be an invalid input if there are only 4 choices)
		if ((inputinteger > 0) && (inputinteger <= amountofchoices) && (userinput.size() <= allowedinputlength)){
			return true;
		}
		else {
			return false;
		}
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

void asker(ifstream& specification, ofstream& answers) {
	string version;
	string id;
	string steps;
	string question;
	getline(specification, version);
	getline(specification, id);
	getline(specification, steps);

	cout << "Deze enquete bestaat uit " << NumberOfSteps(steps) << " vragen." << endl << endl;
	answers << id << endl;

	while (!specification.eof()) {
		getline(specification, question);

		if (QuestionType(question) == "TEXT") {
			TextParser(question);
			WriteUserInput(question, answers);
		}
		else if (QuestionType(question) == "CHOICE") {
			ChoiceParser(question);
			PrintChoices(specification, question);
			WriteUserInput(question, answers);
		}
		else {
			cout << "invalid question type." << endl;
		}
	}

	cout << endl << "Bedankt voor je deelname." << endl;
}


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

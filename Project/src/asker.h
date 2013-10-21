/*
 * asker.h
 *
 *  Created on: Oct 14, 2013
 *      Author: vincentdeschutter
 */


#ifndef ASKER_H_

bool CorrectArguments(int argc, const char *argv[]);
void Intro(const char *argv[]);
void Outro(const char *argv[]);
int NumberOfSteps(std::string stepsstring);
std::string QuestionType(std::string question);
std::string GetNthStringElement(int n, std::string input);
std::string GetSubstring(int n, std::string input);
void TextParser(std::string question);
void ChoiceParser(std::string question);
void PrintQuestion(std::string number, std::string text);
int AmountOfChoices(std::string question);
int StringToInteger(std::string string);
std::string IntegerToString(int integer);
void PrintChoices(std::ifstream& specification, std::string question);
bool ValidUserInput(std::string question, std::string userinput);
void WriteUserInput(std::string question, std::ofstream& answers);
void asker(std::ifstream& specification, std::ofstream& answers);

#define ASKER_H_




#endif /* ASKER_H_ */

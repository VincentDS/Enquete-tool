/*
 * Question.h
 *
 *  Created on: Nov 14, 2013
 *      Author: vincentdeschutter
 */

#ifndef QUESTION_H_
#define QUESTION_H_
#include <string>
using namespace std;

class Question {
public:
	Question(int number, string type, string text): number_(number), type_(type), text_(text) {}
	Question(const Question& Q);
	virtual ~Question();

	void setNumber(int newnumber) {number_ = newnumber;}
	void setText(string newtext) {text_ = newtext;}

	int number() {return number_;}
	string type() const {return type_;}
	string text() {return text_;}

private:
	int number_;
	const string type_;
	string text_;
};


#endif /* QUESTION_H_ */

/*
 * Survey.h
 *
 *  Created on: Nov 14, 2013
 *      Author: vincentdeschutter
 */

#ifndef SURVEY_H_
#define SURVEY_H_
#include "Question.h"
using namespace std;

class Survey {
public:
	Survey(int numberofquestions);
	Survey(const Survey& S);
	Survey& operator=(const Survey& S);
	virtual ~Survey();


	void addQuestion(Question question) {
		*p = question;
		numberofquestions_++;
	}

	Question getQuestion() {
		Question question(*p);
		return question;
	}

	int getNumberofquestions() const {return numberofquestions_;}
	Question* getPointer() const {return p;}

private:
	int numberofquestions_; //amount of questions in the whole specification
	Question* p; //pointer to the array with questions
};


#endif /* SURVEY_H_ */

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
void asker(std::ifstream& specification, std::ofstream& answers);

#define ASKER_H_




#endif /* ASKER_H_ */

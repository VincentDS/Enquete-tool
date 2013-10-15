/*
 * asker.h
 *
 *  Created on: Oct 14, 2013
 *      Author: vincentdeschutter
 */


#ifndef ASKER_H_

bool correctarguments(int argc, const char *argv[]);
void intro(const char *argv[]);
void outro(const char *argv[]);
int numberofsteps(std::string stepsstring);
void asker(std::ifstream& specification, std::ofstream& answers);

#define ASKER_H_




#endif /* ASKER_H_ */

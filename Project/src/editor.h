/*
 * editor.h
 *
 *  Created on: Nov 14, 2013
 *      Author: vincentdeschutter
 */

#ifndef EDITOR_H_
#define EDITOR_H_

bool CorrectExtension(std::string path, std::string extension);
void editor(std::ifstream& specification);
int NumberOfSteps(std::string stepsstring);

#endif /* EDITOR_H_ */

//
// Created by Ryan Perkins on 11/09/2022.
//

#include "requirements.h"

#ifndef STUDY_BUD_UTILITIES_H
#define STUDY_BUD_UTILITIES_H


bool forbiddenChar(const std::string& entry); // check for input of forbidden characters in filenames
int integerHandling(int input, int target, const std::string& status, int increment);// loop if integer failure is found
bool checkStringLength(const std::string& entry, int target); // check if string length is less than target

#endif //STUDY_BUD_UTILITIES_H

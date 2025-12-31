#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

// check if input is a valid integer
bool isNumber(const std::string& input);

// get a validated integer within a range
int getValidatedInt(const std::string& prompt, int min, int max);

// get a nonempty string
std::string getValidatedString(const std::string& prompt);

#endif

#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include<stdbool.h>

void mutableToUpper(char* str);
void mutableToLower(char* str);
char* immutableToUpper(const char* str);
char* immutableToLower(const char* str);
void mutableFilter(char* str);
char* immutableFilter(const char* str);
void mutableClearSpace(char* str);
char* immutableClearSpace(const char* str);
void mutableStrip(char* str);
char* immutableStrip(const char* str);
bool isNumber(const char* str);
bool isLetters(const char* str);
char* stringCopy(const char* str);
int stringToInteger(const char* str);

#endif

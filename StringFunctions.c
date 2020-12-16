#include<string.h>
#include"StringFunctions.h"
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

static const char Distance = 'a' - 'A';

void mutableToUpper(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if ((str[i] >= 'a') && (str[i] <= 'z')) {
			str[i] -= Distance;
		}
	}
}

void mutableToLower(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) {
			str[i] += Distance;
		}
	}
}

char* immutableToUpper(const char* str) {
	char* destptr = stringCopy(str);
	mutableToUpper(destptr);
	return destptr;
}

char* immutableToLower(const char* str) {
	char* destptr = stringCopy(str);
	mutableToLower(destptr);
	return destptr;
}

void mutableFilter(char* str) {
	int j = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (((str[i] >= '0') && (str[i] <= '9'))  
		||  ((str[i] >= 'A') && (str[i] <= 'Z')) 
		||  ((str[i] >= 'a') && (str[i] <= 'z')) 
		||   (str[i] == ' ')) {
			str[j] = str[i];
			++j;
		}
	}
	str[j] = '\0';
}

char* immutableFilter(const char* str) {
	char* destptr = stringCopy(str);
	mutableFilter(destptr);
	return destptr;
}

void mutableClearSpace(char* str) {
	int j = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] != ' ') {
			str[j] = str[i];
			++j;
		}
	}
	str[j] = '\0';
}

char* immutableClearSpace(const char* str) {
	char* destptr = stringCopy(str);
	mutableClearSpace(destptr);
	return destptr;
}

void mutableStrip(char* str) {
	int strStart, strEnd;
	int i = 0;
	while (str[i] == ' ') {
		++i;
	}
	strStart = i;
	while (str[i] != '\0') {
		str[i - strStart] = str[i];
		++i;
	}
	--i;
	while (str[i] == ' ') {
		--i;
	}
	strEnd = i;
	str[strEnd - strStart + 1] = '\0';
}

char* immutableStrip(const char* str) {
	char* destptr = stringCopy(str);
	mutableStrip(destptr);
	return destptr;
}

long long stringToInteger(const char* str) {
	assert(isInteger(str));
	int j = 0;
	long long result = 0;
	if (str[0] == '-') {
		++j;
	}
	while (str[j] != '\0') {
		result = result * 10 +  str[j] - '0';
		++j;
	}
	if (str[0] == '-') {
		result *= (-1);
	}
	return result;
}

bool isInteger(const char* str) {
	int i = 0;
	if (str[i] == '-') {
		++i;
	}
	if (str[i] == '\0') {
		return false;
	}
	while (str[i] != '\0') {
		if ((str[i] < '0') || (str[i] > '9')) {
			return false;
		}
		++i;
	}
	return true;
}

bool isFloating(const char* str) {
	bool point = false;
	int i = 0;
	if (str[i] == '-') {
		++i;
	}
	while (str[i] != '\0') {
		if (((str[i] < '0') || (str[i] > '9')) && (str[i] != '.')) {
			return false;
		}
		if ((str[i] == '.') && point) {
			return false;
		}
		else if (str[i] == '.') {
			point = true;
		}
		++i;
	}
	return true;
}

bool isLetters(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z')) {
			return false;
		}
	}
	return true;
}

char* stringCopy(const char* str) {
	int num = 1;
	for (int i = 0; str[i] != '\0'; ++i) {
		++num;
	}
	char* destptr = (char*) malloc(sizeof(char) * num);
	strcpy(destptr, str);
	return destptr;
}

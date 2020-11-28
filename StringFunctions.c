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
	for (int i = 0; 1 == 1; ++i) {
		if (str[i] != ' ') {
			strStart = i;
			break;
		}
	}
	if (str[strStart] == '\0') {
		str[0] = str[strStart];
		return;
	}
	for (int i = 0; 1 == 1; ++i) {
		if (str[i] == '\0') {
			strEnd = i;
			break;
		}
	}
	--strEnd;
	for (int i = strEnd; 1 == 1; --i) {
		if (str[i] != ' ') {
			strEnd = i;
			break;
		}
	}
	for (int i = 0; i < strEnd - strStart + 1; ++i) {
		str[i] = str[i + strStart];
	}
	str[strEnd - strStart + 1] = '\0';
}

char* immutableStrip(const char* str) {
	char* destptr = stringCopy(str);
	mutableStrip(destptr);
	return destptr;
}

int stringToInteger(const char* str) {
	assert(isNumber(str));
	int j = 0, result = 0;
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

bool isNumber(const char* str) {
	int i = 0;
	if (str[i] == '-') {
		++i;
	}
	while (str[i] != '\0') {
		if ((str[i] < '0') || (str[i] > '9')) {
			return false;
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









































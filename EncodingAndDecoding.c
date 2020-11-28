#include"EncodingAndDecoding.h"
#include"StringFunctions.h"
#include<stdio.h>

static const char Difference = 'a';

void mutableEncodeCaesar(char* str, int n) {
	if (n < 0) {
		n = 'z' - 'a' + 1 + (n % ('z' - 'a' + 1));
	}
	for (int i = 0; str[i] != '\0'; ++i) {
		if ((str[i] >= 'a') && (str[i] <= 'z')) {
			str[i] = 'a' + ((str[i] - 'a' + n) % ('z' - 'a' + 1));
		}
	}
}

char* immutableEncodeCaesar(const char* str, const int n) {
	char* destptr = stringCopy(str);
	mutableEncodeCaesar(destptr, n);
	return destptr;
}

void mutableDecodeCaesar(char* str, int n) {
	mutableEncodeCaesar(str, -n);
}

char* immutableDecodeCaesar(const char* str, const int n) {
	return immutableEncodeCaesar(str, -n);
}

void mutableEncodeXOR(char* str, const char* code) {
	int j = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (code[j] == '\0') {
			j = 0;
		}
		str[i] = Difference + ((str[i] - Difference) ^ (code[j] - Difference));
		++j;
	}
}

char* immutableEncodeXOR(const char* str, const char* code) {
	char* destptr = stringCopy(str);
	mutableEncodeXOR(destptr, code);
	return destptr;
}

void mutableDecodeXOR(char* str, const char* code) {
	mutableEncodeXOR(str, code);
}

char* immutableDecodeXOR(const char* str, const char* code) {
	char* destptr = stringCopy(str);
	mutableEncodeXOR(destptr, code);
	return destptr;
}

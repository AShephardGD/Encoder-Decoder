#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>
#include"StringFunctions.h"
#include"EncodingAndDecoding.h"

void printCaesar(const char* text, const int n) {
	char* result = immutableDecodeCaesar(text, n);
	printf("Шифр Цезаря:\n");
	printf("Шифруемое слово: %s\n", text);
	printf("Ключевое слово: %d\n", n);
	printf("Результат: %s\n", result);
	free(result);
}

void printXOR(const char* text, const char* code) {
	char* result = immutableDecodeXOR(text, code);
	printf("Шифр XOR:\n");
	printf("Шифруемое слово: %s\n", text);
	printf("Ключевое слово: %s\n", code);
	printf("Результат: %s\n", result);
	free(result);
}

char* inputString() {
	int size = 32, len = 0;
	char* str = (char*) malloc(sizeof(char) * size);
	if (!str) {
		return str;
	}
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		str[len++] = c;
		scanf("%c", &c);
		if (len == size) {
			str = realloc(str, sizeof(char) * (size += 16));
			if (!str) {
				return str;
			}
		}
	}
	str[len++] = '\0';
	return realloc(str, sizeof(char) * len);
}

bool checkInput(const int agrc, char* argv[], char** input) {
	if ((agrc != 4) && (agrc != 1)) {
		return false;
	}
	else if (agrc == 4) {
		input[0] = stringCopy(argv[1]);
		input[1] = stringCopy(argv[2]);
		input[2] = stringCopy(argv[3]);
	}
	else {
		printf("Введите команду: ");
		input[0] = inputString();
		printf("Введите текст: ");
		input[1] = inputString();
		printf("Введите ключевое слово: ");
		input[2] = inputString();
		printf("\n");
	}
	return true;
}
		

int main(int agrc, char* argv[]) {
	const char caesarString[] = "--caesar", XORString[] = "--xor", errorInput[] = "Некорректные данные";
	char** input = (char**) malloc(sizeof(char*) * 3);
	if (!checkInput(agrc, argv, input)) {
		printf("%s\n", errorInput);
		return 0;
	}
	char* command = input[0];
	char* text = input[1];
	char* arguement = input[2];
	int i = -1;
	mutableToLower(text);
	mutableStrip(text);
	if (!strcmp(command, caesarString)) {
		if (!isInteger(arguement)) {
			printf("%s\n", errorInput);
			return 0;
		}
		printCaesar(text, stringToInteger(arguement));
	}
	else if (!strcmp(command, XORString)) {
		printXOR(text, arguement);
	}
	else {
		printf("%s\n", errorInput);
	}
	free(input);
	free(text);
	free(command);
	free(arguement);
	return 0;
}

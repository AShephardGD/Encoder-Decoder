#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include"StringFunctions.h"
#include"EncodingAndDecoding.h"

static const char ErrorInput[] = "Некорректные данные";
static const int StringSize = 100;

void printCaesar(const char* text, const int n) {
	char* result = immutableEncodeCaesar(text, n);
	printf("Шифр Цезаря:\n");
	printf("Шифруемое слово: %s\n", text);
	printf("Ключевое слово: %d\n", n);
	printf("Результат: %s\n", result);
	free(result);
}

void printXOR(const char* text, const char* code) {
	char* result = immutableEncodeXOR(text, code);
	printf("Шифр XOR:\n");
	printf("Шифруемое слово: %s\n", text);
	printf("Ключевое слово: %s\n", code);
	printf("Результат: %s\n", result);
	free(result);
}

int main(int agrc, char* argv[]) {
	const char caesar[] = "--caesar", xor[] = "--xor";
	char* text;
	char* command;
	char* arguement;
	int coder = 1, i = -1;
	if ((agrc != 4) && (agrc != 1)) {
		printf("%s\n", ErrorInput);
		return 0;
	}
	else if (agrc == 4) {
		command = stringCopy(argv[1]);
		text = stringCopy(argv[2]);
		arguement = stringCopy(argv[3]);
	}
	else {
		char arrayText[StringSize], arrayCommand[StringSize], arrayArguement[StringSize];
		printf("Введите команду: ");
		scanf("%s", &arrayCommand);
		printf("Введите текст: ");
		scanf("%s", &arrayText);
		printf("Введите ключевое слово: ");
		scanf("%s", &arrayArguement);
		printf("\n");
		command = stringCopy(arrayCommand);
		text = stringCopy(arrayText);
		arguement = stringCopy(arrayArguement);
	}
	mutableToLower(text);
	mutableStrip(text);
	do {
		++i;
		if (command[i] != caesar[i]) {
			coder = 2;
			break;
		}
	} while (caesar[i] != '\0');
	if (coder == 2) {
		i = 0;
		do {
			++i;
			if (command[i] != xor[i]) {
				coder = 0;
				printf("%s\n", ErrorInput);
				return 0;
			}
		} while (xor[i] != '\0');
	}
	if (coder == 1) {
		if (!isNumber(arguement)) {
			printf("%s\n", ErrorInput);
			return 0;
		}
		int n = stringToInteger(arguement);
		printCaesar(text, n);
	}
	else {
		printXOR(text, arguement);
	}
	free(text);
	free(command);
	free(arguement);
	return 0;
}

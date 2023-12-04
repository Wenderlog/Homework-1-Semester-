#ifndef TASK4_H
#define TASK4_H

#include<stddef.h>
#include<stdio.h>

#define MAX_PHONE_AMOUNT 100
#define MAX_STR_SIZE 100

void positiveToReversedCode(int number, int* array);
void reverseCode(int* number, int* array);
void sum(int* number1, int* number2, int* sum);
int toNormal(int* number);

void myQuickSort(int* array, int low, int high);
const int findMostFrequentElement(int* array, int lengthArray);

void addPhone(
	char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t* size,
	const char* phone,
	const char* name
);
void print(char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t size,
	FILE* fp
);
const char* searchByName(char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t size,
	const char* name
);
const char* searchByPhone(char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t size,
	const char* phone
);

void readFromFile(
	char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t* size,
	const char* filename
);

void writeToFile(
	char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t size,
	const char* filename
);


#endif // TASK4_H


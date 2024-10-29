#include "test.h"
#include "task4.h"

#include<stdio.h>
#include<assert.h>

void testBinary(FILE* fp) {
	fprintf(fp, "бинарный тест: ");
	int number1 = 7;
	int number1_arr[sizeof(int) * 8];
	int expected1[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 };
	positiveToReversedCode(number1, number1_arr);
	for (size_t i = 0; i < sizeof(int) * 8; ++i) {
		assert(expected1[i] == number1_arr[i]);
	}
	int number2 = -3;
	int number2_pos_arr[sizeof(int) * 8];
	positiveToReversedCode(number2 * -1, number2_pos_arr);
	int number2_arr[sizeof(int) * 8];
	reverseCode(number2_pos_arr, number2_arr);
	int expected2[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 };
	for (size_t i = 0; i < sizeof(int) * 8; ++i) {
		assert(expected2[i] == number2_arr[i]);
	}
	int sum_arr[sizeof(int) * 8];
	sum(number1_arr, number2_arr, sum_arr);
	int result = toNormal(sum_arr);
	assert(result == 4);
	fprintf(fp, "завершено\n");
}

void testFindMostFrequentElement(FILE* fp) {
	fprintf(fp, "бинарный тест: ");
	int array[] = {1, 2, 3, 2};
    int result = findMostFrequentElement(array, 4);
	assert(result == 2);
	fprintf(fp, "завершено\n");
}

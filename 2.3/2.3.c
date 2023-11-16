#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

void bubbleSort(int array[], int lengthOfArray) {
	for (int i = 0; i < lengthOfArray - 1; ++i) {
		for (int j = 0; j < lengthOfArray - 1; ++j) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

bool isSorted(int array[], int lengthOfArray) {
	for (int i = 1; i < lengthOfArray; ++i) {
		if (array[i] < array[i - 1]) {
			return false;
		}
	}
	return true;
}

void countingSort(int array[], int lengthOfArray) {
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < lengthOfArray; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	int size = max - min + 1;
	int* count = (int*)calloc(size, sizeof(int));

	for (int i = 0; i < lengthOfArray; ++i)
	{
		count[array[i] - min]++;
	}
	int pos = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < count[i]; ++j)
		{
			array[pos] = i + min;
			pos++;
		}
	}
	free(count);
}

int main() {
	setlocale(LC_ALL, "rus");

	const int lenArray = 100000;
	int* arrayBubleSort = (int*)malloc(lenArray * sizeof(int));
	int* arrayCountingSort = (int*)malloc(lenArray * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < lenArray; i++) {
		int k = rand() % 100 - 20;
		arrayBubleSort[i] = k;
		arrayCountingSort[i] = k;
	}
	clock_t startBubleSort = clock();
	bubbleSort(arrayBubleSort, lenArray);
	clock_t endBubleSort = clock();
	double timeBubleSort = (double)(endBubleSort - startBubleSort) / CLOCKS_PER_SEC;
	clock_t startCountingSort = clock();
	countingSort(arrayCountingSort, lenArray);
	clock_t endCountingeSort = clock();
	double timeCountingSort = (double)(endCountingeSort - startCountingSort) / CLOCKS_PER_SEC;
	printf("Сортировка пузырьком - время %.6f секунд.\n", timeBubleSort);
	printf("Сортировка подсчётом - время %.6f секунд.\n", timeCountingSort);

	if (isSorted(arrayBubleSort, lenArray)) {
		printf("Успешно сортировка пузырьком \n");
	}
	else
	{
		printf("Не успешно сортировка пузырьком\n");
	}

	if (isSorted(arrayCountingSort, lenArray)) {
		printf("Успешно сортировка подсчётом \n");
	}
	else
	{
		printf("Не успешно сортировка подсчётом \n");
	}
	free(arrayBubleSort);
	free(arrayCountingSort);
	return 0;
}
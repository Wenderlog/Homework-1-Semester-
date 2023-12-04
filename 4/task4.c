#include"task4.h"

#include <string.h>

void positiveToReversedCode(int number, int* array) {
	for (size_t i = 0; i < sizeof(int) * 8; ++i) {
		array[sizeof(int) * 8 - 1 - i] = (number & 1);
		number >>= 1;
	}
}
void reverseCode(int* number, int* array) {
	int add = 0;
	for (size_t i = 0; i < sizeof(int) * 8; ++i) {
		if (number[sizeof(int) * 8 - 1 - i] + add == 2) {
			array[sizeof(int) * 8 - 1 - i] = 0;
			add = 1;
		}
		if (number[sizeof(int) * 8 - 1 - i] + add == 1) {
			array[sizeof(int) * 8 - 1 - i] = 1;
			add = 1;
		}
		if (number[sizeof(int) * 8 - 1 - i] + add == 0) {
			array[sizeof(int) * 8 - 1 - i] = 0;
		}
	}
}

void sum(int* number1, int* number2, int* sum_arr) {
	int add = 0;
	for (size_t i = 0; i < sizeof(int) * 8; ++i) {
		int current = number1[sizeof(int) * 8 - 1 - i] + number2[sizeof(int) * 8 - 1 - i] + add;
		add = current / 2;
		sum_arr[sizeof(int) * 8 - 1 - i] = current % 2;
	}
}

int toNormal(int* number) {
	int result = 0;
	for (size_t i = 1; i < sizeof(int) * 8; ++i) {
		result *= 2;
		result += number[i];
	}
	if (number[0] == 1) {
		result *= -1;
	}
	return result;
}

void addPhone(
	char phones[100][100],
	char names[100][100],
	size_t* size,
	const char* phone,
	const char* name
) {
	if (*size == 100) {
		return;
	}
	strcpy(phones[*size], phone);
	strcpy(names[*size], name);
	++*size;
}

void print(char phones[100][100],
	char names[100][100],
	size_t size,
	FILE* fp
) {
	for (size_t i = 0; i < size; ++i) {
		fprintf("%s %s\n", phones[i], names[i]);
	}
}

const char* searchByName(char phones[100][100],
	char names[100][100],
	size_t size,
	const char* name
) {
	for (size_t i = 0; i < size; ++i) {
		if (!strcmp(names[i], name)) {
			return phones[i];
		}
	}
	return NULL;
}

const char* searchByPhone(char phones[100][100],
	char names[100][100],
	size_t size,
	const char* phone
) {
	for (size_t i = 0; i < size; ++i) {
		if (!strcmp(phones[i], phones)) {
			return names[i];
		}
	}
	return NULL;
}

void readFromFile(
	char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t* size,
	const char* filename
) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		return;
	}
	*size = 0;
	char phone[MAX_STR_SIZE];
	char name[MAX_STR_SIZE];
	while (fscanf("%s%s", phone, name) == 2) {
		strcpy(phones[*size], phone);
		strcpy(names[*size], name);
		++*size;
	}
	fclose(file);
}

void writeToFile(
	char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE],
	size_t size,
	const char* filename
) {
	FILE* file = fopen(filename, "w");
	if (!file) {
		return;
	}
	print(phones, names, size, file);
	fclose(file);
}

void myQuickSort(int* array, int low, int high) {
    int i = low;
    int j = high;

    int pivot = array[(low + (high - low) / 2)];
    do {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            i++;
            if (j > 0) {
                j--;
            }
        }
    } while (i <= j);

    if (i < high) {
        myQuickSort(array, i, high);
    }
    if (j > low) {
        myQuickSort(array, low, j);
    }
}

const int findMostFrequentElement(int* array, int lengthArray) {
    if (lengthArray == 0) {
        return -1;
    }
    myQuickSort(array, 0, lengthArray - 1);
    int maxCount = 1;
    int currentCount = 1;
    int mostFrequentElement = array[0];
    for (int i = 1; i < lengthArray; i++) {
        if (array[i] == array[i - 1]) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mostFrequentElement = array[i];
            }
        }
        else {
            currentCount = 1;
        }
    }

    return mostFrequentElement;
}

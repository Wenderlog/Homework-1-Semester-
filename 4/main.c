#include"task4.h"
#include"test.h"
#include<locale.h>

#include<stdio.h>
#include<assert.h>

int main() {
	setlocale(LC_ALL, "rus");
	testBinary(stdout);
	testFindMostFrequentElement(stdout);
	char phones[MAX_PHONE_AMOUNT][MAX_STR_SIZE];
	char names[MAX_PHONE_AMOUNT][MAX_STR_SIZE];
	size_t size = 0;
	printf("Введите адрес для считывания телефонных номеров: ");
	char address[MAX_STR_SIZE];
	int scanf_result = scanf("%s", address);
	if (scanf_result < 1) {
		printf("ошибка открытия файла, массив телефонов создастся пустым\n");
	}
	else {
		readFromFile(phones, names, &size, address);
	}
	while (1) {
		printf("Выберите операцию: \n");
		printf("0 - выйти \n");
		printf("1 - добавить запись в справочник \n");
		printf("2 - вывести справочник \n");
		printf("3 - найти по номеру телефона \n");
		printf("4 - найти по имени \n");
		int choice;
		scanf("%d", &choice);
		switch (choice) {
		case 0: {
			writeToFile(phones, names, size, address);
			return 0;
		}
		case 1: {
			char phone[MAX_STR_SIZE];
			printf("Введите телефон: ");
			scanf_result = scanf("%s", phone);
			if (scanf_result < 0) {
				printf("ошибка ввода\n");
				break;
			}
			char name[MAX_STR_SIZE];
			printf("Введите имя: ");
			scanf_result = scanf("%s", name);
			if (scanf_result < 0) {
				printf("ошибка ввода\n");
				break;
			}
			addPhone(phones, names, &size, phone, name);
			break;
		}
		case 2: {
			print(phones, names, size, stdout);
			break;
		}
		case 3: {
			char phone[MAX_STR_SIZE];
			printf("Введите телефон: ");
			scanf_result = scanf("%s", phone);
			if (scanf_result < 0) {
				printf("ошибка ввода\n");
				break;
			}
			const char* result = searchByPhone(phones, names, size, phone);
			if (result == NULL) {
				printf("такого телефона нет\n");
			}
			else {
				printf("имя: %s\n", result);
			}
			break;
		}
		case 4: {
			char name[MAX_STR_SIZE];
			printf("Введите имя: ");
			scanf_result = scanf("%s", name);
			if (scanf_result < 0) {
				printf("ошибка ввода\n");
				break;
			}
			const char* result = searchByName(phones, names, size, name);
			if (result == NULL) {
				printf("такого имени нет\n");
			}
			else {
				printf("телефон: %s\n", result);
			}
			break;
		}
		}

	}
}
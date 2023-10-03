#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct PhoneEntry {
    char name[50];
    char number[20];
};

struct PhoneEntry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries < MAX_ENTRIES) {
        printf("Введите имя: ");
        scanf("%s", phonebook[numEntries].name);
        printf("Введите номер: ");
        scanf("%s", phonebook[numEntries].number);
        numEntries++;
        printf("Запись добавлена.\n");
    } else {
        printf("Справочник полон. Удалите некоторые записи, прежде чем добавлять новые.\n");
    }
}

void printEntries() {
    printf("Все записи в справочнике:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

void findNumberByName() {
    char searchName[50];
    printf("Введите имя для поиска: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Найден номер для %s: %s\n", searchName, phonebook[i].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Запись для %s не найдена.\n", searchName);
    }
}

void findNameByNumber() {
    char searchNumber[20];
    printf("Введите номер для поиска: ");
    scanf("%s", searchNumber);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].number, searchNumber) == 0) {
            printf("Найдено имя для номера %s: %s\n", searchNumber, phonebook[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Запись для номера %s не найдена.\n", searchNumber);
    }
}

void saveToFile() {
    FILE *file = fopen("4.3.txt", "w");
    if (file == NULL) {
        perror("Не удалось открыть файл для записи");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s %s\n", phonebook[i].name, phonebook[i].number);
    }

    fclose(file);
    printf("Данные сохранены в файле '4.3.txt'.\n");
}

int main() {
    FILE *file = fopen("4.3.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s", phonebook[numEntries].name, phonebook[numEntries].number) == 2) {
            numEntries++;
        }
        fclose(file);
        printf("Данные загружены из файла '4.3.txt'.\n");
    }

    int choice;
    do {
        printf("\nМеню:\n");
        printf("0 - выйти\n");
        printf("1 - добавить запись (имя и телефон)\n");
        printf("2 - распечатать все имеющиеся записи\n");
        printf("3 - найти телефон по имени\n");
        printf("4 - найти имя по телефону\n");
        printf("5 - сохранить текущие данные в файл\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("До свидания!\n");
                break;
            case 1:
                addEntry();
                break;
            case 2:
                printEntries();
                break;
            case 3:
                findNumberByName();
                break;
            case 4:
                findNameByNumber();
                break;
            case 5:
                saveToFile();
                break;
            default:
                printf("Неправильный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}

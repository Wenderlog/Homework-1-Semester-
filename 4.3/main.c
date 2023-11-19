#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100

typedef struct Record
{   
    char name[50];
    char phoneNumber[20];
} Record;

void runTests() {
    {
        Record* records[MAX_RECORDS] = { NULL };
        size_t countRecords = 0;

        Record testRecord;
        strcpy(testRecord.phoneNumber, "1234567890");
        strcpy(testRecord.name, "TestName");

        int result = executeCommand1(records, &countRecords, &testRecord);

        if (result == 0) {
            printf("Тест 1: Добавление записи - успешно\n");
        }
        else {
            printf("Тест 1: Добавление записи - ошибка\n");
        }

        if (countRecords == 1) {
            printf("Тест 2: Количество записей увеличилось - успешно\n");
        }
        else {
            printf("Тест 2: Количество записей увеличилось - ошибка\n");
        }

        if (strcmp(records[0]->phoneNumber, "1234567890") == 0 && strcmp(records[0]->name, "TestName") == 0) {
            printf("Тест 3: Запись добавлена правильно - успешно\n");
        }
        else {
            printf("Тест 3: Запись добавлена правильно - ошибка\n");
        }

        freeRecords(records);
    }
}

signed char readCommand()
{
    printf("Ввести команду (0 - закрыть, 1 - добавить запись, 2 - распечатать все записи, 3 - найти телефон по названию, 4 - найти имя по телефону, 5 - сохранить): ");
    signed char command = -1;
    int scanResult = scanf("%hhi", &command);
    while (scanResult == 0 || command > 5 || command < 0)
    {
        scanf("%*[^\n]");
        printf("Неправильный ввод: ");
        scanResult = scanf("%hhi", &command);
    }
    return command;
}


int executeCommand1(Record** records, size_t* countRecords)
{
    if (*countRecords >= MAX_RECORDS)
    {
        printf("Память заполнена\n");
        return 0;
    }

    records[*countRecords] = calloc(1, sizeof(Record));
    if (records[*countRecords] == NULL)
    {
        return -2;
    }

    printf("Введите номер телефона: ");
    scanf("%15s", records[*countRecords]->phoneNumber);
    printf("Введите имя: ");
    scanf("%50s", records[*countRecords]->name);
    ++*countRecords;

    return 0;
}

void executeCommand2(Record** records, size_t countRecords)
{
    for (size_t i = 0; i < countRecords; ++i)
    {
        printf("Номер телефона: %s, Имя: %s\n", records[i]->phoneNumber, records[i]->name);
    }
}

void executeCommand3(Record** records, size_t countRecords)
{
    printf("Имя для поиска: ");
    char name[51] = { 0 };
    scanf("%50s", name);

    bool found = false;

    for (size_t i = 0; i < countRecords; ++i)
    {
        if (strcmp(name, records[i]->name) == 0)
        {
            printf("Найден номер телефона по заданному имени: %s\n", records[i]->phoneNumber);
            found = true;
        }
    }

    if (!found)
    {
        printf("Нет записи с таким именем!\n");
    }
}

void executeCommand4(Record** records, size_t countRecords)
{

    printf("Введите номер телефона для поиска: ");
    char phoneNumber[16] = { 0 };
    scanf("%15s", phoneNumber);

    bool found = false;

    for (size_t i = 0; i < countRecords; ++i)
    {
        if (strcmp(phoneNumber, records[i]->phoneNumber) == 0)
        {
            printf("Найдено имя по указанному номеру телефона: %s\n", records[i]->name);
            found = true;
        }
    }

    if (!found)
    {
        printf("Нет записи с этим номером телефона\n");
    }
}

int executeCommand5(Record** records, size_t countRecords, char** fileName)
{
    char tmp[101] = { 0 };
    printf("Введите имя файла: ");
    scanf("%100s", tmp);

    if (strcmp(tmp, "0"))
    {
        strcpy(*fileName, tmp);
    }

    FILE* file = fopen(*fileName, "w");
    if (file == NULL)
    {
        return -3;
    }

    fprintf(file, "phoneNumber\tname");
    for (size_t i = 0; i < countRecords; ++i)
    {
        fprintf(file, "\n%s\t%s", records[i]->phoneNumber, records[i]->name);
    }
    fclose(file);
    return 0;
}

int readDataFromFile(Record** records, char* fileName, size_t* countRecords)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return -3;
    }
    char tmp[17] = { 0 };
    char heading[] = "phoneNumber\tname";

    fscanf(file, "%11s", tmp);
    tmp[11] = '\t';
    fscanf(file, "%4s", tmp + 12);

    if (strcmp(heading, tmp))
    {
        fclose(file);
        return -4;
    }

    while (!feof(file))
    {
        records[*countRecords] = calloc(1, sizeof(Record));
        if (records[*countRecords] == NULL)
        {
            fclose(file);
            return -2;
        }
        fscanf(file, "%s %s", records[*countRecords]->phoneNumber, records[*countRecords]->name);
        ++*countRecords;
    }

    fclose(file);
    return 0;
}

void freeRecords(Record** records)
{
    for (size_t i = 0; i < MAX_RECORDS; ++i)
    {
        free(records[i]);
    }
}

int main()
{
    runTests();
    char* fileName = calloc(101, sizeof(char));

    Record* records[MAX_RECORDS] = { NULL };
    size_t countRecords = 0;

    printf("Введите путь файла ");
    scanf("%100s", fileName);

    if (strcmp(fileName, "0"))
    {
        int readCode = readDataFromFile(records, fileName, &countRecords);
        switch (readCode)
        {
        case -2:
        {
            printf("Ошибка при выделении памяти");
            freeRecords(records);
            return -2;
        }
        case -3:
        {
            printf("Файл с таким именем не существует! \n");
            break;
        }
        case -4:
        {
            printf("Данный файл содержит неверные данные\n");
            break;
        }
        }
    }

    signed char command = readCommand();
    while (command != 0)
    {
        switch (command)
        {
        case 1:
        {
            int result = executeCommand1(records, &countRecords);
            if (result == -2)
            {
                printf("Ошибка при выделении памяти");
                freeRecords(records);
                return -2;
            }
            break;
        }
        case 2:
            executeCommand2(records, countRecords);
            break;
        case 3:
            executeCommand3(records, countRecords);
            break;
        case 4:
            executeCommand4(records, countRecords);
            break;
        case 5:
        {
            int result = executeCommand5(records, countRecords, &fileName);
            if (result == -3)
            {
                printf("Не удается выполнить запись в файл по этому пути\n");
            }
            else
            {
                printf("Сохранение в файл\n");
            }
            break;
        }
        }
        command = readCommand();
    }

    free(fileName);
    freeRecords(records);
    return 0;
}


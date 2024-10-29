#include <stdio.h>
#include <string.h>
#include "solutionComments.h"
const int numberOfLines = 5;
const int numberOfColumns = 4;

bool createTable(int table[numberOfLines][numberOfColumns])
{
    FILE* fileWithTable;
    if (fopen_s(&fileWithTable, "table.txt", "r") != 0)
    {
        printf("File with table not found\n");
        return false;
    }

    for (int i = 0; i < numberOfLines; ++i)
    {
        for (int j = 0; j < numberOfColumns; ++j)
        {
            if (i == 0)
            {
                fscanf_s(fileWithTable, R"(%c )", &table[i][j], sizeof(char));
                continue;
            }
            fscanf_s(fileWithTable, "%d", &table[i][j], sizeof(int));
        }
    }
    fclose(fileWithTable);
    return true;
}

int nextState(int currentState, char symbol, int table[numberOfLines][numberOfColumns])
{
    for (int i = 1; i < 3; ++i)
    {
        if (symbol == table[0][i])
        {
            return table[currentState + 1][i];
        }
    }
    return table[currentState + 1][3];
}

char* comments(char* fileName)
{
    int table[numberOfLines][numberOfColumns] = {};
    if (!createTable(table))
    {
        return NULL;
    }

    FILE* file;
    if (fopen_s(&file, fileName, "r") != 0)
    {
        printf("File not found\n");
        return new char[0];
    }

    char comments[10000] = {};
    char buffer[1000] = {};
    int state = 0;

    while (!feof(file))
    {
        char symbol = fgetc(file);

        if (state == 1 && symbol == table[0][2])
        {
            buffer[0] = '/';
        }

        if (state == 3 && symbol == table[0][1])
        {
            strcat_s(comments, sizeof(comments), "\n");
            strcat_s(comments, sizeof(comments), buffer);
            strcat_s(comments, sizeof(comments), "/");
            buffer[0] = '\0'; 
        }

        state = nextState(state, symbol, table);

        if (state == 2 || state == 3)
        {
            char str[2] = { symbol, '\0' };
            strcat_s(buffer, sizeof(buffer), str);
        }
    }
    fclose(file);
    return comments;
}

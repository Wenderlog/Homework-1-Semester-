#include <stdio.h>
#include "hashtable.h"

int main() {
    struct Hashtable* hashtable = create_hashtable(100);

    FILE* file = fopen("9.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char buffer[100];
    while (fscanf(file, "%99s", buffer) == 1) {
        insert(hashtable, buffer);
    }

    fclose(file);

    print_word_frequencies(hashtable);

    double fill = fill_factor(hashtable);
    printf("Коэффициент заполнения: %.2lf\n", fill);

    int max_length = max_list_length(hashtable);
    printf("Максимальная длина списка: %d\n", max_length);

    double avg_length = average_list_length(hashtable);
    printf("Средняя длина списка: %.2lf\n", avg_length);

    destroy_hashtable(hashtable);

    return 0;
}

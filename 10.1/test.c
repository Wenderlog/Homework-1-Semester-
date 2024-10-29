#include "test.h"
#include "graph.h"

#include<assert.h>

void test1() {
    FILE *input_file = fopen("10.1.txt", "r");
    if (input_file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    int n, m, k;
    fscanf(input_file, "%d%d", &n, &m);

    Road roads[MAX_CITIES];
    for (int i = 0; i < m; i++) {
        fscanf(input_file, "%d%d%d", &roads[i].city1, &roads[i].city2, &roads[i].length);
    }
    fscanf(input_file, "%d", &k);
    int capitals[k];
    for (int i = 0; i < k; i++) {
        fscanf(input_file, "%d", &capitals[i]);
    }

    State states[MAX_CITIES];
    for (int i = 0; i < k; i++) {
        states[i].capital = capitals[i];
        states[i].cities = (int*)malloc(MAX_CITIES * sizeof(int));
        states[i].cities[0]= capitals[i];
        states[i].num_cities = 1;
    }

    bool* visited = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n - k; i++) {
        for (int j = 0; j < k; j++) {
            int nearest_city = find_nearest_city(states, k, roads, m, j, visited);
            if (nearest_city != -1) {
                states[j].cities[states[j].num_cities] = nearest_city;
                states[j].num_cities++;
            }
        }
    }
    assert(states[0].cities[0] == 2);
    assert(states[0].cities[1] == 3);
    assert(states[1].cities[0] == 1);
    free(visited);
    fclose(input_file);
}
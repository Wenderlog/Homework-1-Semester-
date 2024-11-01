#include"graph.h"
#include"test.h"

int main() {
    test1();
    FILE *input_file = fopen("10.1.txt", "r");
    if (input_file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
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


    for (int i = 0 ; i < k; i++) {
        printf("Государство %d: ", states[i].capital);
        for (int j = 0; j < states[i].num_cities; j++) {
            printf("%d ", states[i].cities[j]);
        }
        printf("\n");
        free(states[i].cities);
    }
    free(visited);
    fclose(input_file);
    return 0;
}
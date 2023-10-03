#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_CITIES 100

typedef struct {
    int city1;
    int city2;
    int length;
}Road;

typedef  struct {
    int capital;
    int* cities;
    int num_cities;
} State;

int find_nearest_city(State states[], int num_states, Road roads[], int num_roads, int state_index, bool* visited) {
    int nearest_city = -1;
    int min_distance = INT_MAX;
    
    int* queue = (int*)malloc(MAX_CITIES * sizeof(int));
    int front = 0;
    int rear = 0;
    
    queue[rear++] = states[state_index].capital;
    visited[states[state_index].capital] = true;
    
    while (front < rear) {
        int current_city = queue[front++];
            
            for (int i = 0; i < num_roads; i++) {
                int next_city = -1;
                if (roads[i].city1 == current_city) {
                    next_city = roads[i].city2;
                } else if (roads[i].city2 == current_city) {
                    next_city = roads[i].city1;
            }
                if (next_city != -1 && !visited[next_city]) {
                    queue[rear++] = next_city;
                    visited[next_city] = true;
                    
                    bool is_city_used = false;
                    for (int j = 0; j < num_states; j++) {
                        if (j != state_index) {
                            for (int k = 0; k < states[j].num_cities; k++) {
                                if (states[j].cities[k] == next_city) {
                                    is_city_used = true;
                                    break;
                                }
                            }
                        }
                        if (is_city_used) {
                            break;
                        }
                        if (!is_city_used) {
                            int distance = roads[i].length;
                            if (distance < min_distance) {
                                min_distance = distance;
                                nearest_city = next_city;
                            }
                        }
                    }
                    
                }
        }
    }
    free(queue);
    return nearest_city;
}

int main() {
    FILE *input_file = fopen("10.1.txt", "r");
    if (input_file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }
    
    int n, m, k;
    fscanf(input_file, "%d %d", &n, &m);
    
    Road roads[m];
    for (int i = 0; i < m; i++) {
        fscanf(input_file, "%d %d %d", &roads[i].city1, &roads[i].city2, &roads[i].length);
    }
    fscanf(input_file, "%d", &k);
    int capitals[k];
    for (int i = 0; i < k; i++) {
        fscanf(input_file, "%d", &capitals[i]);
    }
    
    State states[k];
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

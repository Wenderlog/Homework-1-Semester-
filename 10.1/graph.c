#include "graph.h"

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
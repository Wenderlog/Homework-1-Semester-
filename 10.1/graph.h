#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_CITIES 100

typedef struct road{
    int city1;
    int city2;
    int length;
}Road;

typedef struct state{
    int capital;
    int* cities;
    int num_cities;
} State;

int find_nearest_city(State states[], int num_states, Road roads[], int num_roads, int state_index, bool* visited);

#endif /*GRAPH_H*/
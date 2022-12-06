#include <stdio.h>
#include "my_mat.h"

int graph[10][10];

void insert() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%i", &graph[i][j]);
        }
    }
    createGraph();
}

void createGraph() {
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int isLinked(int i, int j) { return (graph[i][j] == 0) ? 0 : 1; }

int findMin(int i, int j) { return (graph[i][j] != 0) ? graph[i][j] : -1; }


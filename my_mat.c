#include <stdio.h>
#include <limits.h>
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
    int i, j, k;
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            if (i == j) {
                graph[i][i] = 0;
            } else if (graph[i][j] == 0) {
                graph[i][j] = INT_MAX;
            } else if (graph[i][j] != 0) {
                graph[i][j] = graph[i][j];
            }
        }
    }

    for (k = 0; k < 10; k++) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                if (j != k && i != k && (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)) {
                    if (graph[i][j] > (int) graph[i][k] + graph[k][j]) {
                        graph[i][j] = (int) graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

int isLinked(int i, int j) { return (graph[i][j] == 0 || graph[i][j] == INT_MAX) ? 0 : 1; }

int findMin(int i, int j) { return (graph[i][j] == 0 || graph[i][j] == INT_MAX) ? -1 : graph[i][j]; }


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // Número de nodos en el grafo

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[]) {
    printf("Nodo \t Distancia desde el nodo de inicio\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Arreglo de Distancias
    bool sptSet[V]; // Arreglo de Nodos Visitados

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {

  int graph[V][V] = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
    };


    // int graph[V][V] = {
    //     {0, 2, 0, 0, 0, 0},
    //     {2, 0, 4, 0, 6, 0},
    //     {0, 4, 0, 3, 0, 0},
    //     {0, 0, 3, 0, 1, 5},
    //     {0, 6, 0, 1, 0, 2},
    //     {0, 0, 0, 5, 2, 0}
    // };

    dijkstra(graph, 0);

    return 0;
}

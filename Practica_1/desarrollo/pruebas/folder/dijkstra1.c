#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "dijkstra1.h"

// #define V 5 // Número de nodos en el grafo

// int V = 5;

// void definirDimension(int d) {
//   V = d;
// }


void printPath(int parent[], int j) {
    // Si j es el nodo de origen, imprime solo el nodo
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }

    // Imprime la ruta desde el nodo de origen hasta j
    printPath(parent, parent[j]);
    printf("-> %d ", j);
}

void printSolution(int dist[], int parent[], int src, int dest) {
    printf("Nodo \t Distancia desde el nodo de origen \t Ruta\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d \t\t\t\t\t", i, dist[i]);
        if (parent[i] == -1) {
          printf("-");
        } else {
          printf("%d", parent[i]);
        }
        // printPath(parent, i);
        printf("\n");
    }
    printf("Ruta: ");
    printPath(parent, dest);
    printf("\n");
}

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src, int dest) {
    printf("V: %d\n", V);
    printf("src: %d, dest: %d\n", src, dest);

    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Almacenar el nodo previo en la ruta más corta
            }
        }
    }

    // printSolution(dist, parent, src);
    printSolution(dist, parent, src, dest);
}

/*
int main() {

    // V = 5;
    // definirDimension(5);

    // int graph[V][V] = {
    //     {0, 6, 0, 1, 0},
    //     {6, 0, 5, 2, 2},
    //     {0, 5, 0, 0, 5},
    //     {1, 2, 0, 0, 1},
    //     {0, 2, 5, 1, 0}
    // };

    int graph[V][V] = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
    };


    int origen = 0; // Define el nodo de origen
    int destino = 2;

    dijkstra(graph, origen, destino);

    return 0;
}
*/

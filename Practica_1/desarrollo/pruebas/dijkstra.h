#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

int cantidad_nodos;

int minDistance(int dist[], bool sptSet[]);

void printSolution(int dist[]);

void dijkstra(int graph[cantidad_nodos][cantidad_nodos], int nodos, int src);

void asignar_cantidad_nodos(int nodos);

void iniciar();

#endif
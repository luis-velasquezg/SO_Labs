#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

extern int V;
// void definirDimension(int d);
void printPath(int parent[], int j);
void printSolution(int dist[], int parent[], int src, int dest);
// int minDistance(int dist[], bool sptSet[]);
void dijkstra(int graph[V][V], int src, int dest);
#endif
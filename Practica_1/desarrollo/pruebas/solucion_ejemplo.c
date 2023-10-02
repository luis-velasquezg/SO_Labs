#include <stdio.h> //Biblioteca estándar de entrada/salida para que se puedan usar funciones como printf y scanf.
#include <stdlib.h> //Biblioteca estándar para funciones como malloc y free, que se utilizan para la gestión de memoria dinámica.
#include <stdbool.h> //Biblioteca para el tipo de datos bool, que se utiliza para representar valores booleanos (verdadero o falso).
#include <limits.h> //Biblioteca que proporciona constantes relacionadas con los límites de los tipos de datos, como INT_MAX.

#define MAX_NODES 20 //Define una constante llamada MAX_NODES con un valor de 20, que representa el número máximo de nodos (vértices) en el grafo.
//Estructura de grafo

/*esta declaración define una estructura de datos Graph que se utiliza para representar y almacenar información 
sobre un grafo ponderado, incluyendo los pesos de las aristas, el número de vértices y si es dirigido o no.*/
typedef struct {
    int weight[MAX_NODES][MAX_NODES]; // Matriz que almacena los pesos de las aristas 
    int nvertices; //Número de vértices en el grafo
    bool directed; //Grafo es dirigido o no
} Graph;

/* Aquí se inicializa la estructura Graph estableciendo el número de vértices en 0, configurando la dirección del grafo y 
llenando la matriz de pesos de aristas con valores máximos (INT_MAX) para representar que inicialmente no hay aristas definidas 
en el grafo. 
Esta función prepara la estructura Graph antes de agregar aristas y realizar operaciones en el grafo.*/
void initializeGraph(Graph *g, bool directed) {
    int i, j;
    g->nvertices = 0;
    g->directed = directed;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            g->weight[i][j] = INT_MAX;
        }
    }
}

/* agrega una arista con un peso entre los vértices x e y en el grafo g, teniendo en cuenta si el grafo es dirigido o no. 
Si el grafo no es dirigido, también agrega la arista inversa para mantener la simetría en el grafo. Además, incrementa el 
contador de vértices si se agrega una arista en un grafo dirigido.*/
void insertEdge(Graph *g, int x, int y, int weight, bool directed) {
    g->weight[x][y] = weight;
    if (!directed) {
        insertEdge(g, y, x, weight, true);
    } else {
        g->nvertices++;
    }
}

void dijkstra(Graph *g, int start) {
    int i, v, w, dist[MAX_NODES], prev[MAX_NODES], visited[MAX_NODES];

    for (i = 0; i < g->nvertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;
    }
    dist[start] = 0;

    for (i = 0; i < g->nvertices; i++) {
        int minDist = INT_MAX;
        for (w = 0; w < g->nvertices; w++) {
            if (!visited[w] && dist[w] < minDist) {
                v = w;
                minDist = dist[w];
            }
        }
        visited[v] = true;
        for (w = 0; w < g->nvertices; w++) {
            if (!visited[w] && g->weight[v][w] != INT_MAX && (dist[v] + g->weight[v][w] < dist[w])) {
                dist[w] = dist[v] + g->weight[v][w];
                prev[w] = v;
            }
        }
    }

    printf("Vertex\tDistance\tPrevious\n");
    for (i = 0; i < g->nvertices; i++) {
        printf("%d\t%d\t\t%d\n", i, dist[i], prev[i]);
    }
}

int main() {
    Graph g;
    bool directed;
    char choice[5];
    int n, i, x, y, weight;

    printf("Is the graph directed (true/false)? ");
    scanf("%s", choice);
    directed = (choice[0] == 't') ? true : false;

    initializeGraph(&g, directed);

    printf("Enter the number of edges: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter edge (x y weight): ");
        scanf("%d %d %d", &x, &y, &weight);
        insertEdge(&g, x, y, weight, directed);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &x);

    dijkstra(&g, x);

    return 0;
}
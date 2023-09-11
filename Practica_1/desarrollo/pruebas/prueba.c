#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_NODOS 26  // Máximo 26 nodos (A-Z)
#define MAX_NODOS 20  // Máximo 20 nodos

int main() {
    bool esDirigido = false;  // Variable para indicar si el grafo es dirigido o no
    char linea[100];         // Buffer para leer cada línea del archivo
    int matrizAdyacencia[MAX_NODOS][MAX_NODOS] = {0};  // Inicializar la matriz de adyacencia

    // Abrir el archivo para lectura
    FILE *archivo = fopen("input_file.txt", "r");

    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    // Leer la primera línea para determinar si el grafo es dirigido o no
    fgets(linea, sizeof(linea), archivo);
    if (strncmp(linea, "true", 4) == 0) {
        esDirigido = true;
    }

    // Leer la segunda línea que contiene las aristas y los costos
    fgets(linea, sizeof(linea), archivo);

    // Parsear las aristas y los costos
    char *token = strtok(linea, ";");
    while (token != NULL) {
        char nodoInicial, nodoFinal;
        int costo;
        if (sscanf(token, " (%c, %c, %d)", &nodoInicial, &nodoFinal, &costo) == 3) {
            int startIdx = nodoInicial - 'A';
            int endIdx = nodoFinal - 'A';

            // Establecer la entrada en la matriz de adyacencia
            matrizAdyacencia[startIdx][endIdx] = costo;

            // Si el grafo no es dirigido, también establecer la entrada inversa
            if (!esDirigido) {
                matrizAdyacencia[endIdx][startIdx] = costo;
            }
        }
        token = strtok(NULL, ";");
    }

    // Cerrar el archivo
    fclose(archivo);

    // Imprimir la matriz de adyacencia
    printf("Matriz de Adyacencia:\n");
    for (int i = 0; i < MAX_NODOS; i++) {
        for (int j = 0; j < MAX_NODOS; j++) {
            printf("%2d ", matrizAdyacencia[i][j]);
        }
        printf("\n");
    }

    return 0;
}

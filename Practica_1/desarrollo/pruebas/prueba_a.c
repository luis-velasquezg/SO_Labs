#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Se define la Constante MAX_NODOS
#define MAX_NODOS 20 // Máximo de nodos
#define HASH_SIZE 100

bool tablaHash[HASH_SIZE];


// Insertar vertice en la tabla hash
void insertarVertice(char vertice) {
  unsigned int indice = (unsigned int)vertice % HASH_SIZE;
  tablaHash[indice] = true;
} 

// Estructura de Vertice
typedef struct Vertice {
  char letra;
  int id;
}


// int main(int argc, char *argv[])
int main()
{

  for (int i = 0; i < TABLE_SIZE; i++)
  {
    tablaHash[i] = NULL;
  }


  printf("Su nombre es %s, tiene %d años \n", "Ana", 16);


  bool esDirigido = false; // Variable para indicar si el grafo es dirigido o no
  char linea[100]; // Buffer para leer cada linea del archivo
  int matrizAdyacencia[MAX_NODOS][MAX_NODOS] = {0}; // Inicializa la matriz de adyacencia

  // Abrir el archivo para lectura
  FILE *archivo = fopen("input_file.txt", "r");

  // Si el archivo no existe, el programa termina
  if (archivo == NULL)
  {
    perror("No se pudo abrir el archivo");
    return 1;
  }

  // Leer la primera linea para determinar si el grafo es dirigido o no
  fgets(linea, sizeof(linea), archivo);
  if (strncmp(linea, "true", 4) == 0)
  {
    esDirigido = true;
  }

  printf("linea 1: %s", linea);

  // Leer la segunda linea que contiene las aristas y los costos
  // fgets(linea, sizeof(linea), archivo);
  fgets(linea, sizeof(linea), archivo);
  printf("linea 2: %s \n", linea);



  int nodosDetectados = 0;
  // Parsear las aristas y los costos
  char *token = strtok(linea, ";");
  printf("token: %s\n", token);
  while (token != NULL)
  {
    char nodoInicial, nodoFinal;
    int costo;

    // int x = sscanf(token, " (%c, %c, %d)", &nodoInicial, &nodoFinal, &costo);
    // printf("x: %d\n", x);
    // printf("nodoInicial: %c\n", nodoInicial);
    // printf("nodoFinal: %c\n", nodoFinal);
    // printf("costo: %d\n", costo);

    if (sscanf(token, " (%c, %c, %d)", &nodo1, &nodo2, &costo) == 3)
    {
      Vertice nodoInicial;
      nodoInicial.letra = nodo1;
      nodoInicial.id = nodosDetectados;
      nodosDetectados++;

      {
        /* data */
      };
      

      int i = nodoInicial - 'A';
      int j = nodoFinal - 'A';  

      printf("i: %d, j: %d\n", i, j);

      // Establecer la entrada en la matriz de adyacencia
      matrizAdyacencia[i][j] = costo;

      // Si el grafo no es dirigido, se podra recorrer tambien de manera inversa
      if (!esDirigido)
      {
        matrizAdyacencia[j][i] = costo;
      }
    }
    token = strtok(NULL, ";");
  }

  // Cerrar el archivo
  fclose(archivo);

  // Imprimir la matriz de adyacencia
  printf("Matriz de Adyacencia:\n");
  for (int i = 0; i < MAX_NODOS; i++)
  {
    for (int j = 0; j < MAX_NODOS; j++)
    {
      printf("%2d ", matrizAdyacencia[i][j]);
    }
    printf("\n");
  }

  return 0;
}

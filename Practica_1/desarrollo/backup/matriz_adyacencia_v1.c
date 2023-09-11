#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Se define la Constante MAX_NODOS
#define MAX_NODOS 20 // Máximo de nodos

int main(int argc, char *argv[])
{
  // Revisa si el numero de argumentos sea el correcto
  if (argc != 2)
  {
    printf("Uso correcto: %s <nombre_archivo>\n", argv[0]);
    return 1;
  }

  bool esDirigido = false; // Variable para indicar si el grafo es dirigido o no
  char linea[100]; // Buffer para leer cada linea del archivo
  int matrizAdyacencia[MAX_NODOS][MAX_NODOS] = {0}; // Inicializa la matriz de adyacencia

  // Abrir el archivo para lectura
  FILE *archivo = fopen(argv[1], "r");

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

  // Leer la segunda linea que contiene las aristas y los costos
  fgets(linea, sizeof(linea), archivo);

  // Parsear las aristas y los costos
  char *token = strtok(linea, ";");
  while (token != NULL)
  {
    char nodoInicial, nodoFinal;
    int costo;
    if (sscanf(token, " (%c, %c, %d)", &nodoInicial, &nodoFinal, &costo) == 3)
    {
      int i = nodoInicial - 'A';
      int j = nodoFinal - 'A';

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

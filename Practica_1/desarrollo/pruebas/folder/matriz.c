#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// #include "pq.h"
#include "dijkstra1.h"

// Se define la Constante MAX_NODOS
#define MAX_NODOS 20      // Maximo de nodos
#define HASH_SIZE 100     // Tamanio de tabla hash
#define LINE_BUFFER 400   // Buffer para leer cada linea del archivo


// Estructura de Vertice
typedef struct {
  char letra;
  int id;
} Vertice;

int V; // Numero de Nodos en el grafo


// Tabla Hash de Vertices (para consultar su id teniendo la letra)
Vertice tablaHash[HASH_SIZE];
// Arreglo de Vertices (para consultar la letra teniendo su id)
char listaVertices[MAX_NODOS];
int contadorElementos; // Incrementa con cada letra nueva que encuentra


// Funcion de hash simple para convertir un caracter en un indice
unsigned int hash(char c) {
    return (unsigned int)c % HASH_SIZE; // c mod 100
}


// Insertar vertice en la Tabla Hash y el Arreglo de Vertices
void insertarVertice (char vertice) {
  unsigned int indice = hash(vertice);
  if (tablaHash[indice].letra == '\0' && contadorElementos < MAX_NODOS)
  {
    Vertice verticeNuevo;
    verticeNuevo.letra = vertice;
    verticeNuevo.id = contadorElementos;
    
    // Se almacena el Vertice en la Tabla Hash y la Lista de Vertices
    tablaHash[indice] = verticeNuevo; // Tipo Vertice
    listaVertices[contadorElementos] = vertice; // Tipo char
    
    contadorElementos++;
  }
}

// Retorna el id de un vertice dada su letra
// Retorna -1 si no lo encuentra 
int obtenerVerticeId(char vertice) {
  unsigned int indice = hash(vertice);
  if (tablaHash[indice].letra != '\0') {
    return tablaHash[indice].id;
  }
  return -1;
}


/*** FUNCION DE PRUEBA ***/
void revisarEjecucion() {

  // IMPRIMIR TABLA HASH
  printf("\n[Tabla Hash]\n");
  for (int i = 0; i < HASH_SIZE; i++) {
    printf("[%d]\tVertice: %c\tid: %d\n", i, tablaHash[i].letra, tablaHash[i].id);
  }

  // IMPRIMIR LISTA DE VERTICES
  printf("\n[Lista de Vertices]\n");
  for (int i = 0; i < MAX_NODOS; i++) {
    printf("[%d]\tVertice:%c\n", i, listaVertices[i]);
  }
  
}
/*** FIN FUNCION DE PRUEBA ***/



int main(int argc, char *argv[]) {

  // Revisa si el numero de argumentos sea el correcto
  if (argc != 2) {
    printf("Uso correcto: %s <nombre_archivo>\n", argv[0]);
    return 1;
  }


  // Lectura por Consola de Nodos (vertices) Origen y Destino
  char verticeOrigenIngresado, verticeDestinoIngresado;
  printf("Nodo Origen:\n"); // Nodo origen
  scanf(" %c", &verticeOrigenIngresado);
  printf("Nodo Destino:\n"); // Nodo destino
  scanf(" %c", &verticeDestinoIngresado);

  printf("\n");

  // Reinicia la Tabla Hash
  for (int i = 0; i < HASH_SIZE; i++) {
    tablaHash[i].letra = '\0'; // Caracter nulo ('\0')
  }

  // Reinicia la Lista de Vertices
  for (int i = 0; i < MAX_NODOS; i++) {
    listaVertices[i] = '\0'; // Caracter nulo
  }
  
  // Reinicia el Contador de Elementos
  contadorElementos = 0;


  bool esDirigido = false; // Variable para indicar si el grafo es dirigido o no
  char linea[LINE_BUFFER]; // Buffer para leer cada linea del archivo
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
      insertarVertice(nodoInicial);
      insertarVertice(nodoFinal);

      // int i = nodoInicial - 'A';
      // int j = nodoFinal - 'A';

      int indexOrigen = obtenerVerticeId(nodoInicial);
      int indexDestino = obtenerVerticeId(nodoFinal);

      // Establecer los costos en la matriz de adyacencia
      if (indexOrigen >= 0 && indexDestino >= 0) {
        // matrizAdyacencia[i][j] = costo;
        matrizAdyacencia[indexOrigen][indexDestino] = costo;

        // Si el grafo no es dirigido, se podra recorrer tambien de manera inversa
        if (!esDirigido)
        {
          matrizAdyacencia[indexDestino][indexOrigen] = costo;
        }
      }
      
    }
    token = strtok(NULL, ";");
  }

  // Cerrar el archivo
  fclose(archivo);


  printf("contadorElementos: %d\n", contadorElementos);
  
  // Imprimir lista de nodos de la Matriz de Adyacencia
  printf("Indice Nodos:\n");
  for (int i = 0; i < contadorElementos; i++) {
    printf("%c:%d", listaVertices[i], i);
    if (i < (contadorElementos - 1)) {
      printf(", ");
    }
  }
  printf("\n\n");
  
  // IMPRIMIR MATRIZ DE ADYACENCIA
  printf("[Matriz de Adyacencia]\n");
  for (int i = 0; i < contadorElementos; i++)
  {
    for (int j = 0; j < contadorElementos; j++)
    {
      printf("%2d ", matrizAdyacencia[i][j]);
    }
    printf("\n");
  }

  // revisarEjecucion();


  int verticeOrigen = obtenerVerticeId(verticeOrigenIngresado);  
  int verticeDestino = obtenerVerticeId(verticeDestinoIngresado);

  

  if (verticeOrigen >= 0 && verticeDestino >= 0) {
    // V = contadorElementos;
    V = MAX_NODOS;


    dijkstra(matrizAdyacencia, verticeOrigen, verticeDestino);
  } else {
    printf("ERROR: No existe el Vertice de origen o destino especificado\n");
  }

  


  return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // Para obtener los valores limites un tipo de dato

int main()
{
  int max_integer = INT_MAX; // Valor maximo de un entero

  char vector[10];
  int vector2[10] = {1};
  // for (int i = 0; i < 10; i++)
  // {
  //   vector[i] = '\0';
  // }

  // vector2 = {0};

  printf("Valor maximo de un entero: %d\n", max_integer);

  // printf("%d\n", vector2);

  vector[0] = 'A';
  vector[1] = 'X';
  vector[2] = 'E';
  vector[3] = 'D';

  for (int i = 0; i < 10; i++)
  {
    printf("%c", vector[i]);
  }


  if (vector[4] == '\0')
  {
    printf("\nElemento nulo");
  } else {
    printf("Elemento no nulo");
  }







  // vector[0] = "hola";
  // vector[1] = "mundo";
  // printf("%s", vector[0]);
  // printf("%s", vector[1]);
  // printf("%s", vector[2]);
  // for (int i = 0; i < 10; i++)
  // {
  //   printf("%s", vector[i]);
  // }
  // printf("\n");
  // printf("%zu", sizeof(vector));
  // printf("\n");

  return 0;
}
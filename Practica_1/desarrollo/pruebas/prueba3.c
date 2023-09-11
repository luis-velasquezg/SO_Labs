#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int a = 0;

  if (argv[1] != NULL) {
    // char *numeroComoTexto = argv[1];
    
    // Realizar el casting de la cadena a entero usando atoi
    // a = atoi(numeroComoTexto);
    a = atoi(argv[1]); // atoi convierte un String a un Entero 
  }
 
  a++;
  printf("%d\n", a);
  return 0;
}
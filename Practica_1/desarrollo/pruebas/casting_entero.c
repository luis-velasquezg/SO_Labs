/*
Ten en cuenta que atoi tiene algunas limitaciones y asume que la cadena es un número válido.
Si la cadena no es un número válido, puede comportarse de manera inesperada. Para manejar
errores de conversión más robustamente y obtener más control sobre los resultados, puedes
considerar el uso de strtol. Aquí tienes un ejemplo usando strtol:
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    // Obtener el argumento pasado como cadena de caracteres
    char *numeroComoTexto = argv[1];

    // Variables para almacenar el resultado y verificar errores
    int numero;
    char *endptr;  // Puntero al último carácter convertido

    // Realizar el casting de la cadena a entero usando strtol
    numero = strtol(numeroComoTexto, &endptr, 10);

    // Verificar si ocurrió un error de conversión
    if (*endptr != '\0') {
        printf("Error: No se pudo convertir la cadena en un número válido.\n");
        return 1;
    }

    // Realizar operaciones con el número (por ejemplo, imprimirlo)
    printf("El número ingresado es: %d\n", numero);

    return 0;
}

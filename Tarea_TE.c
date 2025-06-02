#include <stdio.h>
#include <math.h>

// Variable con función verificar si una letra es vocal es una mejora propuesta
int esVocal(char letra) {
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U');
}

int main() {
    //Declaración de variables 
    int opcion, numero;
    float decimal, resultado;  
    char letra1, letra2, letra3;
    int contador = 0; 

    // Menú con opciones al usuario 
    printf("\nSeleccione una opción:\n");
    printf("1. Calcular el cuadrado de un número\n");
    printf("2. Verificar si un número es par o impar\n");
    printf("3. Calcular la raíz cuadrada de un número decimal\n");
    printf("4. Contar cuántas vocales hay en tres letras ingresadas\n");
    printf("5. Salir\n"); //Opción agregada para salir del programa 

    // Hace una mejora, en caso de que la opción no sea válida
    printf("Seleccione una opción: ");
    if (scanf("%d", &opcion) != 1) {
        printf("Entrada inválida. Por favor, ingrese un número.\n");
        return 0; 
    }

    switch (opcion) {
        case 1: // Calcular el cuadrado de un número
            printf("Ingrese un número: ");
            if (scanf("%d", &numero) != 1) {
                printf("Entrada inválida. Por favor, ingrese un número entero.\n");
                break;
            }
            resultado = numero * numero;  // Mejoramos para que la variable no tenga problemas
            printf("El cuadrado de %d es %.2f\n", numero, resultado); //.2 para que sean dos decimales
            break;

        case 2: // Verificar si un número es par o impar
            printf("Ingrese un número: ");
            if (scanf("%d", &numero) != 1) {
                printf("Entrada inválida. Por favor, ingrese un número entero.\n");
                break;
            }
            if (numero % 2 == 0) {
                printf("El número es par.\n");
            } else {
                printf("El número es impar.\n");
            }
            break;

        case 3: // Calcular la raiz cuadrada de un número decimal 
            printf("Ingrese un número decimal: ");
            if (scanf("%f", &decimal) != 1) {
                printf("Entrada inválida. Por favor, ingrese un número decimal.\n"); //Mejora agregada para verificación
                break;
            }
            if (decimal >= 0) {
                resultado = sqrt(decimal);
                printf("La raíz cuadrada es: %.2f\n", resultado);
            } else {
                printf("No se puede calcular la raíz cuadrada de un número negativo.\n");
            }
            break;

        case 4:
            printf("Ingrese tres letras separadas por espacios: ");
            scanf(" %c %c %c", &letra1, &letra2, &letra3);
            if (esVocal(letra1)) contador++;  //Mejora y simplifica la función a partir de la función agregada al incio
            if (esVocal(letra2)) contador++;
            if (esVocal(letra3)) contador++;
            printf("Se ingresaron %d vocales.\n", contador);
            break;

        case 5:
            printf("Hasta la proxima. ¡Gracias!\n"); //Anadí una opción extra
            break;

        default:
            printf("Opción no válida. Intente de nuevo.\n");
    }

    return 0;
}
//Las mejoras fueron en el conteo de las vocales, una opción extra de salida al menú y verificación si el número es decimal o no en el case 3

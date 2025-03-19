

#include <stdio.h>
#include <math.h>
#include <string.h>

int main {
int opcion;
float ancho, largo, area;
int numero, suma, digito;
char letra;

switch (opcion) {
 
  // Parte 1: Calcular el área de un rectángulo
  double largo, ancho, area;
    printf("Ingrese el largo del rectángulo: ");
    scanf("%lf", &largo);
    printf("Ingrese el ancho del rectángulo: ");
    scanf("%lf", &ancho);
    
    area = largo * ancho;
    printf("El área del rectángulo es: %.2lf\n", area);

    
    
    // Parte 2: Conversión de Celsius a Fahrenheit
    double celsius, fahrenheit;
    printf("Ingrese la temperatura en grados Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2lf grados Celsius equivalen a %.2lf grados Fahrenheit.\n", celsius, fahrenheit);

   
   
    // Parte 3: Verificar si un número es múltiplo de 2
    int numero;
    printf("Ingrese un número para verificar si es múltiplo de 2: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("%d es múltiplo de 2.\n", numero);
    } else {
        printf("%d no es múltiplo de 2.\n", numero);
    }

    return 0;
}
}




#include <stdio.h>

int main() {
    float inicial, final, intervalo;

    // Pedir al usuario los valores
    printf("Ingrese el valor inicial, final e intervalo para la temperatura en Celsius: ");
    scanf("%f %f %f", &inicial, &final, &intervalo);

    
    int num_elementos = 20;  // Tamaño del arreglo
    float valores[num_elementos][2];  

    // Calcular valores 
    int i;
    for (i = 0; i < num_elementos && (inicial + i * intervalo) <= final; i++) {
        valores[i][0] = inicial + i * intervalo;      // Valor en Celsius
        valores[i][1] = valores[i][0] + 273.15;       // Valor en Kelvin
    }

    // Imprimir resultados 
    printf("\nCelsius\tKelvin\n");
    printf("------------------\n");

    
    for (int j = 0; j < i; j++) {
        printf("%.2f\t%.2f\n", valores[j][0], valores[j][1]);
    }

    return 0;
}

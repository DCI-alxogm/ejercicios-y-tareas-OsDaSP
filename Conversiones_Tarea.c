#include <stdio.h>
#include <math.h>

int main() {
    // Declaración de variables
    int opcion = 0, opcion_coordenadas = 0, modo_angulo = 0;
    float temp, x, y, z, r, theta, phi, valor;

    while (1) { //Instrcción para no crear repetición infinita (pasaba con coordenadas)
        // Opciones principal
        printf("Menú principal:\n");
        printf("1. Transformación de temperaturas\n");
        printf("2. Transformación de coordenadas\n");
        printf("3. Transformación de sistemas de unidades\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Transformación de temperaturas
                printf("Transformación de temperaturas:\n");
                printf("1. Celsius a Kelvin\n");
                printf("2. Kelvin a Celsius\n");
                printf("Seleccione una opción: ");
                scanf("%d", &opcion);

                if (opcion == 1) { //Celsius a Kelvin
                    printf("Ingrese la temperatura en Celsius: ");
                    scanf("%f", &temp);
                    printf("Temperatura en Kelvin: %.2f K\n", temp + 273.15f);
                } else if (opcion == 2) { //Kelvin a Celsius
                    printf("Ingrese la temperatura en Kelvin: ");
                    scanf("%f", &temp);
                    printf("Temperatura en Celsius: %.2f °C\n", temp - 273.15f);
                } else { //Sin no hay una elección válida
                    printf("Opción no válida.\n");
                }
                break;

            case 2:
                // Selección de tipo de ángulos 
                printf("Seleccione el modo de ángulo:\n");
                printf("1. Radianes\n");
                printf("2. Grados\n");
                printf("Seleccione una opción: ");
                scanf("%d", &modo_angulo);

                if (modo_angulo != 1 && modo_angulo != 2) {
                    printf("Modo no válido. Volviendo al menú principal.\n");
                    break;
                }
		//Elección de coordenadas posterior a los ángulos
                printf("Transformación de coordenadas:\n");
                printf("1. Cartesianas a Esféricas\n");
                printf("2. Esféricas a Cartesianas\n");
                printf("3. Cartesianas a Cilíndricas\n");
                printf("4. Cilíndricas a Cartesianas\n");
                printf("Seleccione una opción: ");
                scanf("%d", &opcion_coordenadas);

                switch (opcion_coordenadas) {
                    case 1: //Cartesianas a Esféricas
                        printf("Ingrese x, y, z: ");
                        scanf("%f %f %f", &x, &y, &z);
                        r = sqrt(x * x + y * y + z * z);
                        theta = atan2(y, x);
                        phi = acos(z / r);

                        if (modo_angulo == 2) {
                            theta *= (180.0 / M_PI);
                            phi *= (180.0 / M_PI);
                        }
                        printf("Coordenadas esféricas (r, θ, φ): %.2f, %.2f, %.2f\n", r, theta, phi);
                        return 0; // Finalizar el programa porque entraba en un bucle sin fin
                    case 2: //Esféricas a Cartesianas
                        printf("Ingrese r, θ, φ: ");
                        scanf("%f %f %f", &r, &theta, &phi);

                        if (modo_angulo == 2) {
                            theta *= (M_PI / 180.0);
                            phi *= (M_PI / 180.0);
                        }
                        x = r * sin(phi) * cos(theta);
                        y = r * sin(phi) * sin(theta);
                        z = r * cos(phi);
                        printf("Coordenadas cartesianas (x, y, z): %.2f, %.2f, %.2f\n", x, y, z);
                        return 0; // Finalizar el programa
                    case 3: //Cartesianas a Cilíndricas
                        printf("Ingrese x, y, z: ");
                        scanf("%f %f %f", &x, &y, &z);
                        r = sqrt(x * x + y * y);
                        theta = atan2(y, x);

                        if (modo_angulo == 2) {
                            theta *= (180.0 / M_PI);
                        }
                        printf("Coordenadas cilíndricas (r, θ, z): %.2f, %.2f, %.2f\n", r, theta, z);
                        return 0; // Finalizar el programa
                    case 4: //Cilíndricas a cartesianas
                        printf("Ingrese r, θ, z: ");
                        scanf("%f %f %f", &r, &theta, &z);

                        if (modo_angulo == 2) { 
                            theta *= (M_PI / 180.0);
                        }
                        x = r * cos(theta);
                        y = r * sin(theta);
                        printf("Coordenadas cartesianas (x, y, z): %.2f, %.2f, %.2f\n", x, y, z);
                        return 0; // Finalizar el programa
                    default://Si no hay una elección válida
                        printf("Opción no válida. Volviendo al menú principal.\n");
                }
                break;

            case 3:
                // Transformación de sistemas de unidades
                printf("Transformación de sistemas de unidades (SI a Sistema Inglés):\n");
                printf("1. Longitud (metros a pies)\n");
                printf("2. Masa (kilogramos a libras)\n");
                printf("3. Temperatura (Celsius a Fahrenheit)\n");
                printf("4. Velocidad (m/s a mph)\n");
                printf("Seleccione una opción: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1: //Longitudes
                        printf("Ingrese la longitud en metros: ");
                        scanf("%f", &valor);
                        printf("Longitud en pies: %.2f ft\n", valor * 3.28084f);
                        break;
                    case 2://Masa
                        printf("Ingrese la masa en kilogramos: ");
                        scanf("%f", &valor);
                        printf("Masa en libras: %.2f lbs\n", valor * 2.20462f);
                        break;
                    case 3://Temperatura
                        printf("Ingrese la temperatura en Celsius: ");
                        scanf("%f", &valor);
                        printf("Temperatura en Fahrenheit: %.2f °F\n", (valor * 9 / 5) + 32);
                        break;
                    case 4://Velocidad
                        printf("Ingrese la velocidad en m/s: ");
                        scanf("%f", &valor);
                        printf("Velocidad en mph: %.2f mph\n", valor * 2.23694f);
                        break;
                    default: //Si no hay una elección váilida
                        printf("Opción no válida.\n");
                }
                break;

            case 4:
                // Salir del programa
                printf("Saliendo del programa...\n");
                return 0;

            default: //Si no hay una elección válida 
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }
    return 0;
}

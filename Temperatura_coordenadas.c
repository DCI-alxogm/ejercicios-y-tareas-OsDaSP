#include <stdio.h>
#include <stdlib.h>
#include <math.h>

  int main ()
  {
    float tc, tk; //Variables de temperatura
    float x, y, z; //Coordenadas cartesianas 
    float r, theta, phi; //Coordenadas esféricas
    float rc, theta_c, zc; //Coordenadas cilíndricas
    int opc, opCoordenadas; //Opciones para el usuario
    int op; //Opciones para el usuario
    repetirtodo:
    printf("\n Hola, selecciona que deseas realizar: \n");
    printf("0 - Convertir temperatura °C a Kelvin \n"); 
    printf("1 - Convertir coordenadas cartesianas \n");
    printf("Opción: \n");
    scanf("%d", &opc);
    

    if (opc==0) {
       goto temperatura;
    } else if (opc==1) {
       goto tipoCoordenadas;
    } else {
        printf("Opción no válida, vuelva a intertar \n");
        goto repetirtodo;
    }
    
    temperatura:
    printf("¿Cual es la temperarura que te gustaria convertir en Celcius?\n");
    scanf("%f", &tc);
    tk = tc + 273.15;
    printf("Tu temperatura en Kelvin es: %.2f \n", tk); 
    goto preguntar;

    tipoCoordenadas:
    printf("¿Qué tipo de coordenadas desea obtener? \n");
    printf("1 - Coordenadas cilíndricas \n");
    printf("2 - Coordenadas esféricas \n");
    printf("Opción: \n");
    scanf("%d", &opCoordenadas);
    
    if (opCoordenadas==1){
       goto CartesianasaCilindricas;
    } else if (opCoordenadas==2){
       goto CartesianasaEsfericas;
    } else {
       printf("Opción no válida, vuelva a intentar \n");
       goto tipoCoordenadas;
    }

 
    CartesianasaCilindricas:
    printf("Introduce los valores de las variables x, y, z que quieres convertir \n");
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);
    
    //Operaciones para cilindricas    
    rc = sqrt(x * x + y * y);
    theta_c = atan2(y, x);
    zc = z;
    
    printf("Las coordenadas cilindricas obtenidas son rc=%.2f, theta_c=%.2f rad, z=%.2f  \n", rc, theta_c, zc);
    goto preguntar;
    
     
    CartesianasaEsfericas:
    printf("Introduce los valores de las variables x, y, z que quieres convertir \n");
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);
    
    //Operaciones para esféricas
    r = sqrt(x * x + y * y + z * z);
    theta = atan2(y, x);
    phi = acos(z / r);

    printf("Las coordenadas esfericas obtenidas son r=%.2f, theta=%.2f rad, phi=%.2f rad \n", r, theta, phi);
    goto preguntar;

    preguntar:
    printf("¿Quieres hacer otra conversion? (1 - Sí, 2 - No): \n");
    scanf("%d",  &op);
    
    if (op==1){
       goto repetirtodo;
    }else {
    printf("Hasta la proxima \n");
    return 0;}
 }

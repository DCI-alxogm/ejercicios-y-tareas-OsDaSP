//No considero necesario corregir mi codigo ya que desde mi punto de vista funciona muy bien y esta es la forma en la que a mi se me facilita mas su comprension
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){

   char fname[100];
   FILE *fin, *fout;
   int i, j, iter;
   int num_max=100;
   int n_filas, m_columnas;
   float delta;
   float placa[100][100];
   float nueva[100][100];
   int convergencia=0;


//Adrir archivo de entrada
    fin=fopen("entrada.txt","r");


//Leer dimensiones y delta
    fscanf(fin, "%d %d %f", &n_filas, &m_columnas, &delta);

//Leer los datos
    for (i=0; i<n_filas; i++){
      for (j=0; j<m_columnas; j++){
        fscanf(fin, "%f", &placa[i][j]);
      }
    }
    fclose(fin);

//Inicio de interacciones
    for (iter=0; iter<num_max &&! convergencia; iter++){
      convergencia = 1;

 //Aplicando la ecuacion de laplace
   for (i=1; i<n_filas - 1; i++){
      for (j=1; j<m_columnas-1; j++){
        nueva[i][j] = 0.25*(
         placa[i+1][j] +   // vecino de abajo
         placa[i-1][j] +   // vecino de arriba
         placa[i][j+1] +   // vecino derecho
         placa[i][j-1]     // vecino izquierdo
        );

//Sacar el error relativo
   float error = fabs(1 - (placa[i][j]/nueva[i][j]));

//Si el error es mayor al permitido es porque aun no hay equilibrio, entonces
         if (error>=delta) {
           convergencia=0;
         }
      }
   }

// copiar los valores para la siguiente iteraccion
   for (i=1; i<n_filas-1; i++) {
      for (j=1; j<m_columnas-1; j++) {
         placa[i][j] = nueva[i][j];
      }
   }


//Guardar resultado en el archivo de salida
   sprintf(fname, "salida_iter_%03d.txt", iter);
    fout=fopen(fname,"w");
      for (i=0; i<n_filas; i++){
         for (j=0; j<m_columnas; j++){
           fprintf(fout, "%.2f ", placa[i][j]);
         }
         fprintf(fout, "\n"); //siguiente linea
      }
      fclose(fout);
   }

   printf("Proceso finalizado en %d iteraciones.\n", iter);

   return 0;
}

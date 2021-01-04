#include <stdio.h>
#include "functions.h"
#include<math.h>

int ecuacioncuadratica(int a, int b, int c)
{   
    float discriminante=(b*b)-(4*a*c);
    
    if(discriminante<0){
        printf("No hay soluciones reales\n");
    } 
    else{
        
       float sol1=(-b+sqrtf(discriminante))/(2*a);
       float sol2=(-b-sqrtf(discriminante))/(2*a);
        if(sol1==sol2){
            printf("Poseen la misma solucion, la cual es:%f\n",sol1);
        }else
        {
          printf("Poseen diferente solucion.\n La solucion 1 es:%f\n",sol1); 
          printf("La solucion 2 es :%f\n",sol2);  
        };
        
    } 



    return 0;
}


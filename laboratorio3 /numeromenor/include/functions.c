#include <stdio.h>
#include "functions.h"

int numeromenor( int numero1, int numero2, int numero3)
{   
    int x=0;
    
    if(numero1<numero2 && numero1<numero3){
        x++;
        printf("El numero menor es %d\n",numero1);}
    if(numero2<numero1 && numero2<numero3){
        x++;
        printf("El numero menor es %d\n",numero2);}
    if(numero3<numero2 && numero3<numero1){
        x++;
        printf("El numero menor es %d\n",numero3);}
    if(x==0){
        
        printf("No hay numero menor ya que 2 o mas numeros son iguales\n");}


    return 0;
}


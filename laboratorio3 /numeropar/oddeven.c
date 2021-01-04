#include <stdio.h>
#include "include/functions.h" 
#include<stdlib.h>

//Nota el programa se diseno para ingresar solo 1 numero

int main (int argc, char const *argv[])

{

    int numero = atoi(argv[1]);
    
    numeropar( numero);
    

    return 0;
}
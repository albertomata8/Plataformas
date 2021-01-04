#include <stdio.h>
#include "functions.h"

int numeropar(int numero)
{
    int modulo;
    modulo= numero%2;

    switch (modulo)
    {
        case 0:
            printf("El numero es par\n");
            break;
    
        default:
            printf("El numero es impar\n");
            break;
    }

    return 0;
}


#include <stdio.h>
#include "triangulos.h"
#include <math.h>
#include<stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int cantidadtri= atoi(argv[1]);
    tri* bloque=reserveTri(cantidadtri);
    initTri(bloque, cantidadtri);
    sortTri(bloque,cantidadtri);
    printAllTri(bloque,cantidadtri);
    free(bloque);
     
    return 0;
}
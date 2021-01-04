#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <time.h>
#include "triangulos.h"
#include "impexp.h"

int main(int argc, char const *argv[])
{
    int cantidadtri= atoi(argv[1]);
    tri* bloque=reserveTri(cantidadtri);
    initTri(bloque, cantidadtri);
    FILE* archivo1=fopen("desorden.txt","w");
    FILE* archivo2=fopen("orden1.txt","w");
    exportTristoFile(archivo1,cantidadtri,bloque);
    sortTri(bloque,cantidadtri);
    exportTristoFile(archivo2,cantidadtri,bloque);
    free(bloque);
    fclose(archivo1);
    fclose(archivo2);
    FILE* archivo3=fopen("desorden.txt","r");
    FILE* archivo4=fopen("orden2.txt","w");
    tri* bloquenuevo=reserveTri(cantidadtri);
    int cantidadtrinuevo=importTrisFromFile(archivo3,bloquenuevo);
    sortTri(bloquenuevo,cantidadtrinuevo);
    exportTristoFile(archivo4,cantidadtrinuevo,bloquenuevo);
    free(bloquenuevo);
    fclose(archivo3);
    fclose(archivo4);

    return 0;
}
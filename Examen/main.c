#include <stdio.h>
#include "kmeans.h"
#include <math.h>
#include<stdlib.h>
#include <time.h>
#include<limits.h>//para que me de un limite muy grande o pequeno

int main(int argc, char const *argv[])
{
    srand(time(NULL));//para que cambie de numero aleatorio
    int cantidadK= atoi(argv[1]);//exportar el primer dato de la linea de comandos
    int cantidadObservaciones;
    int* punteroCantidadObservaciones=&cantidadObservaciones;//apunta al contenido ...
    // ...de cantidadObservaciones
    
    FILE* archivo=fopen("data.txt","r");//se abre el file  data.txt con tipo read
    obs* rutamalloc=importData(archivo,punteroCantidadObservaciones);//primera funcion...
    //.... que se solicita, se obtiene rutamalloc la cual contiene la direccion a la ....
    //.... memoria reservada para las observaciones.
    centroide* rutamalloccentroide=getInitialCentroids(cantidadK,rutamalloc,cantidadObservaciones);//segunda funcion...
    //.... que se solicita, se obtiene rutamalloccentroide la cual contiene la direccion a la ....
    //.... memoria reservada para los centroides.
    kMeans(rutamalloccentroide,rutamalloc,cantidadObservaciones,cantidadK);// Tercera funcion solicitada
    FILE* archivonuevo=fopen("clusters.txt","w");//se crea el file  clusters.txt con tipo write
    exportCluster(rutamalloccentroide, rutamalloc, cantidadObservaciones, cantidadK, archivonuevo);//Cuarta funcion solicitada
    free(rutamalloc);// se libera la memoria
    free(rutamalloccentroide);
    fclose(archivo);// se cierran los archivos
    fclose(archivonuevo);
    
    return 0;
}
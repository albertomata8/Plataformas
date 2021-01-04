#if !defined(FUNCTIONS)
#define FUNCTIONS
#include <stdio.h>
#include <math.h>//para poder hacer la raiz cuadrada
#include<stdlib.h>//para extraer los datos de linea de comandos
#include <time.h>//para hacer los numeros aleatorios
#include<limits.h>//para que me de un limite muy grande o pequeno

//Primeramente se realizan los tipos de datos p2D, obs y centroide
typedef struct p2D 
{
    double x;
    double y;

}p2D;

typedef struct obs 
{
    p2D punto;
    int etiqueta;

}obs;

typedef struct centroide 
{
    p2D puntocentroide;
    int etiquetacentroide;

}centroide;
// Primera funcion solicitada:
obs* importData( FILE* archivo, int* punteroCantidadObservaciones);

//Segunda funcion solicitada
centroide* getInitialCentroids(int cantidadK,obs* rutamalloc, int cantidadObservaciones);

//Esta funcion va dentro Etiquetar, se utiliza para determinar distancia Eucilinana
double distanciaEucliniana(centroide centroide1, obs obs1);

// Esta funcion etiqueta a todas las observaciones y va dentro de la funcion kMeans
void Etiquetar(centroide* rutamalloccentroide,obs* rutamalloc, int cantidadObservaciones, int cantidadK);

// Saca el promedio de todos dentro de la etiqueta y los sustituye en la memoria reservada de rutamalloccentroide
//Va dentro de la funcion kMeans
void Promedio(centroide* rutamalloccentroide,obs* rutamalloc, int cantidadObservaciones, int cantidadK);
//Tercera funcion solicitada
void kMeans(centroide* rutamalloccentroide,obs* rutamalloc, int cantidadObservaciones, int cantidadK);
//Cuarta funcion solicitada
void exportCluster(centroide* rutamalloccentroide, obs* rutamalloc,int cantidadObservaciones, int cantidadK, FILE* archivonuevo);


#endif // FUNCTIONSs/
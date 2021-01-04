#if !defined(FUNCTIONS)
#define FUNCTIONS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <time.h>
typedef struct p2D 
{
    double x;
    double y;

}p2D;

typedef struct tri 
{
    p2D A;
    p2D B;
    p2D C;

}tri;

void setSeed(unsigned int semilla);
double randNum(double min, double max);
p2D randP2D();
double dist(p2D p1, p2D p2);
p2D randP2DTri(p2D p1);
int triIneq(p2D p1, p2D p2, p2D p3);
tri randTri(p2D p1);
double calcArea(tri t1);
tri* reserveTri(int cantidadtri);
void initTri(tri* rutamalloc, int cantidadtri);
void sortTri(tri* rutamalloc, int cantidadtri);
void printTri(tri t1);
void printAllTri(tri* rutamalloc, int cantidadtri);
#endif // FUNCTIONSs
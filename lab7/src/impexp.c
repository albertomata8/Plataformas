#include <stdio.h>
#include "impexp.h"
#include "triangulos.h"
#include <math.h>
#include<stdlib.h>
#include <time.h>

void exportTristoFile(FILE* archivo, int cantidadtri,tri* bloque){
    for (int i = 0; i < cantidadtri; i++)
    {
        fprintf(archivo,"Triangulo %d \n A: %.1f %.1f \n B:  %.1f %.1f \n C: %.1f %.1f \n Area: %.1f \n \n",
        i+1,bloque[i].A.x,bloque[i].A.y, bloque[i].B.x,bloque[i].B.y, bloque[i].C.x,bloque[i].C.y,calcArea(bloque[i]));
    }
}

int importTrisFromFile(FILE* archivo, tri* bloquenuevo){
    char buffer[1000];
    double bufferNumeroTri;
    double bufferNumeroAx;
    double bufferNumeroAy;
    double bufferNumeroBx;
    double bufferNumeroBy;
    double bufferNumeroCx;
    double bufferNumeroCy;
    double bufferArea;
    int i=0;
    while(fscanf(archivo,"%s %lf %s %lf %lf %s %lf %lf %s %lf %lf %s %lf  ",
    &buffer,&bufferNumeroTri, &buffer, &bufferNumeroAx, &bufferNumeroAy,&buffer,&bufferNumeroBx,
    &bufferNumeroBy, &buffer,&bufferNumeroCx,&bufferNumeroCy, &buffer, &bufferArea)!=-1){
       
       bloquenuevo[i].A.x=bufferNumeroAx;
       bloquenuevo[i].A.y=bufferNumeroAy;
       bloquenuevo[i].B.x=bufferNumeroBx;
       bloquenuevo[i].B.y=bufferNumeroBy;
       bloquenuevo[i].C.x=bufferNumeroCx;
       bloquenuevo[i].C.y=bufferNumeroCy;
       i++;
    }
    return i;

}
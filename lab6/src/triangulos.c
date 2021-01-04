#include <stdio.h>
#include "triangulos.h"
#include <math.h>
#include<stdlib.h>
#include <time.h>

void setSeed(unsigned int semilla){
    srand(semilla);
}

double randNum(double min, double max){
    int a=(max*10)+1-(min*10);
    int b=min*10;
    double numaleatorio =(float)(rand()%(a)+b)/10;
    return numaleatorio;
}
p2D randP2D(){
    int a=500+1+500;
    int b=-500;
    int i=0;

    double numaleatorio =(float)(rand()%(a)+b)/10;
    double numaleatorio2 =(float)(rand()%(a)+b)/10;
    p2D puntoaleatorio;
    puntoaleatorio.x = numaleatorio;
    puntoaleatorio.y = numaleatorio2;
    return puntoaleatorio;
}
double dist(p2D p1, p2D p2){
    double xtotal=p1.x-p2.x;
    double ytotal= p1.y-p2.y;
    double distancia=sqrt(pow(xtotal,2)+pow(ytotal,2));
    return distancia;
}
p2D randP2DTri(p2D p1){
    p2D puntoaleatorio;
    double distancia=101;
    while (distancia>10)
    {
        puntoaleatorio=randP2D();
        distancia=dist(p1,puntoaleatorio);
    }
    return puntoaleatorio;
} 
int triIneq(p2D p1, p2D p2, p2D p3){
    double lado1=dist(p1,p2);
    double lado2=dist(p1,p3);
    double lado3=dist(p3,p2);
    if ((lado1+lado2)>lado3 && (lado1+lado3)>lado2 && (lado3+lado2)>lado2 )
    {
        return 1;
    }else{
        return 0;
    }
}
tri randTri(p2D p1){
    p2D p2;
    p2.x=0;
    p2.y=0;
    p2D p3;
    p3.x=0;
    p3.y=0;
    int triIneqq=0;
    while (triIneqq==0)
    {
        while (p2.x==p3.x && p2.y==p3.y){
            p2=randP2DTri(p1);
            p3=randP2DTri(p1);
        }
        triIneqq=triIneq(p1,p2,p3);


    }
    tri trialeatorio;
    trialeatorio.A=p1;
    trialeatorio.B=p2;
    trialeatorio.C=p3;
    return trialeatorio;
}
double calcArea(tri t1){
    double lado1=dist(t1.A,t1.B);
    double lado2=dist(t1.A,t1.C);
    double lado3=dist(t1.C,t1.B);
    double s= (lado1+lado2+lado3)/2;
    double area=sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
    return area;
}
tri* reserveTri(int cantidadtri){
    tri* rutamalloc= malloc(cantidadtri*sizeof(tri));
    return rutamalloc;
}
void initTri(tri* rutamalloc, int cantidadtri){
    for (int i = 0; i < cantidadtri; i++)
    {
        p2D puntoaleatorio=randP2D();
        rutamalloc[i]=randTri(puntoaleatorio);
    }
    
}
void sortTri(tri* rutamalloc, int cantidadtri){
    tri a;
    tri b;
    tri c;
    int z=0;
    int k=0;
    int t=0;
    tri copiarutamalloc [cantidadtri];
    for (int i = 0; i < cantidadtri; i++)
    {
        copiarutamalloc [i]=rutamalloc[i];
    }
    for (int i = 0; i < cantidadtri; i++)
    {
        a=copiarutamalloc[i];
        for (int i = 0; i < cantidadtri; i++)
        {
            b=copiarutamalloc[i];
            if (calcArea(a)>calcArea(b))
            {
                z++;
            }
            if (calcArea(a)==calcArea(b))
            {
                if (a.A.x!=b.A.x || a.A.y!=b.A.y || a.B.x!=b.B.x || a.B.y!=b.B.y || a.C.x!=b.C.x || a.C.y!=b.C.y)
                {
                    k++;
                    if (k>1)
                    {
                        t++;
                        c=b;
                    }
                    
                }  
                
            }
        }
        if (calcArea(a)<calcArea(c)){
            rutamalloc[z]=a;
        }else
        {
            rutamalloc[z+t]=a;   
        }
        
        
        z=0;
    }
}
void printTri(tri t1){
    printf("Triangulo:\n");
    printf("A: (%.1f,%.1f)\n",t1.A.x,t1.A.y);
    printf("B: (%.1f,%.1f)\n",t1.B.x,t1.B.y);
    printf("C: (%.1f,%.1f)\n",t1.C.x,t1.C.y);
    printf("Area: %.1f\n",calcArea(t1));
}
void printAllTri(tri* rutamalloc, int cantidadtri){
    for (int i = 0; i < cantidadtri; i++)
    {
        printTri(rutamalloc[i]);
    }
    
}
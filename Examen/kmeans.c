#include <stdio.h>
#include "kmeans.h"//importar el archivo donde estan declaradas
#include <math.h>//para poder hacer la raiz cuadrada
#include<stdlib.h>//para extraer los datos de linea de comandos
#include <time.h>//para hacer los numeros aleatorios
#include<limits.h>//para que me de un limite muy grande o pequeno


//Primera funcion solicitada:

obs* importData( FILE* archivo, int* punterocantidadPoint){
    double buffer1;// se definen los buffers que establecen....
    //...como esta conformado el archivo
    double buffer2;
    int cantidad=0;
    // este primer while informa cuantas observaciones hay.....
    //....y lo guarda en variable cantidad
    while(fscanf(archivo,"%lf %lf",
    &buffer1,&buffer1)!=-1){
       
       cantidad++;
    }
    //De esta manera se logra llenar cantidadObservaciones, debido a que ahi....
    //... es donde apunta punterocantidadPoint 
    *punterocantidadPoint=cantidad;
    fclose(archivo);//se cierra el archivo
    archivo=fopen("data.txt","r");//y se vuelve a abrir para reutilizarlo
    obs* rutamalloc= malloc(cantidad*sizeof(obs));// se reserva la memoria...
    //...para la cantidad obtenida de observaciones
    double bufferx;// como en el caso anterior se definen los buffers que establecen....
    //...como esta conformado el archivo.
    double buffery;
    int j=0;//Variable para ubicar cada casilla de memoria reservada
    while(fscanf(archivo,"%lf %lf",&bufferx,&buffery)!=-1){
       rutamalloc[j].punto.x=bufferx;//aqui se va guardando cada dato en su respectiva...
       // casilla que tenia reservada para el tipo obs
       rutamalloc[j].punto.y=buffery;
       rutamalloc[j].etiqueta=0;
       j++;
    }

    return rutamalloc; // retorna rutamalloc la cual contiene la direccion de la memoria....
    //...reservada de tipo obs
}
// Segunda funcion solicitada
centroide* getInitialCentroids(int cantidadK,obs* rutamalloc, int cantidadObservaciones){
    //para obtener el centroide se deben de seleccionar alguna observacion de forma aleatoria
    
    int a=(cantidadObservaciones-1);// "a" vendria siendo la maxima posicion de observacion
    int b=0;// "b" vendria siendo la minima posicion de observacion 
    int numerorepetido[cantidadK];
    centroide* rutamalloccentroide= malloc(cantidadK*sizeof(centroide));//los espacios necesarios ...
    // ....para la memoria centroide
    for (int i = 0; i < cantidadK; i++)// mediante este for se llena la memomria reservada para centroides
    {
        int numaleatorio =rand()%a+b;
        if (i>0)//funcion para que se no se repitan numeros aleatorios.
        {
            for (int j = 0; j < i; j++)
            {
                while (numaleatorio==numerorepetido[j])
                {
                     numaleatorio =rand()%(a)+b;//Numero aleatorio con rango[0,299]
                }
            }
        }
        
        numerorepetido[i]=numaleatorio;
        
        
        //Se llena la memoria reservada *rutamalloccentroide a partir de posiciones aleatorias de....
        //... la memoria reservada *rutamalloc
        rutamalloccentroide[i].puntocentroide.x=rutamalloc[numaleatorio].punto.x;
        rutamalloccentroide[i].puntocentroide.y=rutamalloc[numaleatorio].punto.y;
        rutamalloccentroide[i].etiquetacentroide=i+1;
    }
    
    return rutamalloccentroide;// retorna rutamalloccentroide la cual contiene la direccion de la memoria....
    //...reservada de tipo centroide
    
}
//Esta siguiente funcion va dentro de Etiquetar, saca la distancia Eucliniana
double distanciaEucliniana(centroide centroide1, obs obs1){
    double xtotal=centroide1.puntocentroide.x- obs1.punto.x;// Se obtienen la diferencia entre las 2 equis
    double ytotal= centroide1.puntocentroide.y - obs1.punto.y; // Se obtienen la diferencia entre las 2 yes
    double distancia=sqrt((xtotal*xtotal)+(ytotal*ytotal));// Se aplica la formula par la distancia Eucliniana
    return distancia;// retorna la distancia calculada
}
//Esta siguiente funcion etiqueta todas las observaciones y va dentro de kMeans
void Etiquetar(centroide* rutamalloccentroide,obs* rutamalloc, int cantidadObservaciones, int cantidadK){
    double distancia=INT_MAX;//nos pone un valor muy grande
    for (int i = 0; i < cantidadObservaciones; i++)//Primer for para ir variendo cada posiciom de las observaciones
    {
        obs obs1=rutamalloc[i];//variable con el contenido dentro de la memoria reservada hacia donde....
        //... apunta rutamalloc, osea se obtienen las observaciones.Se hace de manera que se pueda trabajar con estos datos
        for (int j = 0; j < cantidadK ; j++)
        {
            centroide centroide1=rutamalloccentroide[j];//variable con el contenido dentro de la memoria reservada hacia donde....
        //... apunta rutamalloccentroide osea se obtienen los centroides
            double distancianueva=distanciaEucliniana(centroide1, obs1);//variable con el valor de la distancia Eucliniana....
            //... obtenida con el datos de la observacion y el centroide
            if (distancianueva<distancia)// comparacion para descurbrir cual es la distancia menor
            {
                distancia=distancianueva;
                rutamalloc[i].etiqueta=rutamalloccentroide[j].etiquetacentroide;//cambia la etiqueta de la observacion a la...
                //.... etiqueta que pusee el centroide con el que posee menor distancia.
            }


        }
        distancia=INT_MAX;//para reiniciar el ciclo
        

    }
   
}
// En la siguiente funcion se saca el promedio de todas las observaciones de respectiva etiqueta y dichos valores se ....
//....sustituyen en la memoria reservada de rutamalloccentroide, osea se reemplazan los centroides.
//Esta funcion va dentro de kMeans.
void Promedio(centroide* rutamalloccentroide,obs* rutamalloc, int cantidadObservaciones, int cantidadK){
    double vectorx=0;//se define la variable que va a poseer la sumatoria de equis
    double vectory=0;//se define la variable que va a poseer la sumatoria de ye
    double size=0;// se define cuantos elementos se estan sumando
    

    for (int i = 0; i <cantidadK; i++)//"for" para ir variando el centroide
    {
        for ( int j = 0; j <cantidadObservaciones; j++)// "for" para ir variando la observacion
        {
            if (rutamalloc[j].etiqueta==i+1)// el if establece que si la observacion posee....
            //...la misma etiqueta que el centroide entre al if, donde se le sumaran los valores..
            //... a los vetores "x" y "y" 
            {
              vectorx=vectorx+rutamalloc[j].punto.x;//sumatoria de todas las x
              vectory=vectory+rutamalloc[j].punto.y;// sumatoria de todas las y
              size++;

            }
            
        }
        //se sacar promedio y se cambia en la memoria reservada del centroide, osea que se estan...
        //... reemplazando los centroides inicialmente seleccionados de manera aleatoria por el ...
        //... promedio
        if (size==0)
        {
            size=1;
        }
        
        double promediox=vectorx/size;
        double promedioy=vectory/size;
        if (vectorx!=0&&vectory!=0)// este if se pone para 
        {
            rutamalloccentroide[i].puntocentroide.x=promediox;
            rutamalloccentroide[i].puntocentroide.y=promedioy;
        }
        
        vectorx=0;
        vectory=0;
        size=0;
        
        
    }
}


// Tercera funcion solicitada
void kMeans(centroide* rutamalloccentroide,obs* rutamalloc, int cantidadObservaciones, int cantidadK){
    for (int i = 0; i < 100; i++)// Debido a que se piden 100 iteraciones
    {
        //se llaman a las siguientes funciones:
        Etiquetar(rutamalloccentroide,rutamalloc,cantidadObservaciones,cantidadK);
        Promedio(rutamalloccentroide,rutamalloc,cantidadObservaciones,cantidadK);
        //rutamalloccentroide[i].puntocentroide.x;
        //rutamalloccentroide[i].puntocentroide.y;
        
    }
    
}
// Cuarta funcion solicitada
void exportCluster(centroide* rutamalloccentroide, obs* rutamalloc,int cantidadObservaciones, int cantidadK, FILE* archivonuevo){
    for (int i = 0; i < cantidadK; i++)// For para escribir en el archivo nuevo todos los centroides
    {
        fprintf(archivonuevo,"%.3lf %.3lf %d \n",rutamalloccentroide[i].puntocentroide.x,rutamalloccentroide[i].puntocentroide.y,rutamalloccentroide[i].etiquetacentroide);
    }
    for (int j = 0; j <1; j++)// For para escribir en el archivo nuevo el espacio en blanco
    {
        fprintf(archivonuevo,"\n");
    }
    for (int i = 0; i < cantidadObservaciones; i++) // For para escribir en el archivo nuevo todas las observaciones
    {
        fprintf(archivonuevo,"%.3lf %.3lf %d \n",rutamalloc[i].punto.x,rutamalloc[i].punto.y,rutamalloc[i].etiqueta);
    }

}
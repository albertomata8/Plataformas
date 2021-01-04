#include <stdio.h>
#include<stdlib.h>

void search(int arr[],int tamanio, int buscar){
    int aparecio=0;
    for( int i = 0;i < tamanio; i++)
    {
        if (buscar==arr[i])
        {
            printf("%d ",i);
            aparecio++;
        }
        
    }
    
    
}

int main (int argc, char const *argv[])

{
    int tamanio= 6; //se debe de cambiar si se cambia el tamanio
    // del arreglo   
    int arr[]={31,14,9,7,20,14};//uno lo introduce
    int buscar=21;// numero que se quiere buscar

    search(arr,tamanio,buscar);

    


    return 0;
}
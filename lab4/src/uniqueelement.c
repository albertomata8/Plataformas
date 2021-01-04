#include <stdio.h>
#include<stdlib.h>

int main (int argc, char const *argv[])

{
    int arr [argc]; 


    for( int i = 1;i < argc; i++)
    {
      arr[i]= atoi(argv[i]);
     
    }

    if(argc>21||argc==1){
        printf("error\n");
    }else
    {
    int a=1;
    int aparecio=0;

    while (a<argc)
    {
        int numero = arr[a];
        
        for (int b = 1; b < argc; b++)
        {
            int numero2 = arr[b];
            
            if (numero == numero2)
            {
                aparecio = aparecio + 1;
                
            }
            if(aparecio>1){
                
                int cantidad = sizeof(arr)/4;
                // se divide entre 4 porque el entero ocupa 4 bites
                int d =b;
                
                while (d< (cantidad-1))
                {
                    arr[d]=arr[d+1];
                    d++;
                    //funcion para eliminar un numero repetido
                }
                
                
            }
        }
        aparecio=0;
        a++;
    }

    int cantidad2 =(sizeof(arr)/4);
    printf("%d\n",arr[1]);
    for (int i = 2; i < cantidad2; i++)
    {
        if(arr[i]!=arr[i+1]){
        printf("%d\n",arr[i]);
        }
    }


    }
    


    return 0;
}

#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int numeroaleatorio(int limitemenor, int limitemayor){
    srand(time(NULL));
    int numaleatorio =rand()%(limitemayor+1-limitemenor)+limitemenor;
    return numaleatorio;
}
void ciclo(int numaleatorio, int limitemenor,int limitemayor){
    int num1;
    float N= (1.0*(limitemayor-limitemenor)/3);
    int n=0;
    while (num1!=numaleatorio && n<=N)
        {
            printf("Inserte un numero:");
            scanf("%d",&num1);
            
            if(num1>=limitemenor && num1<=limitemayor && num1<numaleatorio){
                printf("El numero es mayor\n");
            }
            if(num1>=limitemenor && num1<=limitemayor && num1>numaleatorio){
                printf("El numero es menor\n");
            }
            if (num1<limitemenor || num1>limitemayor)
            {
            printf("error\n");
            break;
            }
            n++;

        }
        if (n>N &&num1!=numaleatorio)
        {
            printf("Se acabaron los intentos\n");
        }
        
        if (num1==numaleatorio)
        {
            printf("correcto\n");
        }
        

}

int main (int argc, char const *argv[])

{
    int limitemenor= atoi(argv[1]);
    int limitemayor= atoi(argv[2]);

    int numaleatorio =numeroaleatorio(limitemenor,limitemayor);
    int num1;
    int num2;
    
    ciclo(numaleatorio,limitemenor,limitemayor);

    return 0;
}
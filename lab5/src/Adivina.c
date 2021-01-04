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
    printf("Inserte un numero:");
    scanf("%d",&num1);
    while (num1!=numaleatorio)
        {
            
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
            printf("Inserte otro numero:");
            scanf("%d",&num1);
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
    ciclo(numaleatorio,limitemenor,limitemayor);
    

    return 0;
}
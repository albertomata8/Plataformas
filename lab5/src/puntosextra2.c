#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int numeroaleatorio(int limitemenor, int limitemayor){
    srand(time(NULL));
    int numaleatorio =rand()%(limitemayor+1-limitemenor)+limitemenor;
    return numaleatorio;
}
void ciclo(int numaleatorio, int limitemenor,int limitemayor){
    float N= (1.0*(limitemayor-limitemenor)/3);
    int n=0;
    float num1;
    float rangohirviendo= numaleatorio-(0.95*numaleatorio);
    float rangocaliente= numaleatorio-(0.75*numaleatorio);
    float rangofrio= numaleatorio-(0.50*numaleatorio);
    int caliente=0;
    int frio=0;
    int hirviendo=0;
    float menorhirviendo = 1.0*(numaleatorio-rangohirviendo);
    float mayorhirviendo = 1.0*(numaleatorio+rangohirviendo);
    float menorcaliente = 1.0*(numaleatorio-rangocaliente);
    float mayorcaliente = 1.0*(numaleatorio+rangocaliente);
    float menorfrio = 1.0*(numaleatorio-rangofrio);
    float mayorfrio = 1.0*(numaleatorio+rangofrio);
    while (num1!=numaleatorio && n<=N)
        {
            printf("Inserte un numero:");
            scanf("%f",&num1);
            if(num1!=numaleatorio && num1>=limitemenor && num1<=limitemayor && menorhirviendo<=num1 && num1<=mayorhirviendo){
                printf("Hirviendo\n");
                hirviendo++;
            }
            if(num1!=numaleatorio && num1>=limitemenor && num1<=limitemayor && menorcaliente<=num1 && num1<=mayorcaliente && hirviendo==0){
                printf("Caliente\n");
                caliente++;
            }
            if(num1!=numaleatorio && num1>=limitemenor && num1<=limitemayor && menorfrio<=num1 && num1<=mayorfrio && caliente==0 && hirviendo==0){
                printf("Frio\n");
                frio++;
            }
            if(num1!=numaleatorio && num1>=limitemenor && num1<=limitemayor && frio==0 && caliente==0 && hirviendo==0){
                printf("Helado\n");
                
            }
            
            hirviendo=0;
            caliente=0;
            frio=0;
            
            if (num1<limitemenor||num1>limitemayor)
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
    //printf("Numero aleatorio %d\n",numaleatorio);
    ciclo(numaleatorio,limitemenor,limitemayor);

    return 0;
}
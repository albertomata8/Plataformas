#include <stdio.h>
#include<stdlib.h>

int tacharmultiplos(int arr[],int limitenuevo){

    int d=0;
    
    
    for ( int i =1;i <= limitenuevo; i++)
    {
        int modulo = arr[i] % arr[0];
        
        if (modulo ==0 )
        {
            d=i;
            
            while(d< limitenuevo)
            { 
               arr[d]=arr[d+1];

                d++;
                
                
            }
            i--;
            limitenuevo--;
           
            
        }
        d=0;
        
    }

    

    return limitenuevo;

}

void Quitarprimerelemento(int arr[], int limitenuevo){
    int d=0;

    while(d< limitenuevo)
            { 
               arr[d]=arr[d+1];

                d++;   
            }

}
    



int main (int argc, char const *argv[])

{
    int limite=atoi(argv[1]);
    int lim= limite-1;
    int y=-1;
    int ymil=-1;
    int arr[lim];
    int arrmil[999];
    int hastanumero[lim];
    int hastamil[999];

    for( int i =2;i <= limite; i++)
    { 
       y++;
       arr[y]= i;
        
    }
    for( int i =2;i <= 1000; i++)
    { 
       ymil++;
       arrmil[ymil]= i;
        
    }

    int limitenuevo=y;
    int limitenuevomil=ymil;
    int primerelemento=(2*2);
    int primerelementomil=(2*2);
    int k=0;
    int p=0;
    
    
    while (primerelemento<limite )
    {
    
        hastanumero[k]=arr[0];
        limitenuevo = tacharmultiplos(arr,limitenuevo);
        Quitarprimerelemento(arr, limitenuevo);
        primerelemento=(arr[0]*arr[0]);
        k++;

    }
    while (primerelementomil<1000 )
    {
    
        
        hastamil[p]=arrmil[0];
        limitenuevomil = tacharmultiplos(arrmil,limitenuevomil);
        Quitarprimerelemento(arrmil, limitenuevomil);
        primerelementomil=(arrmil[0]*arrmil[0]);
        p++;

    }
    
    
    for( int i =0;i < limitenuevo; i++)
    { 
        if (arr[i]==arr[i-1])
       {   
       }else
       {
           //printf("%d\n",arr[i]);
           hastanumero[k]=arr[i];
           k++;
       }

    }
    for( int i =0;i < k; i++)
    { 
        //printf("%d hasta numero\n",hastanumero[i]);
    }
    for( int i =0;i < limitenuevomil; i++)
    { 
        if (arrmil[i]==arrmil[i-1])
       {   
       }else
       {
         
           hastamil[p]=arrmil[i];
           p++;
       }

    }
    for( int i =0;i < p; i++)
    { 
        
        if (hastamil[i]==limite &&hastamil[i]==hastanumero[i])
           {
               printf("%d \n",hastamil[i]);
           }
       if(hastamil[i]!=hastanumero[i]){
          printf("%d \n",hastamil[i]);
       }
        
           
       
       
    }
    



    return 0;
}
    
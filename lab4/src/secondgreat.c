#include <stdio.h>
#include<stdlib.h>

int main (int argc, char const *argv[])

{
    int arr [argc]; 
    int numerospositivos=0;
    int numerosnegativos=0;
    for( int i = 1;i < argc; i++)
    {
      
      arr[i]= atoi(argv[i]);
      if (arr[i]>=0)
      {
        numerospositivos++;
      }

      if (arr[i]<0)
      {
        numerosnegativos++;
      }
      

    }
    if (numerospositivos>1 )
    {
      int a=1;
      int b=1;
      int numeromayor=0;
      int segundomayor =0;
      while (b<argc){
        int numero1 = arr[b];
        if (numero1>numeromayor)
        {
          numeromayor= numero1;
        };
        b++;

      }

      while (a<argc)
      {
       int numero = arr[a];
        if (numero>segundomayor && numero<numeromayor){
        segundomayor=numero;
        };
      a++;
      
      }

      int c=1;
      int datocero=0;
      while (c<argc){
        int num2= arr[c];
        c++;
        if (num2==0)
        {
          datocero=1; 
        }
      
      }

      if (segundomayor ==0 && datocero==0)
      {
        segundomayor= numeromayor;
      }
    
  
    
      if  (argc<3)
      {
        printf("error\n");
      }else
      {

        printf("Segundo numero mayor:%d\n",segundomayor);
      }
      
    }
    if (numerospositivos==1 && numerosnegativos>0)
    {
      int a=1;
      int b=1;
      int numeromayor=0;
      int segundomayor =0;
      while (b<argc){
        int numero1 = arr[b];
        if (numero1>numeromayor)
        {
          numeromayor= numero1;
        };
        b++;
      }

      
      while (a<argc)
      {
       int numero = arr[a];
       if (numero<0){
         if (segundomayor==0)
         {
           segundomayor=numero;
         }
         if (numero>segundomayor)
         {
           segundomayor==numero;
         }
         
           
       };
        a++;
      }
     
      printf("Segundo numero mayor:%d\n",segundomayor);




    }
    if (numerospositivos==0 && numerosnegativos>1)
    {
      int a=1;
      int b=1;
      int numeromayor=0;
      int segundomayor =0;
      while (b<argc){
        int numero1 = arr[b];
        if (numeromayor== 0)
        {
          numeromayor= numero1;
        };
        if (numero1>numeromayor)
        {
          numeromayor= numero1;
        };
        b++;
      }
      while (a<argc)
      {
       int numero = arr[a];
       if (numero<numeromayor && segundomayor==0){
         segundomayor= numero; 
       };
       if (numero<numeromayor && numero >segundomayor)
       {
         segundomayor= numero; 
       };
        a++;
      }
      if(segundomayor==0){
        segundomayor= numeromayor;
      }
      
      printf("Segundo numero mayor:%d\n",segundomayor);




    }
    
    if (numerospositivos==0 && numerosnegativos==1){
      printf("error\n");
    }
    if (numerospositivos==1 && numerosnegativos==0){
      printf("error\n");
    }
    if (numerospositivos==0 && numerosnegativos==0){
      printf("error\n");
    }
    
    
    

    return 0;
}
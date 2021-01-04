#include <stdio.h>
#include "include/functions.h" 
#include<stdlib.h>
#include<math.h>
int main (int argc, char const *argv[])

{

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    ecuacioncuadratica(a,b,c);
    

    return 0;
}
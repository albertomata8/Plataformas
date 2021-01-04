#if !defined(FUNCTIONS2)
#define FUNCTIONS2
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <time.h>
#include "triangulos.h"

void exportTristoFile(FILE* archivo, int cantidadtri, tri* bloque);
int importTrisFromFile(FILE* archivo, tri* bloquenuevo);
#endif // FUNCTIONS2
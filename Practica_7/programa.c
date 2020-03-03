#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50000000

int main (){

    long seno=0,coseno=0,tangente=0,logaritmo=0,raiz=0;
    double i = 0;

    while(i < MAX){
        seno += sin(i);
        coseno += cos(i);
        tangente += tan(i);
        logaritmo += log(i);
        raiz += sqrt(i);
        i++;
    }
    printf("TERMINE\n");
    return 0;
}
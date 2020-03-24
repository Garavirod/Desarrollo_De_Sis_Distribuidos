#include<iostream>
#include <math.h>
#define MAX 50000000

using namespace std;

int main (){

    long seno,coseno,tangente,logaritmo,raiz;
    double i = 0;

    while(i < MAX){
        seno += sin(i);
        coseno += cos(i);
        tangente += tan(i);
        logaritmo += log(i);
        raiz += sqrt(i);
        i++;
    }
    cout << "termine" << endl;
    return 0;
}
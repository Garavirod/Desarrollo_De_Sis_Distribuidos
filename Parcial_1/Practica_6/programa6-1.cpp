#include<iostream>
#include<vector>
#include "PoligonoIrreg.h"
#include<iomanip>

#define N 11 //Variable que define el número de vertices
using namespace std;

int main(int argc, char const *argv[])
{
    
    // EJERCICIO 1
    PoligonoIrreg pr;
    pr.anadeVerticesPush(N);
    pr.imprimeVertice();


    // EJERCICIO 2
    cout<<endl;
    pr.ordenaA();
    pr.imprimeVertice();

    return 0;
}

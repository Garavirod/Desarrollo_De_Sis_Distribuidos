#include "Fraccion.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Fraccion f;
    f.inicializaFraccion(4,6);
    cout<<f.operaFraccion()<<endl;
    f.printFraccion();
    f.imprimeFraccionSimp();
    return 0;
}

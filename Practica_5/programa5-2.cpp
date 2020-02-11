#include<iostream>
#include<vector>
#include "PoligonoIrreg.h"
#include "Coordenada.h"


using namespace std;



int main(int argc, char const *argv[])
{
    PoligonoIrreg p1;
    vector<PoligonoIrreg> v_obj;
    p1.anadeVertice(Coordenada(2,5));
    p1.anadeVertice(Coordenada(4,1));
    p1.anadeVertice(Coordenada(6,9));
    p1.anadeVertice(Coordenada(7,7));
    p1.anadeVertice(Coordenada(1,6));
    // Imprimimos los vertices del poligono
    p1.imprimeVertice();

    // Ejercico 3
    cout<<"Var estática >: "<<PoligonoIrreg::cuentaVertices<<endl;



    return 0;
}

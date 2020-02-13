#include<iostream>
#include<vector>
#include "PoligonoIrreg.h"
#include "Coordenada.h"
#define N 11000 //Variable que define el número de polígonos

using namespace std;



int main(int argc, char const *argv[])
{
    // EJERCICIO 2

    // PoligonoIrreg p1;
    // vector<PoligonoIrreg> v_obj;
    // p1.anadeVertice(Coordenada(2,5));
    // p1.anadeVertice(Coordenada(4,1));
    // p1.anadeVertice(Coordenada(6,9));
    // p1.anadeVertice(Coordenada(7,7));
    // p1.anadeVertice(Coordenada(1,6));
    // Imprimimos los vertices del poligono
    // p1.imprimeVertice();

    

    // EJERCICIO 3
    vector<PoligonoIrreg> p1;
    vector<PoligonoIrreg> p2;

    // Push
    if (atoi(argv[1]) == 0)
    {
        for (int i = 0; i < N; i++)
        {
            p1.push_back(PoligonoIrreg());
            p1[i].anadeVerticesPush(N);
        }

    }

    // Reserve
    if (atoi(argv[1]) == 1)
    {
        p2.reserve(N);
        for (int i = 0; i < N; i++)        
            p2[i].anadeVerticesReserve(N);
        
    }


    cout<<"Var estática >: "<<PoligonoIrreg::cuentaVertices<<endl;



    return 0;
}

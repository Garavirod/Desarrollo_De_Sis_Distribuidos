#include<iostream>
#include<vector>
#include "Coordenada.h"

#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

class PoligonoIrreg
{
private:
    std::vector<Coordenada> vc;
public:
    PoligonoIrreg(/* args */);
    void anadeVertice(Coordenada c);
    void imprimeVertice();
    void anadeVerticesReserve(int);
    static int cuentaVertices;

};
#endif

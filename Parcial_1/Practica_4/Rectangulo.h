#include "Coordenada.h"
#ifndef RECTANGULO_H_
#define RECTANGULO_H_

class Rectangulo
{
private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;

public:
    Rectangulo(/* args */);
    Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
    Rectangulo(Coordenada c1, Coordenada c2);
    void imprimeEsq();
    double obtenArea();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
};
#endif

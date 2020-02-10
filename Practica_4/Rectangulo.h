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
    void imprimeEsq();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
    ~Rectangulo();
};
#endif

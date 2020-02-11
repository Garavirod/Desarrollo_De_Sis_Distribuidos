#include "Rectangulo.h"
#include <cmath>
#include <iostream>
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0, 0), inferiorDer(0, 0)
{
}

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer) : superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{
}

Rectangulo::Rectangulo(Coordenada c1, Coordenada c2) : superiorIzq(c1), inferiorDer(c2)
{
}

void Rectangulo::imprimeEsq()
{
    cout << "Para la esquina superior izquierda.\n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha.\n";
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}
double Rectangulo::obtenArea()
{
    double ancho, alto;
    alto = obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
    ancho = obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX();
    return abs(alto * ancho);
}

Coordenada Rectangulo::obtieneSupIzq()
{
    return superiorIzq;
}
Coordenada Rectangulo::obtieneInfDer()
{
    return inferiorDer;
}
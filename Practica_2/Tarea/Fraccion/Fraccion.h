#ifndef FRACCION_H_
#define FRACCION_H_

class Fraccion
{
private:
    int numerador, denominador;
public:
    Fraccion(int=1,int=1);
    void inicializaFraccion(int,int);
    double operaFraccion();
    void printFraccion();
    int simplificaFraccion();
    void imprimeFraccionSimp();
};
#endif

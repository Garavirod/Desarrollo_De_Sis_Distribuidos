#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada
{
private:
    double x, y;
public:
    Coordenada(double = 0, double = 0);
    double obtenerX();
    double obtenerY();
    ~Coordenada();
};
#endif

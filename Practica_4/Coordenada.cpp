#include "Coordenada.h"
#include<iostream>
using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){ }
double Coordenada::obtenerX(){return this->x;}
double Coordenada::obtenerY(){return this->y;}
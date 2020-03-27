#include "Coordenada.h"
#include<iostream>
#include<cmath>
using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){ }

double Coordenada::obtenerX(){
    // return (this->x * cos(this->y * M_PI / 180));
    return this->x;
}
double Coordenada::obtenerY(){    
	// return this->x * sin(this->y * M_PI / 180);
    return this->y;
}

double Coordenada::getMagnitud(){
    return sqrt(pow(this->x,2)+pow(this->y,2));
}
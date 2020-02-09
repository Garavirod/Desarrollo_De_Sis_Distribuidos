#include "Fraccion.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion(int n, int d){
    this->numerador=n;
    this->denominador=d;
}

void Fraccion::inicializaFraccion(int n, int d){
    this->denominador=d;
    this->numerador=n;
}

double Fraccion::operaFraccion(){
    return this->numerador/this->denominador;
}

void Fraccion::printFraccion(){
    cout<<this->numerador<<"/"<<this->denominador<<endl;
}

int Fraccion::simplificaFraccion(){
    int b = numerador, t;
	int a = denominador;
	while(b){
       t = b;
       b = a % b;
       a = t;
    }
    return a;
}

void Fraccion::imprimeFraccionSimp(){
    cout<<(this->numerador / Fraccion::simplificaFraccion()) << "/" << (this->denominador / Fraccion::simplificaFraccion());
}


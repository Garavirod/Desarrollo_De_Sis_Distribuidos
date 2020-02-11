#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include<iostream>
#include<vector>
using namespace std;


PoligonoIrreg::PoligonoIrreg(){}

void PoligonoIrreg::anadeVertice(Coordenada c){
    this->vc.push_back(c);
}

void PoligonoIrreg::imprimeVertice(){
    for(int i=0; i<this->vc.size(); i++)
        cout<<"x = "<<this->vc[i].obtenerX()<<" y = "<<this->vc[i].obtenerY()<<endl;
}

void PoligonoIrreg::anadeVerticesReserve(int cv){
    this->vc.reserve(cv);
	for (int i = 0; i < cv; i++)
	{
		this->vc[i] = Coordenada(rand() % 100 / 10.0, rand() % 100 / 10.0);
	}
	cuentaVertices += cv;
}
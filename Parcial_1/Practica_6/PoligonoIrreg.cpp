#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include<iostream>
#include<vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;


PoligonoIrreg::PoligonoIrreg(){}

void PoligonoIrreg::anadeVertice(Coordenada c){
    this->vc.push_back(c);
}

void PoligonoIrreg::imprimeVertice(){
vector<Coordenada>::iterator i;
	for(i=this->vc.begin(); i!=this->vc.end(); i++){
		Coordenada c = *i;
		cout<<"x = "<<c.obtenerX()<<" y = "<<c.obtenerY()<<" magnitud = "<<c.getMagnitud()<<endl;
	}        
}

void PoligonoIrreg::anadeVerticesReserve(int cv){
    this->vc.reserve(cv);
	for (int i = 0; i < cv; i++)
		this->vc[i] = Coordenada(rand() % (101-1), rand() % (101-1));

}

void PoligonoIrreg::anadeVerticesPush(int cv){
	srand48(time(NULL));
	for (int i = 0; i < cv; i++){		
		double r1 = drand48() * (100-300) + 100;
		double r2 = drand48() * (100-300) + 100;
		cout<<fixed<<setprecision(3)<<endl;
		this->vc.push_back(Coordenada(r1,r2));
	}
}

bool comparaMagnitud(Coordenada a, Coordenada b){
	return a.getMagnitud() < b.getMagnitud();
}

void PoligonoIrreg::ordenaA(){
	sort(this->vc.begin(),this->vc.end(),comparaMagnitud);
}
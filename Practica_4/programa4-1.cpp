#include "Rectangulo.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
   	// Rectangulo rectangulo1(Coordenada(3.6055,56.3099), Coordenada(5.0990,11.3099));
    Rectangulo rectangulo1(Coordenada(2,3),Coordenada(5,1));
	double ancho, alto; 
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n"; 
	rectangulo1.imprimeEsq();
	cout << "El área del rectángulo es = " << rectangulo1.obtenArea() << endl;
	return 0;
}

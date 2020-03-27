#include "Solicitud.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char*argv[]) {

	char arreglo[4000] = "23+70\0";
	char *ip;
	int puerto;
	int operacion = 1;


	ip = argv[1];
	puerto = atoi(argv[2]);
	Solicitud cliente;
	printf("%s\n", cliente.doOperation(ip, puerto, operacion, arreglo));

	return 0;
}

#include <iostream>
#include <stdlib.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;

int main(int argc, char*argv[]) {

	int puerto = 7200;
	SocketDatagrama servidor(puerto);
	SocketDatagrama cliente(puerto);

	// PAQUETE A MANDAR
	char mensajeCliente[50] = "HOLA SOY ELE CLIENT";
	char dir_ip[18] = "127.0.0.1";
	PaqueteDatagrama datagramaClient((char *)&mensajeCliente, sizeof(mensajeCliente),(char *)dir_ip,puerto);

	// PAQUETE A RECIBIR
	char mensajeServer[50]; //Tiene esta long sus mensaje	
	PaqueteDatagrama datagramaServer(sizeof(mensajeServer));

	cliente.envia(datagramaClient);
	cliente.recibe(datagramaServer);
	
	return 0;
}
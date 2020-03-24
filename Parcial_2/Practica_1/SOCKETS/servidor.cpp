#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int puerto = 7200;
	SocketDatagrama servidor(puerto);
	SocketDatagrama cliente(puerto);

	// PAQUETE A MANDAR
	char mensajeServidor[50] = "Este es un mensaje del servidor";
	char dir_ip[18] = "127.0.0.1";
	PaqueteDatagrama datagramaServer((char *)&mensajeServidor, sizeof(mensajeServidor),(char *)dir_ip,puerto);

	// PAQUETE A RECIBIR
	char mensajeCliente[40]; //Tiene esta long sus mensaje	
	PaqueteDatagrama datagramaClient(sizeof(mensajeCliente));


	while(true){
		servidor.recibe(datagramaClient);
		servidor.envia(datagramaServer);
	}
	
	
	return 0;
}
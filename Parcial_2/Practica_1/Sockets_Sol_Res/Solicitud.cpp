#include "SocketDatagrama.h"
#include "Solicitud.h"
#include "Mensaje.h"
#include <string.h>

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char* ip, int puerto, int operationId, int* arguments) {
	struct mensaje msj;
	msj.messageType = 0;
	msj.requestId = id;
	id++;
	memcpy(msj.ip, ip, 16);
	msj.puerto = puerto;
	msj.operationId = operationId;

	cout << "Id operacion: " << msj.operationId << endl;

	cout << "ip: " << msj.ip << endl;
	memcpy(msj.arguments, arguments, 100);
	cout << "puerto: " << msj.puerto << endl;
	cout << "argumentos: " << msj.arguments[1] << endl;

	//SocketDatagrama socket(puerto);
	PaqueteDatagrama paq((char*) &msj, sizeof(msj), ip, puerto);
	int cont=0;
	while (cont<5)
	{
		cont++;
		socketlocal->envia(&paq);
		PaqueteDatagrama paq1(sizeof(msj));
		socketlocal->recibe(&paq1);
		cout<<"Contador >: "<<cont<<endl;

		char* resultado;
		resultado = paq1.obtieneDatos();
		int r;
		memcpy(&r,resultado,sizeof(resultado));
		cout << "Suma en el servidor >: " << r << endl;
		return resultado;
	}
}

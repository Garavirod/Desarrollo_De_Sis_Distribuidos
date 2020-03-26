#include "SocketDatagrama.h"
#include "Solicitud.h"
#include "Mensaje.h"
#include <string.h>

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char* ip, int puerto, int operationId, char* arguments) {
	struct mensaje msj;
	msj.messageType = 0;
	msj.requestId = id;
	id++;
	memcpy(msj.ip, ip, 16);
	msj.puerto = puerto;
	msj.operationId = operationId;
	//cout << "numero: " << operationId << endl;
	//cout << "Id operacion: " << msj.operationId << endl;
	//cout << "ip: " << IP << endl;
	//cout << "ip: " << msj.IP << endl;
	memcpy(msj.arguments, arguments, 100);
	//cout << "puerto: " << puerto << endl;
	//cout << "puerto: " << msj.puerto << endl;
	cout << "argumentos: " << arguments << endl;
	//cout << "argumentos: " << msj.arguments << endl;

    //Creasmo un datagrama de 'envio'
	PaqueteDatagrama datagramaEnvio((char*) &msj, sizeof(msj), ip, puerto);
	socketlocal->envia(&datagramaEnvio);

    //Creamos un datagrama de 'recibo'
	PaqueteDatagrama datagramaRecibo(sizeof(msj));
	socketlocal->recibe(&datagramaRecibo);

	char* resultado;
	resultado = datagramaRecibo.obtieneDatos();
	cout << "Suma realizada: " << resultado << endl;
	return resultado;
}

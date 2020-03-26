#include "SocketDatagrama.h"
#include "Respuesta.h"
#include<iostream>
#include<string.h>
using namespace std;


Respuesta::Respuesta(int puerto) {
	socketlocal = new SocketDatagrama(puerto);

}
struct mensaje* Respuesta::getRequest() {

    // Creamos un datagrama de 'recibo'
	PaqueteDatagrama datagramaRecibo(sizeof(mensaje));
	socketlocal->recibe(&datagramaRecibo);
    //Pasamos los datos    
	this->palabras = (struct mensaje*) datagramaRecibo.obtieneDatos();
	cout << "La IP: " << this->palabras->ip << endl;
	this->palabras->puerto = datagramaRecibo.obtienePuerto();
	memcpy(this->palabras->ip,datagramaRecibo.obtieneDireccion(),16);
	cout << "Puerto: " << this->palabras->puerto << endl;
	return this->palabras;
}

void Respuesta::sendReply(char * respuesta, char * ipCliente, int puertoCliente) {

	struct mensaje *m1;
	m1 = (struct mensaje *) respuesta;
	cout << "ip Cliente: " << ipCliente << endl;
	cout << "puerto Cliente: " << puertoCliente << endl;
	PaqueteDatagrama datagramaEnvio((char*) m1, 100, ipCliente, puertoCliente);
	socketlocal->envia(&datagramaEnvio);
}

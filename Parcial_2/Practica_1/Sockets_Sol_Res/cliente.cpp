#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include "Solicitud.h"

using namespace std;

int main(int argc, char *argv[])
{

	if(argc < 4){
		cout<<"MODO DE USO :"<<endl<<"./cliente <ip> <puerto> <numero1> <numero2>"<<endl;
		return -1;

	}
	
	//Creamos una conexion el puerto 7000
	SocketDatagrama socket = SocketDatagrama(7000);
	char *response;
	char* ip = argv[1];
	int puerto = (int)*argv[2];
	char numeros[2];
	numeros[0] = (char)*argv[3];
	numeros[1] = (char)*argv[4];

	Solicitud cli;
	response = cli.doOperation(ip,puerto,1,numeros);
	cout<<response<<endl;
	
	// //Creamos un paquete datagram de 'envio'
	// PaqueteDatagrama datagrama = PaqueteDatagrama((char *) numeros, 2 * sizeof(int),ip, 7001);
	// socket.envia(&datagrama); //Se manda el datagrama al servidor

	// //Se crea un paquete datagram de 'recibo'
	// PaqueteDatagrama databack =  PaqueteDatagrama(sizeof(int));
	// socket.recibe(&databack); //Se recibe el datagrama de recibo

	// int * ans = (int*)databack.obtieneDatos(); //Obtenemso lo datos del datagrama de recibo
	// cout<< " Dirección " << datagrama.obtieneDireccion() << " puerto: " << datagrama.obtienePuerto() << endl;
	// cout << "Respuesta="<<(*ans) << endl;
	return 0;
}
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include "Solicitud.h"
#include<string.h>
using namespace std;

int main(int argc, char *argv[])
{

	if(argc < 4){
		cout<<"MODO DE USO :"<<endl<<"./cliente <ip> <puerto> <numero1> <numero2>"<<endl;
		return -1;

	}
	
	char *response;
	char* ip = argv[1];
	int puerto = atoi(argv[2]);
	int numeros[2];
	numeros[0] = atoi(argv[3]);
	numeros[1] = atoi(argv[4]);
	Solicitud cli;
	response = cli.doOperation(ip,puerto,1,(int*)numeros);
	cout<<response<<endl;
	return 0;
}
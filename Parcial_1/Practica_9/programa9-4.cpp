//g++ -std=c++11 E4.cpp -o E4 -lpthread

#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include <cmath> 
#include <time.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#define numeroElementos 100000000
using namespace std;

char buffer[97576 * 4];

string generteWord()
{
    string t = "";
    char w1 = (char)(65 + rand() % (91 - 65));
    char w2 = (char)(65 + rand() % (91 - 65));
    char w3 = (char)(65 + rand() % (91 - 65));
    t += w1;
    t += w2;
    t += w3;
    return t;
}

void usoRam() {
	printf("Hilo %ld | Uso de RAM\n", this_thread::get_id());
	//cout << "Uso de RAM" << endl;
    int *arreglo, i;
	arreglo = new int[numeroElementos];
	for(i = 0; i < numeroElementos; i++)
		arreglo[i] = 0;
	
	for(i = 0; i < 645000000; i++) {
		arreglo[rand() % numeroElementos] = rand();
	}
}

void usoRam2() {
	printf("Hilo %ld | Uso de RAM 2\n", this_thread::get_id());
	//cout << "Uso de RAM" << endl;
    int *arreglo, i;
	arreglo = new int[numeroElementos];
	for(i = 0; i < numeroElementos; i++)
		arreglo[i] = 0;
	
	for(i = 0; i < 645000000; i++) {
		arreglo[rand() % numeroElementos] = rand();
	}
}

void usoCPU() {
	printf("Hilo %ld | Uso de CPU\n", this_thread::get_id());
	//cout << "Uso de CPU" << endl;
    double max = 121000000.0;
    double i = 0.0;
	double seno1 = 0.0;
	double cos1 = 0.0;
	double tan1 = 0.0;
	double log1 = 0.0;
	double raiz1 = 0.0;
	while(i < max) {
		seno1 += sin(i);
		cos1 += cos(i);
		tan1 += tan(i);
		log1 += log(i);
		raiz1 += sqrt(i);
		i += 1;
	}
}

void usoDiscoDuro() {
	printf("Hilo %ld | Uso de DD 1\n", this_thread::get_id());
	int n = 1757600;

	int destino;
	string linea = "";
	char archivo[8] = {'D','D','1','.','t','x','t'};
	
    string cad = "";
        for (int i = 0; i < n - 1; i++)
        {
            cad += generteWord();
            cad += " ";
        }
    cad += generteWord();

	
	if((destino = open(archivo, O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
    {
		perror(archivo);
		exit(-1);
	}

	int i = 0;
	char candenota[cad.size()+1];
	strcpy(candenota,cad.c_str());

	while (i < 7030400) 
    {
		write(destino, candenota, sizeof(char));
		memset(candenota, candenota[i], sizeof(char));
		i++;
    }

	fsync(destino);
	close(destino);
}

void usoDiscoDuro2() {
	printf("Hilo %ld | Uso de DD 2\n", this_thread::get_id());
	int n = 1757600;

	int destino;
	string linea = "";

	char archivo[8] = {'D','D','2','.','t','x','t'};
	
    for (int i = 0; i < n; i++)
    	linea.insert(4 * i, generteWord());

	
	if((destino = open(archivo, O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
    {
		perror(archivo);
		exit(-1);
	}

	int i = 0;
	char candenota[7030401];
	strcpy(candenota,linea.c_str());

	while (i < 7030400) 
    {
		write(destino, candenota, sizeof(char));
		memset(candenota, candenota[i], sizeof(char));
		i++;
    }

	fsync(destino);
	close(destino);
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

	if(argc != 2){
		cout << "Forma de uso: " << argv[0] <<" opcion\n";
		exit(0);
	}

	int opcion = atoi(argv[1]);
	cout << "Inciso " << opcion << ")"<< endl;

	switch(opcion) {
		case 1: 
		{
			//DD 1 y 2
			thread th1(usoDiscoDuro), th2(usoDiscoDuro2);
			th1.join();
		    th2.join();
		}
		break;
		case 2: 
		{
			//RAM y RAM
			thread th3(usoRam), th4(usoRam2);
			th3.join();
		    th4.join();
		}
	    break;
		case 3: 
		{
			//CPU y CPU
			thread th5(usoCPU), th6(usoCPU);
			th5.join();
		    th6.join();
		}
	    break;
		case 4: 
		{
			//DD y CPU
			thread th7(usoDiscoDuro), th8(usoCPU);
			th7.join();
		    th8.join();
		}
	    break;
		case 5: 
		{
			//DD y RAM
			thread th9(usoDiscoDuro), th10(usoRam);
			th9.join();
		    th10.join();
		}
	    break;
		case 6: 
		{
			//CPU y RAM
			thread th11(usoCPU), th12(usoRam);
			th11.join();
		    th12.join();
		}
		break;
		case 7: 
		{
			//CPU, DD y RAM
			thread th13(usoCPU), th14(usoDiscoDuro), th15(usoRam);
			th13.join();
		    th14.join();
		    th15.join();
		}
	    break;
		default:
			cout << "Error" << endl;
		break;
	}
	exit(0);
}
#include<iostream>
#include <string>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;
#define N 1757600

string generteWord(){
    string t = "";
    char w1 = (char)(65 + rand() % (91 - 65));
    char w2 = (char)(65 + rand() % (91 - 65));
    char w3 = (char)(65 + rand() % (91 - 65));
    t += w1;
    t += w2;
    t += w3;
    return t; 
}

int main(int argc, char const *argv[])
{
    int destino;
    srand(time(NULL));
    string cadenota = "";

    if (argc != 2)
    {
        cout << "Forma de uso: " << argv[0] << " nombre_del_archivo\n";
        exit(0);
    }

    for(int i =0; i<N-1; i++){ 
        cadenota += generteWord();
        cadenota += " "; 
    }
    cadenota += generteWord();
    
    char buffer[cadenota.size()+1];
    strcpy(buffer, cadenota.c_str());
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if ((destino = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    {
        perror(argv[1]);
        exit(-1);
    }
    write(destino, buffer, strlen(buffer));
    fsync(destino);
    close(destino);

    cout<<"Tamaño del archivo >: "<<sizeof(buffer)<<endl;
    
    return 0;
}

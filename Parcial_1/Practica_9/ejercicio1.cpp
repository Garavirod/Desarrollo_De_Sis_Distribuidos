#include <string>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

using namespace std;

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



#define N 1757600

int main(int argc, char const *argv[])
{

    FILE *fp;

    if (argc != 3)
    {
        cout << "Forma de uso: " << argv[0] << " nombre_del_archivo  opcion_ejecucion (A B C)\n";
        exit(0);
    }

    if (atoi(argv[2]) == 1)
    {
        string cadenota = "";
        for (int i = 0; i < N - 1; i++)
        {
            cadenota += generteWord();
            cadenota += " ";
        }
        cadenota += generteWord();
        // GUARDAMOS DE BYTE POR BYTE
        fp = fopen(argv[1], "a+t"); //parámetro para escritura al final y para file tipo texto
        for (int i = 0; i < cadenota.length(); i++)
            fputc(cadenota[i], fp);
        fclose(fp);
    }
    else if (atoi(argv[2]) == 2)
    {
        // GUARDAMOS TOKEN POR TOKEN
        fp = fopen(argv[1], "a+t");
        for (int i = 0; i < N - 1; i++)
        {
            string token = generteWord();
            char c[token.size() + 1];
            strcpy(c, token.c_str());
            fputs(c, fp);
            fputs(" ", fp);            
        }
        fputs(" ", fp);
        fclose(fp);
    }
    else if (atoi(argv[2]) == 3)
    {
        char buffer[BUFSIZ];
        fp = fopen(argv[1], "w");
        setbuf(fp, buffer);
        for (int i = 0; i < N; i++)
        {
            string token = generteWord();
            char c[token.size() + 1];
            strcpy(c, token.c_str());
            fputs(c, fp);
            fputs(" ", fp);
        }
        fflush(fp);
    }

    /*
    
        fflush()funciona FILE*, simplemente vacía los búferes internos FILE*de su aplicación al sistema operativo.

        fsync funciona en un nivel inferior, le dice al sistema operativo que vacíe sus memorias intermedias a los medios físicos.

        Los sistemas operativos almacenan en caché los datos que escribe en un archivo. 
        Si el sistema operativo aplicara cada escritura para golpear la unidad, 
       las cosas serían muy lentas. 
       fsync(entre otras cosas) le permite controlar cuándo los datos deben llegar al disco.
    
    */
    return 0;
}

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
        
    }
    return 0;
}

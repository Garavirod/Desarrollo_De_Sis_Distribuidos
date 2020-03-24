#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include "renidmiento.h"
using namespace std;

#define N 50000000

int main(int argc, char const *argv[])
{
    char *cadenota = (char*) malloc(sizeof(char)*1);
    string stringVariable;
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        // CONVERTIMOS EL STRING A UN ARRAY DE CHAR
        string stringG = generteWord();
        stringG += " ";
        char auxString[stringG.size() + 1];
        strcpy(auxString, stringG.c_str());

        // CONCATENAMOS DOS ARRAYS DE CHAR
        cadenota = (char*) realloc(cadenota, (strlen(cadenota) + strlen(auxString) + 1) * sizeof(char));
        memcpy(cadenota + strlen(cadenota), auxString, strlen(auxString) +1);
    }
    
    cout<<"Número de ocurrencias >: "<<getOcurrencias(cadenota)<<endl;
    return 0;
}

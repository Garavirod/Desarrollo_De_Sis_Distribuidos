#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char * cadenota = NULL;
    char * cadena = NULL;
    char * cad = NULL;
    int po = 4;
    char ipn [4] = "IPN";
    long i = 0, j = 0, cont = 0;
    char * aux;
    long n = 2000;
    srand(time(NULL));
    FILE *fp;
    fp = fopen ( "fichero1.txt", "w" );
    
    cadenota = malloc(sizeof(char) * 5);
    cadena = malloc(sizeof(char) * 5);
    cad = malloc(sizeof(char) * 5);

    for(i; i < n; i++)
    {
        j = 0;
        for(j; j < 3; j++)
        {
            int num = rand() % (90 - 65 + 1) + 65;
            aux = (char)  num;
            cadena [j] = (char)aux;
        }

        cadena [j] = (char) 32;
        cadenota =(char*)realloc(cadenota, po+1);
        strcat(cadenota, cadena);
        //memcpy(cadenota, cadena, 4);
        strcpy(cadena, "");

        po = po + 4;
    }
    //puts(cadenota);
    fputs(cadenota,fp);

    long tam = strlen(cadenota);

    //printf("\n%li",tam);
    //cont=1;
    for (i = 0; i < tam; i++){
        if(cadenota[i++] == ipn[0])
        {
            if(cadenota[i++] == ipn[1])
            {
                if(cadenota[i++] == ipn[2])
                    cont=cont+1;
            }
            else
                i=i+1;
        }
        else
            i=i+2;
    }

    //printf("\ni = %li, tam = %li",i,tam);
    //puts(cadenota);
    printf("\nEl numero de coincidencias con la cadena %c%c%c: \t%li\n",ipn[0], ipn[1], ipn[2], cont);
    free(cadenota);
    fclose ( fp );
}
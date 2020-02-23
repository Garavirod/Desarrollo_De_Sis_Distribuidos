#include <iostream>
#include <cstring>
#include <string>
#include <string.h>

using namespace std;

/*
    retorna una palabra de tres letras aleatorias mayusculas
 */
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

/*
    Retorna el número de ocurrencias de una cadena con el template string
*/
int getOcurrencias(string &cadenota)
{
    int counter = 0;
    size_t idxOcurr = cadenota.find("IPN");
    while (idxOcurr != std::string::npos){
        counter++;
        idxOcurr = cadenota.find("IPN", idxOcurr + 1, 2);
    }
    return counter;
}

/*
    Retorna el número de ocurrencias de una cadena 
*/

int getOcurrencias( char *cadena )
{
   char *tmp = cadena;
   char *pdest;
   int counter = 0, pos;
   char IPN[] = "IPN";
   int longitud = strlen(IPN);
   while(1)
   {
      pdest = strstr( tmp, IPN );
      if( !pdest ) break;
      pos = pdest - tmp;
      tmp += pos + longitud;
      counter++;
   }
   return counter;
}

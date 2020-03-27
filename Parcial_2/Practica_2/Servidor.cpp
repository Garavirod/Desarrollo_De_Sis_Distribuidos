#include <cstdlib>
#include <string>
#include <vector>
#include "Respuesta.h"
#include <sstream>

using namespace std;

void split(const string &s, char c, vector<string> &v)
{
  string::size_type i = 0;
  string::size_type j = s.find(c);

  while (j != string::npos)
  {
    v.push_back(s.substr(i, j - i));
    i = ++j;
    j = s.find(c, j);

    if (j == string::npos)
      v.push_back(s.substr(i, s.length()));
  }
}

int main(int argc, char const *argv[])
{

  if (argc < 2)
  {
    cout << "Modo de uso" << endl
         << "./Servidor <puerto>" << endl;
    return -1;
  }

  Respuesta respuesta((int)*(argv[1]));
  while (1)
  {
    struct mensaje msj; //Mensaje de recibo
    struct mensaje m1;  //Menaje de envio

    cout << "\nEsperando conexion : " << endl;
    memcpy(&msj, respuesta.getRequest(), sizeof(struct mensaje));

    // cout << "Estos son loa argumentos antes de la operacion: " << msj.arguments << endl;
    // cout << "id: " << msj.operationId << endl;
    // cout<< "IP: " <<msj.IP<<endl;

    // cout << "Id encontrado :  1" << endl;
    // cout << "Los argumentos son : " << msj.arguments << endl;

    memcpy(m1.arguments, msj.arguments, strlen(msj.arguments));
    string cad = m1.arguments;
    cout<<"MI CADENA >: "<<cad<<endl;
    vector<string> v;
    split(cad, '+', v);
    for (int i = 0; i < v.size(); ++i)
    {
      cout << v[i] << '\n';
    }
    int a = stoi(v[0]) + stoi(v[1]);
    cout << a << endl;
    stringstream p;
    p << a;
    string aux = p.str();
    memcpy(m1.arguments, aux.c_str(), strlen(m1.arguments));

    m1.messageType = 1;
    memcpy(m1.IP, msj.IP, 16); //------------------
    m1.puerto = msj.puerto;
    m1.requestId = msj.requestId;
    respuesta.sendReply((char *)m1.arguments, m1.IP, msj.puerto);
    // cout << "Fin del servicio" << endl;
  }

  return 0;
}

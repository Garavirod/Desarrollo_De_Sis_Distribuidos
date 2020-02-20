#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n = 100000;
    int c = 0;
    srand(time(NULL));
    int random; 
    string cadenota, cadenita;
    for(int i = 0; i < n; i++){
        for( int j = 0;j < 3 ; j++){
            random = 65 + rand() % (91 - 65);
            cadenita  += (char) random;
        }      
        cadenota += cadenita + " ";  
        if(cadenita.compare("IPN")==0)
            c++;
        cadenita = "";
    }
    cout << cadenota<< endl;
    cout << c << endl;

    return 0;
}

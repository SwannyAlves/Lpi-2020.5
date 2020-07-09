#include <iostream>
#include "carro.hpp"

using namespace std;

int main(){

    Carro c;
    c.tipo = "sedan";
    c.numPortas = 4;
    c.placa = "xyw-7894";

    cout << "tipo de carro: " << c.tipo << endl;
    cout << "quantidade de portas: "<< c.numPortas << endl;
    cout << "placa do carro: " << c.placa << endl;
    c.acelera(50);
    cout << "a velocidade atual é: " << c.velocidade << "km/h"<<endl;
    c.freia(20);
    cout << "a velocidade atual é: " << c.velocidade << "km/h" << endl;  

    return 0;
}
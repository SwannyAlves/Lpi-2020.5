#include "carro.hpp"


Carro::Carro(string tipo){
    this->tipo = tipo;
    this->qtdCarros += qtdCarros;
}

Carro::Carro(){
    this->qtdCarros += qtdCarros;
}

void Carro::acelera(int velocidade){ // tipo do método - nome da classe - o método - o parâmetro de entrada
    this -> velocidade += velocidade; // 'this ->' = esta se referindo ao atributo velocidade de carro.hpp 
}
void Carro::freia(int velocidade){         

    this -> velocidade -= velocidade;
}

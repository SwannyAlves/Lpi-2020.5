#include "Conta.hpp"


    Conta::Conta(){
        this -> qtdContas += 1;
    }
    Conta::Conta(Cliente& nomeCliente)]{
        this -> qtdContas += 1;
    }

    Conta::~Conta(){}

    void Conta::saca(double valor){
        this -> saldo -= valor;
    }

    void Conta::deposita(double valor){
        this -> saldo += valor;
    }

    void Conta::transfere(double valor, Conta &favorecido){
        this -> saldo -= valor;
       favorecido.saldo += valor;
    }


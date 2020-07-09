#include <string>

#include "Cliente.hpp"
#include "Agencia.hpp"

class Conta {

    public:

 

    Cliente:: Cliente nomeCliente;
    int numeroDaConta;
    Agencia numeroDaAgencia;
    double saldo;

    Conta();
    Conta(Cliente::Cliente& nomeCliente);
    ~Conta();

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &favorecido);

    int qtdContas;
};
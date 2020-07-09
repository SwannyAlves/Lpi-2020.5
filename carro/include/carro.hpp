#include <string>

using namespace std;


class Carro{

    public:
        string tipo;
        string placa;
        int numPortas;
        int velocidade;

        Carro(string tipo);
        Carro();

        void acelera(int velocidade);
        void freia(int freia);
        int qtdCarros;
};


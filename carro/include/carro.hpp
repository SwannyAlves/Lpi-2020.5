#include <string>

using namespace std;


class Carro{

    public:
        string tipo;
        string placa;
        int numPortas;
        int velocidade;

        void acelera(int velocidade);
        void freia(int freia);

};

